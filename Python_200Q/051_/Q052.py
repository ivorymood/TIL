class MyClass:
    # 클래스 생성자
    def __init__(self, *args):
        self.var = '안녕하세요'
        print('MyClass 인스턴스 객체가 생성되었습니다')

class MyClass2:
    def __init__(self, text):
        self.var = text
        print('생성 인자로 전달받은 값은 <'+self.var+'>입니다')

obj = MyClass()
print(obj.var)

obj2 = MyClass2('철수')