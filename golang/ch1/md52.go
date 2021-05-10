package main

import (
    "crypto/md5"
    "encoding/hex"
    "fmt"
 
)

func md5V(str string) string  {
    h := md5.New()
    h.Write([]byte(str))
    return hex.EncodeToString(h.Sum(nil))
}

func main(){
	var st  string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
	for i := 0 ; i < len(st) ;i++ {
		var s string = st[i]
		for j := 0; j < len(st);j++{
		var	ss  string = s + st[j]
			for k := 0; k < len(st);k++{
				var sss string  = ss + st[k]
				
				fmt.Println(sss)
			}
 		}
	}

}