f = open('sample.txt', 'r')
# file.read : 오픈한 파일 객체의 모든 내용을 한꺼번에 읽는다
data = f.read()
print(data)
f.close()