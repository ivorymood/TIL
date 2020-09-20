# range객체는 리스트가 아님
range1 = range(10)
range2 = range(10, 20)
print(list(range1))
print(list(range2))

ret = 0
for i in range(10):
    ret += (i + 1)
    #print(ret)

for x in range(2, 10):
    print(x)

for x in range(2, 10, 2):
    print(x)
