class MyClass:
    var = '안녕하세요!!'
    def sayHello(self):
        param1 = '안녕'
        self.param2 = '하이'
        print(param1)
        print(self.var)

obj = MyClass()
print(obj.var)
# self.param2가 sayHello() 내에서 선언된 인스턴스 멤버이기 때문에
# sayHello()가 한번은 호출되어야 self.param2를 쓸 수 있다.
# print(obj.param2)
obj.sayHello()
print(obj.param2)