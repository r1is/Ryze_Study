## 前言

在使用`docker-compose`编排`typecho`个人博客前，已经使用过宝塔`LNMP`环境、[单个docker镜像](https://hub.docker.com/r/yangxuan8282/typecho "单个docker镜像")来搭建，前者容易上手几乎不用怎么操心，后者由于是使用现成的`image`，给博客添加`https`证书不是太方便。在网上搜寻很多资料后，有了使用`docker-compose`编排`ngnix`、`php`、`mysql`容器搭建`typecho`博客的思路。

## 准备工作

本文通过让` Nginx`、`PHP`、`MySQL `各自运行在宿主机（vps或云主机）的不同容器中，并使用 `Docker Compose` 对各个容器进行编排管理，因此需要现在宿主机上安装 `Docker `和 `Docker Compose`。
由于笔者使用的`centos`服务器，故本节只介绍如何在`centos`系统上安装`docker`和`docker-compose`。

### 安装`docker`
#### 设置`docker`仓库
安装所需的软件包。`yum-utils` 提供了` yum-config-manager`，并且 `device mapper` 存储驱动程序需要 `device-mapper-persistent-data `和` lvm2`。
**设置仓库**
```shell
sudo yum install -y yum-utils \
  device-mapper-persistent-data \
  lvm2
```
**使用以下命令来设置稳定的仓库**
```shell
sudo yum-config-manager \
    --add-repo \
    https://download.docker.com/linux/centos/docker-ce.repo
```
#### 安装 `Docker Engine-Community`
安装最新版本的 Docker Engine-Community 和 containerd
```shell
sudo yum install docker-ce docker-ce-cli containerd.io
```
#### 启动 `Docker`
```shell
$ sudo systemctl start docker
```
#### 验证是否正确安装了`docker`
```shell
$ sudo docker run hello-world
```
#### 配置镜像加速器
修改`daemon`配置文件`/etc/docker/daemon.json`来使用加速器
```shell
sudo mkdir -p /etc/docker
sudo tee /etc/docker/daemon.json <<-'EOF'
{
  "registry-mirrors": ["https://uz1zrdnz.mirror.aliyuncs.com"]
}
EOF
sudo systemctl daemon-reload
sudo systemctl restart docker
```
### 安装` docker-compose`

```shell
$ sudo curl -L "https://github.com/docker/compose/releases/download/1.25.5/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
```

将可执行权限应用于二进制文件：

```shell
$ sudo chmod +x /usr/local/bin/docker-compose
```

创建软链：

```shell
$ sudo ln -s /usr/local/bin/docker-compose /usr/bin/docker-compose
```

测试是否安装成功：

```shell
$ docker-compose --version
docker-compose version 1.25.5, build 8a1c60f6
```

### 拉取镜像

#### `Nginx`镜像

```shell
docker pull anguiao/nginx-brotli
```

anguiao/nginx-brotli [ 镜像传送门](https://hub.docker.com/r/anguiao/nginx-brotli)

#### `php `镜像

```shell
docker pull anguiao/php-fpm
```

在`php`镜像的基础上已经导入了`mysql `[传送门](https://hub.docker.com/r/anguiao/php-fpm)

## 主要配置与安装

### 文件结构

```shell
├── conf                           //配置文件
│   └── nginx
│       ├── nginx.conf						 //nginx全局配置文件
│       ├── ryzezr.com.conf				//nginx站点配置文件
├── db											   //建站后的数据库目录
├── docker-compose.yml					//docker-compose配置文件
├── log											   //日志目录
├── ssl											    //SSL证书目录，https证书可以去宝塔免费申请
│   ├── dhparam.pem					     //生成的公钥
│   ├── fullchain.cer					     //你申请的证书
│   └── www.ryzezr.com.key		    //发给你的私钥
```

### `Nginx`配置

#### 全局配置

全局配置文件，参考自[anguiao的博客](https://blog.anguiao.com/archives/build-blog-with-docker.html)

```shell
user  www-data www-data;
worker_processes  1;

error_log  /var/log/nginx/error.log warn;
pid        /var/run/nginx.pid;

events {
    worker_connections  1024;
}

http {
    include            mime.types;
    default_type       application/octet-stream;

    log_format  main  '$remote_addr - $remote_user [$time_local] "$request" '
                      '$status $body_bytes_sent "$http_referer" '
                      '"$http_user_agent" "$http_x_forwarded_for"';

    charset            UTF-8;

    sendfile           on;
    tcp_nopush         on;
    tcp_nodelay        on;

    keepalive_timeout  60;

    gzip               on;
    gzip_vary          on;

    gzip_comp_level    6;
    gzip_buffers       16 8k;

    gzip_min_length    1000;
    gzip_proxied       any;
    gzip_disable       "msie6";

    gzip_http_version  1.0;

    gzip_types         text/plain text/css application/json application/x-javascript text/xml application/xml application/xml+rss text/javascript application/javascript image/svg+xml;

    brotli             on;
    brotli_comp_level  6;
    brotli_types       text/plain text/css application/json application/x-javascript text/xml application/xml application/xml+rss text/javascript application/javascript image/svg+xml;

    include            /etc/nginx/conf.d/*.conf;
}
```

#### 站点配置

在 `Nginx `全局配置文件的最后，包含了 `conf.d` 目录下的配置文件，这使得我们可以将站点的相关配置写在一个独立的配置文件当中。配置文件来自：[Anguiao的博客](https://blog.anguiao.com/archives/build-blog-with-docker.html)

```shell
server {
    listen 80;
    listen [::]:80;
    server_name test.anguiao.com; //更换为你的站点域名
		//这里是，http重定向为https
    return 301 https://$host$request_uri;
}

server {
    listen 443 ssl http2 fastopen=3 reuseport;
    listen [::]:443 ssl http2 fastopen=3 reuseport;
    server_name test.anguiao.com;   //更换为你的站点域名
    index index.php index.html index.htm index.nginx-debian.html;
    root /var/www/html;

    access_log /var/log/nginx/access.log;
    error_log /var/log/nginx/error.log warn;

    ssl_certificate /var/www/ssl/fullchain.cer;    //更换为你的站点证书
    ssl_certificate_key /var/www/ssl/anguiao.com.key; //更换你申请的私钥
    ssl_session_timeout 1d;
    ssl_session_cache shared:SSL:50m;
    ssl_session_tickets off;

    ssl_dhparam /var/www/ssl/dhparam.pem;

    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_ciphers 'ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-CHACHA20-POLY1305:ECDHE-RSA-CHACHA20-POLY1305:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-SHA384:ECDHE-RSA-AES256-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256';
    ssl_prefer_server_ciphers on;

    add_header Strict-Transport-Security max-age=15768000;

    ssl_stapling on;

    ssl_early_data on;

    resolver 114.114.114.114 valid=300s;
    resolver_timeout 10s;
		//这里是typecho伪静态化配置
    if (!-e $request_filename) {
            rewrite ^(.*)$ /index.php$1 last;
    }

    location ~ .*\.php(\/.*)*$ {
            fastcgi_pass fpm:9000;
            fastcgi_index index.php;
            include fastcgi_params;
            fastcgi_param SCRIPT_FILENAME  $document_root$fastcgi_script_name;
    }
}
```

### 编写`docker-compose.yml`

`docker-compose`使用`./`当前路径下的`docker-compose.yml编排以上容器`

```shell
version: '3'
 
 services:
   nginx:
     image: anguiao/nginx-brotli
     container_name: blog_nginx
     ports:
       - 80:80
       - 443:443
     volumes:
       - ./www/:/var/www/html/:rw     //目录映射
       - ./ssl/:/var/www/ssl/:ro      //目录映射
       - ./conf/nginx/nginx.conf:/etc/nginx/nginx.conf:ro   //目录映射
       - ./conf/nginx/test.anguiao.com.conf:/etc/nginx/conf.d/test.anguiao.com.conf:ro   //目录映射
     restart: always
    depends_on:
       - fpm
       - mysql
 
   fpm:
     image: anguiao/php-fpm
     container_name: blog_fpm
     expose:
       - 9000
     volumes:
      - ./www/:/var/www/html/:rw
       - ./log/php-fpm/:/var/log/php-fpm/:rw
     restart: always
 
   mysql:
     image: mysql:5.7
     container_name: blog_db
     expose:
      - 3306
     volumes:
       - ./db:/var/lib/mysql/:rw   //目录映射
     restart: always
     environment:
       - MYSQL_ROOT_PASSWORD=123456  //数据库root密码
       - MYSQL_DATABASE=typecho      //名称
      - MYSQL_USER=typecho
       - MYSQL_PASSWORD=123456       //数据库密码
 ```

### 安装typecho

下载`typecho`,并解压至`www`目录

```shell
wget http://typecho.org/downloads/1.1-17.10.30-release.tar.gz
tar xvf 1.1-17.10.30-release.tar.gz
rm 1.1-17.10.30-release.tar.gz
```

为了让容器获得站点相关文件的写入权限，需要更改相关文件的所有者。通过查看 PHP 镜像的 Dockerfile，得知其 `www-data` 用户的 UID 和 GID 均为 82，因此可以这样设置：

```shell
sudo chown -R 82:82 www
```

至此配置完成，可以启动了：

```shell
docker-compose up -d
```

在浏览器中输入你的站点域名，安装网页提示完成后继安装步骤。

> 需要注意的是，数据库配置中的“数据库地址”应填写`mysql`（与 `docker-compose.yml` 相对应），其他`配置`与`环境变量`保持一致即可
