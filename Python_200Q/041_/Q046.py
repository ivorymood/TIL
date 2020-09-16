from time import sleep
from mypackage import mylib
from mypackage.mylib import reverse

print('1초간 휴식 시작!')
sleep(1)
print('1초 휴식 끝!')
print(mylib.add_txt('나는', '파이썬이다'))
print(reverse(1, 2, 3))
