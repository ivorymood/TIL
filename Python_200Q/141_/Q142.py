f = open('mydata.txt', 'r')
h = open('mydata2.txt', 'w')

data = f.read()
h.write(data)

f.close()
h.close()