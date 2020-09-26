from os.path import getsize

file1 = 'mydata.txt'
file2 = 'D:\TIL\Python_200Q\\141_\puppy.jpg'
file_size1 = getsize(file1)
file_size2 = getsize(file2)

print('File Name: %s \tFile Size: %d' %(file1, file_size1))
print('File Name: %s \tFile Size: %d' %(file2, file_size2))
