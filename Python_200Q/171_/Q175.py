BUFSIZE = 256*1024
merge_filename = 'ret.exe'
filelist = ['python-3.8.2.exe_' + str(x) for x in range(9)]

with open(merge_filename, 'wb') as f:
    for filename in filelist:
        print('[%s] 합치는 중..' %filename)
        with open(filename, 'rb') as h:
            buf = h.read(BUFSIZE)
            while buf:
                f.write(buf)
                buf = h.read(BUFSIZE)

print('파일 합치기 완료')