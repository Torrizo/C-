#include<iostream>
#include<string>
using namespace std;


class A
{
public:
	static int _i;
};

int A::_i = 10;
class B : public A
{

};

class C : public B
{

};

void test()
{
	A a;
	B b;
	C c;
	int* prt = &a._i;
	prt = &b._i;
    prt = &c._i;

}
//class A
//{
//public:
//	A()//构造函数
//	{
//		cout << "A()" << endl;
//	}
//	A(int a)
//		:_a(a)
//	{
//		cout << "A()" << endl;
//	}//拷贝构造
//	A(const A& a)
//	{
//		cout << "A(const A& a)" << endl;
//	}
//	A& operator=(const A& a)
//	{
//		cout << "operator=(const A& a)" << endl;
//		return *this;
//	}
//	~A()//析构函数  //desturctorduo多态
//	{
//		cout << "~A" << endl;
//	}
//private:
//	int _a;
//
//};
//
//
//class B : public A
//{
//public:
//
//	//父类构造在子类构造初始化列表出自动调用
//	//先执行父类的构造函数，在执行子类构造函数的函数体
//	//如果父类没有默认构造，需要显示指定
//	//
//	B()
//		:A() //显示指定
//	{
//		cout << "B()" << endl;
//	}
//	//继承自父类的成员必须调用父类构造完成初始化
//	//不能直接在子类构造中进行初始化
//	B(int a, int b)
//		:A(a)
//		, _b(b)
//	{}
//	//显示定义
//	B(const B& b)
//		:A(b)
//	{
//		cout << "B(const B& b)" << endl;
//	}
//	B& operator=(const B& b)
//	{
//		cout << "operator=(const B& b)" << endl;
//		//子类的operator=和父类的operator=构成同名隐藏 
//		A::operator= (b);//递归的调用  //同名隐藏。需要指定作用域
//		return *this;
//	}
//
//	//底层编译之后，子类析构和父类析构函数名相同，构成同名隐藏
//	~B()//desturctor
//	{
//		A::A();
//		//~A(); 自己会调用父类的析构，不用画蛇添足自己调用
//		cout << "~B()" << endl;
//	}
//
//private:
//	int _b;
//};
//
//void test()
//{
//
//	//子类默认的赋值运算符自动调用父类的赋值运算符
//	B b1;
//	//B b2;
//	//b2 = b1;
//	//显式定义的赋值运算符不会自动调用父类的赋值运算符
//
//	//构造函数的调用顺序和析构函数的调用顺序
//	//构造： 父类构造——》子类构造
//	//析构： 子类析构——》父类析构  
//
//	//编译器在任何情况下，都会自动调用父类的析构函数
//	//不需要在子类析构中显示调用父类析构：会导致父类析构最终会被调用两次
//}


//void test()
//{
//	//创建子类对象时，会自动调用父类的默认构造
//	B b;
//
//	//没有显示定义子类的拷贝构造：
//	//执行拷贝构造对象时：子类默认的拷贝构造自动调用父类的拷贝构造
//	//执行拷贝对象时：子类的拷贝构造自动调用父类的构造函数
//	B b2 = b;
//}

//class Person
//{
//public://公有
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	void  func(int n)
//	{
//		cout << "Person::func() " << endl;
//	}
//protected://保护   在类外不可见，在子类中可见
//	string _name = "peter"; // 姓名
//	int _age = 18; // 年龄
////private: //私有
//	int _id = 2; //父类作用域
//};
////继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和
////Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。
////调用Print可以看到成员函数的复用。
//class Student : public Person
//	//class Student : protected Person
//	//class Student : private Person
//{
//public:
//	void setId()
//	{
//		//基类的私有成员在子类中不可见 ,但是确实被子类继承
//		//_id = 10;
//		//需要用sizeof看
//
//
//
//		//设置子类中的ID
//		//父类中继承的同名Id被隐藏：叫“同名隐藏”
//		_id = 10;
//		//如果需要访问父类中的同名的成员变量，可以通过指定父类作用域访问
//		Person::_id = 20;
//	}
//	void setName()
//	{
//		_name = "peter";
//		_age = 18;
//	}
//
//	void  func()
//	{
//		cout << "Student::func() " << endl;
//	}
//
////protected:
//	int _stuid = 2020; // 学号  // name age print
//	int _id = 2;
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // 工号  //name age print
//};
//
//
////void test()
////{
////	int a = 2.5;//隐式类型转换
////	Person p;
////	Student s;
////	//切片  子类向父类的转化
////	//父类向子类转化是非法的
////
////	p = s;//子类赋值给父类
////	Person* ptr = &s;
////	Person& ref = s;
////	//非法操作，不安全，访问不到子类的新增成员
////	//是不可以的s = p;
////
////	//父类的指针/引用不能直接转换为子类的指针/引用
////	//Student* ptr2 = &p;
////	Student* ptr2 = (Student*)&p;
////	Student& ref2 = (Student&)p;
////	//越界访问  非法操作
////	ptr2->_stuid = 2;
////	ref2._stuid = 3;
////}
//void test()
//{
//	Student s;
//	s.setId();//两个成员，从父类作用域中继承下来，
//	//子类中也有
//
//	//成员函数，只要函数名相同，就会构成同名函数
//
//	s.func( );//访问当前子类
//	s.Person::func(10);//访问父类
//
//	//在子类中尽量不要构造同名的函数，容易造成隐藏
//}

int main()
{
	test();
	system("pause");
	return 0;
}

//void test()
//{
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	Student s;
//	s.Print();
//}
//
//
//int main()
//{
//	/*Student s;
//	Teacher t;
//	s.Print();
//	t.Print();*/
//
//	test();
//	system("pause");
//	return 0;
//}