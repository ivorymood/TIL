listdata1 = [0, 1, 2, 3, 4]
listdata2 = [True, True, True]
listdata3 = ['', [], (), {}, None, False]
# all : 모든 요소가 참
# any : 한 요소라도 참
print(all(listdata1)) # Flase (0)
print(any(listdata1)) # True
print(all(listdata2)) # True
print(any(listdata2)) # True
print(all(listdata3)) # False ('', [], (), {}, None, Flase)
print(any(listdata3)) # False ('', [], (), {}, None, Flase)