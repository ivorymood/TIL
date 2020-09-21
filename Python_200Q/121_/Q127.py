names = {'Marry': 10999, 'Sams': 2111, 'Aimy': 9778, 'Tom': 20245,
         'Michale':27115, 'Bob':5887, 'Kelly':7855}
ks = names.keys()
list_ks = list(names.keys())
print(ks)
print(list_ks)

for k in ks:
    print('Key:%s \t Value:%d' %(k, names[k]))

for k in list_ks:
    print('Key:%s \t Value:%d' %(k, names[k]))
