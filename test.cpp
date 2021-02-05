#include<iostream>
using namespace std;

class Person {
public:
	virtual void func()
	{

	}
	virtual void func2()
	{

	}
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();
}

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
	virtual void Func1()//有虚函数大小为8，没有虚函数内存为4
	{
		cout << "Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Func2()" << endl;
	}
    void Func3() //普通函数，再虚表中不存在，虚表中找不到func3的存在
	{
		cout << "Func3()" << endl;
	}

private:
	int _b = 1;
};
//多态看对象。虚函数成员：虚表中存放的实际地址决定，
//多态过程：
//1.通过指针/引用定位到实际的对象2.从对象中获取实际虚表的首地址（虚表指针）3.从虚表指针找到实际地址
//虚表指针是一个二级指针
class Derive :public Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
	virtual void Func4()
	{
		cout << "Func4()" << endl;
	}
	virtual void Func5()
	{
		cout << "Func5()" << endl;
	}
};
void test()
{
	//cout << sizeof(Base) << endl;
	//A* pa = new A;//抽象类
	//C* pc = new C;//抽象类的子类
	//数据段
	static int a = 3;
	//栈
	int stackval = 10;
	//堆上
	int *pHeap = new int;
	//代码段
	char* pc = "1234";
	//虚报指针
	Base b;

}

int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);

	test();
	system("pause");
	return 0;
}