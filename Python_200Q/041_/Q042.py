# 리턴값이 여러개인 경우, 튜플로 리턴값을 만들어 리턴
def reverse(x, y, z):
    return z, y, x

ret = reverse(1, 2, 3)
print(ret)

r1, r2, r3 = reverse('a', 'b', 'c')
print(r1)
print(r2)
print(r3)