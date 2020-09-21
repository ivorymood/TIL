listdata = list(range(5))
retl = reversed(listdata)
print('원본 리스트', end='')
print(listdata)
print('역순 리스트', end='')
print(list(retl))
# list_reverseiterator object
print(retl)

ret2 = listdata[::-1]
print('슬라이싱 이용', end='')
print(ret2)