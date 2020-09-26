spos = 2
size = 10

f = open('mydata.txt', 'r')
h = open('mydata_part.txt', 'w')

f.seek(spos)
data = f.read(size)
h.write(data)

h.close()
f.close()