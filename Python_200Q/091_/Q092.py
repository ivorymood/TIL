txt = 'A lot of things occur each day, every day'

# find : 문자열에서 단어가 최초로 나타나는 인덱스 찾기
word_count1 = txt.find('e')
word_count2 = txt.find('day')
word_count3 = txt.find('day', 30)
print(word_count1) # 22
print(word_count2) # 27
print(word_count3) # 38 (30번 인덱스 이후부터 day 문자열을 찾기 시작)
