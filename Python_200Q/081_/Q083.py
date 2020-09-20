#파이썬은 모든 문자를 유니코드로 처리
msg = input('임의의 문장을 입력하세요: ')
msglen = len(msg)
print('당신이 입력한 문장의 길이는 <%d>입니다' %msglen)

# encode : 유니코드 형식으로 된 문자열을 바이트 객체로 변환
msglen2 = len('abcde'.encode())
print('당신이 입력한 문장의 길이는 <%d>입니다' %msglen2)

msglen3 = len('안녕하세요'.encode())
print('당신이 입력한 문장의 길이는 <%d>입니다' %msglen3)
