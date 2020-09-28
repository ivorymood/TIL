url = 'http://new.nver.com/main/read.nhn?mode=LSD&mid=shm&sidl=105&oid=028&aid=23456234'

tmp = url.split('?')
queries = tmp[1].split('&')
for query in queries:
    print(query)