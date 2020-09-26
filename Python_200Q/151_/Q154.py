import shutil
import os

target_folder = 'D:/TIL/Python_200Q/151_/my_dir'
print('[%s] 하위 모든 디렉토리 및 파일들을 삭제합니다.' %target_folder)
for file in os.listdir(target_folder):
    print(file)
k = input('[%s]를 삭제하겠습니까? (y/n)' %target_folder)
if k == 'y':
    try:
        shutil.rmtree(target_folder)
        print('[%s]의 모든 하위 디렉토리와 파일들을 삭제햇습니다. ' %target_folder)
    except Exception as e:
        print(e)