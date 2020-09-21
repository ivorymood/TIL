solarsys = ['태양', '수성', '금성', '지구', '화성', '목성', '토성', '천왕성', '해왕성', '지구']
solarsys.remove('태양')
print(solarsys)

# 존재하지 않는 요소를 제거하려고 하면 [x not in list 에러 발생]
# solarsys.remove('something')