bnum = 0b11110000
bstr = '0b11110000'
onum = 0o360
ostr = '0o360'
hnum = 0xf0
hstr = '0xf0'

# 0b, 0o, 0x가 붙은 숫자는 base를 자동인식
# 문자열로 된 n진수는 두번째 인자에 base를 지정해야 제대로 변환
b1 = int(bnum)
b2 = int(bstr, 2)
o1 = int(onum)
o2 = int(ostr, 8)
h1 = int(hnum)
h2 = int(hstr, 16)

print(b1)
print(b2)
print(o1)
print(o2)
print(h1)
print(h2)