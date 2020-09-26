# 파일 처리 후 자동으로 파일을 닫아줌
with open('mydata.txt', 'r') as f:
    for line_num, line in enumerate(f.readlines()):
        print('%d %s' %(line_num + 1, line), end='')