class MyClass:
    var = '안녕하세요'

# 클래스 메소드는 첫 번째 인자가 반드시 self(인스턴스 객체)로 시작해야 함
    def sayHello(self):
        print(self.var)

# MyClass의 인스턴스 객체 생성
obj = MyClass()
print(obj.var)
obj.sayHello()