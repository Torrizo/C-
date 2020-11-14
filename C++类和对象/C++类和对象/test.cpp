//#include<iostream>
//using namespace std;
//
//////如何定义一个类
//////封装
//////1.将数据和方法放到定义一起
//////2.把想给你看到的数据定义成给你看，不想给你看的封装起来。   访问限定符
////
////
////class Stack  //写一个栈
////{
////public:
////	//1.成员函数
////	void Push(int x);
////	void Pop();
////	void Empty();
////	//...
////private:
////	//2.成员变量
////	int* _a;
////	int _size;
////	int _capacity;
////};
////
////
//////c语言中struct是用来定义结构体的
//////c++中，兼容c的struct定义结构体的用法，但是同时struct也可以用来定义类
//////c++中使用class和struct定义类的区别？-》默认的访问限定符
////struct ListNode_C   //默认公有
////{
////	int _val;
////	struct ListNode_C* _next; //兼容c的用法
////	struct ListNode_C* _prev;
////
////};
////
////struct ListNode_CPP  
////{
////	int _val;
////	ListNode_CPP* _next;    //兼容c++的用法
////	ListNode_CPP* _prev;
////	//还可以定义函数-》成员函数
////	ListNode_CPP CreateNode(int val);
////};
////
//////1.声明和定义的区别？   声明是一种承诺，承诺要干嘛，
//////但是还没做，定义就是把这是事落地了，
//
//class Stack   //写一个栈
//{
//public:
//	//1.成员函数
//	void Push(int x)//在类里面定义
//	{
//		//...
//	}
//
//	void Pop();
//	bool Empty(); //这里也是声明
//	//...
//private:
//	//2.成员变量
//	int* _a;     //在类里面声明，在类外面定义
//	int _size;
//	int _capacity;//这里是声明
//};
//
//
//int main()
//{
//	//类实例化出对象，相当于定义出了类的成员变量
//	struct s1;
//	struct s2;
//	struct s3;
//	//s1._a = nullptr;
//
//	//对象中只存储成员变量 不存储成员函数
//	cout << sizeof(s1) << endl;   //是12
//	//一个实例化出N个对象，每个对象的成员变量都可以存不同的值，但调用的函数却是同一个
//	//如果每个对象都放成员函数，而这些成员函数都是一样的，浪费空间。
//	//如何计算一个实例化出的对象的大小，计算成员变量之和，并且考虑内存对齐规则
//	//没有成员变量的类的大小是1
//	//为什么是1
//	return 0;
//}

 //实例化-》就是自己定义的类型定义出对象
//1.内置类型，基本类型 int/char/double
//2.自定义类型，class / struct

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//this指针是谁来调用，this就指向谁
//	void Init(int year, int month, int day) //void Init(Date* this,int year, int month, int day)
//	{
//		/*_year = year;
//		_month = month;
//		_day = day;*/
//		this -> _year = year;
//		this -> _month = month;//可以用，但是一般不会加
//		this -> _day = day;
//	}
//	void print() //void print(Date* this)
//	{
//		cout << _year << "-" << _month << "_" << _day << endl;
//	}//隐含的this指针吧参数送过来 编译器加的
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////this指针存在那里
////栈上的存储的 
//
//
//
//
//class A
//{
//public:
//	void printA()
//	{
//		cout << _a << endl;//		cout << this-> _a << endl;在这报错
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Init(2020, 4, 7);
//
//	A* p = NULL;
//	p->printA();//空指针不会存在编译不通过的问题。
//	p->Show(); //访问成员函数才会去找
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	//构造函数 -》在对象构造的时候调用的函数，这个函数完成初始化的工作
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//
//	Date() //构造是初始化的作用 
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//
//
//
//
//
//
//	//this指针是谁来调用，this就指向谁
//	void Init(int year, int month, int day) //void Init(Date* this,int year, int month, int day)
//	{
//		/*_year = year;
//		_month = month;
//		_day = day;*/
//		this -> _year = year;
//		this -> _month = month;//可以用，但是一般不会加
//		this -> _day = day;
//	}
//	void print() //void print(Date* this)
//	{
//		cout << _year << "-" << _month << "_" << _day << endl;
//	}//隐含的this指针吧参数送过来 编译器加的
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//	
//
//int main()
//{
//	//对象实列化时自动调用
//	Date d1(2020, 4, 8);  //自动调用
//	d1.print();
//	d1.Init(2020, 4, 7);
//	
//
//
//	Date d2; //不能加括号，带括号编辑器不认识会报错，识别不出重载。
//	d2.Init(2020, 4, 7);
//	d2.print();
//	return 0;
//}
#include<iostream>
using namespace std;






//class Time
//{
//public:
//	Time()
//	{
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//
//};
//
//
//
////5、如果类中没有显式定义构造函数，则C++编译器会自动生成一个无参的默认构造函数，一旦用户显式定义编译器将不再生成。
//
//class Date
//{
//public:
//	//我们没有显示定义构造函数，这里编译器生成无参默认构造函数
//	void print() //void print(Date* this)
//	{
//		cout << _year << "-" << _month << "_" << _day << endl;
//	}//隐含的this指针吧参数送过来 编译器加的
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//
//
//int main()
//{
//	Date d1; //调用编译器生成构造函数
//	d1.print();
//	
//	return 0;
//}

//6.无参的构造函数和全缺省的构造函数都称为默认构造函数，并且默认构造函数只能有一个。注意：无参构造函数、全缺省构造函数、我们没写编译器默认生成的构造函数，都可以认为是默认构造函数。
// 默认构造函数
//class Date
	//{
	//public:
	//	// 一旦用户显式定义编译器将不再生成。
	//	/*Date()
	//	{
	//	_year = 0;
	//	_month = 1;
	//	_day = 1;
	//	}
	//	*/
	//	
	//	Date(int year, int month, int day)
	//	{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//	}
	//
	//	// 更好的方式->全缺省
	//	/*Date(int year = 0, int month = 1, int day = 1)
	//	{
	//		_year = year;
	//		_month = month;
	//		_day = day;
	//	}*/
	//
	//	void Print()  // void Print(Date* this) 
	//	{
	//		cout << _year << "-" << _month << "-" << _day << endl;
	//	}
	//private:
	//	int _year;
	//	int _month;
	//	int _day;
	//};
	//
	//int main()
	//{
	//	Date d1;   // 调用默认构造函数  -》1、自己实现无参的构造函数 2、自己实现的全缺省构造函数  3、我们不写，编译自动生成的
	//	                                   // 特点：不用传参数
	//	d1.Print();
	//
	//	//Date d2(2020, 3, 8);
	//	//d2.Print();
	//
	//	return 0;
	//}

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		cout << "Date(int year = 0, int month = 1, int day = 1)" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()  // void Print(Date* this) 
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

class Stack
{
public:
	Stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int)*n);
		cout << "malloc:" << _a << endl;
		_size = 0;
		_capacity = n;
	}

	~Stack()
	{
		free(_a);
		cout << "free:" << _a << endl;
		_a = nullptr;
		_size = _capacity = 0;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};

int main()
{
	// 析构：对象声明周期到了以后，自动调用。完成对象里面的资源清理工作，不是完成d1和d2销毁
	Date d1;
	Date d2;

	Stack s1;
	Stack s2;

	// ...Push

	return 0;
}






