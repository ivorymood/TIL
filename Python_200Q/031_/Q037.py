tuple1 = (1, 2, 3, 4, 5)
tuple2 = ('a', 'b', 'c')
tuple3 = (1, 'a', 'abc', [1, 2, 3, 4, 5], ['a', 'b', 'c'])
# 튜플의 값은 변경할 수 없다
#tuple1[0] = 6

def myfunc():
    print("안녕하세요")

tuple4 = (1, 2, myfunc)
tuple4[2]()