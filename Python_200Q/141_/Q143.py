# 1KB 단위로 파일 읽고 쓰기
bufsize = 1024
f = open('puppy.jpg', 'rb')
h = open('puppy_copy.jpg', 'wb')

data = f.read(bufsize)
while data:
    h.write(data)
    data = f.read(bufsize)

f.close()
h.close()