f1 = lambda x: x * x
f2 = lambda x, y : x + y
args1 = [1, 2, 3, 4, 5]
args2 = [10, 9, 8, 8, 6]

# args의 모든 요소를 f에 대입하여 결과를 얻은 후 map객체로 리턴
ret1 = map(f1, args1)
ret2 = map(f2, args1, args2)
print(list(ret1))
print(list(ret2))