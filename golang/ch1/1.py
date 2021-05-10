import hashlib
s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

for i in s:

	for j in s:
		temp = i +j
		for k in s:
			r = ""
			r = temp + k
			a = hashlib.md5(r.encode())
			if a.hexdigest()[0:10] == '2b8819472b':
				print(r,a.hexdigest)


