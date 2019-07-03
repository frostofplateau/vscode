# import io
# import sys


# sys.stdout=io.TextIOWrapper(sys.stdout.buffer,encoding="utf-8")
print("你好")


"""
strings可以被编码(encode)成字bytes,bytes也可以解码(decode)成strings。
"""
s1 = "abcdefghijklimnopqrstuvwxyz"
b1 = b'asdfasd'
s2 = s1.encode('utf-8')
b2 = b1.decode('utf-8')
print(b2)
print(s2)
a = "a" or "b"
print(type(a))