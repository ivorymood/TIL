import os

# 현재 디렉토리 얻기
pdir = os.getcwd()
print(pdir)
# 부모 디렉토리로 작업 디렉토리를 변경
os.chdir('..')
print(os.getcwd())
os.chdir(pdir)
print(os.getcwd())