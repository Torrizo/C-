#include<iostream>
using namespace std;
//抽象类：包含纯虚函数的类
//抽象类不能实例化，因为不完整，有纯虚函数。
class A
{
public:
	//final实现继承 
	virtual void func()final //他修饰的虚函数，在子类中不能重写
	{
		cout << "A :: func()" << endl;
	}
	virtual void func2()
	{
		cout << "A::func2()" << endl;
	}
	//纯虚函数
	virtual void func4() = 0;
	virtual ~A() //析构尽量写成虚函数，会保证资源尽量安全，不会内存泄漏
	{
		cout << "~A()" << endl;
	}
};
class B:public A
{
public:
	//override 强制子类的函数必须重写父类的一个虚函数   体现了接口继承
	virtual void func2() override
	{
		cout << "A::func3()" << endl;
	}
	//重写父类中的纯虚函数
	virtual void func4() override
	{
		cout << "A::func4()" << endl;
	}
	virtual ~B()  //重写父类的析构函数，底层函数名相同
	{
		cout << "~B()" << endl;
	}
};

//包含了纯虚函数的类都是抽象类，抽象类的子类也是抽象类
class C : public A
{

};
//void test()
//{
//	//A* pa = new A;//抽象类
//	//C* pc = new C;//抽象类的子类
//}

//void test()
//{
//	A* pa = new A;
//	B* pb = new B;
//	delete pa;
//	delete pb;
//
//	//切片  具有内存泄漏的风险：析构不是多态，如果子类对象中有资源申请，会导致只会调用父类的析构
//	//子类的资源没有释放掉，会有内存泄露的风险。
//
//
//	//多态看对象，非多态看类型
//	//子类对象——》子类析构
//	//父类指针，引用
//	A* pc = new B;
//	delete pc;
//}

class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};
void test()
{
	cout << sizeof(Base) << endl;
	//A* pa = new A;//抽象类
	//C* pc = new C;//抽象类的子类
}

int main()
{
	test();
	system("pause");
	return 0;
}