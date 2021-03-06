#include<iostream>
using namespace std;

//class Solution
//{
//public:
//	Solution Print()
//	{
//		cout << " Solution()" << endl;
//	}
//	int Sum_Solutin(int n)
//	{
//		cout << "~Solution()" << endl;
//		return n;
//	}
//};
//int main()
//{
//	Solution s1;
//	s1.Sum_Solutin(10); //S1生命周期在这一行
//
//
//	//Solution();//匿名对象
//	Solution().Sum_Solutin(10);   //只有这一行会使用这个创建对象，别人不需要使用
//                                   //生命周期在这一行
//
//
//	return 0;
//}

//int main()
//{
//	static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int year; int month; int day;
//	// 这样可以不断接收输入  按ctrl+c结束
//	while (cin >> year >> month >> day)
//	{
//		int n = 0;
//		for (int i = 1; i < month; ++i)
//		{
//			n += monthDays[i];
//		}
//		n += day;
//		if (month > 0 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			n += 1;
//		}
//		cout << n << endl;
//	}
//	return 0;
//}



class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
};
class C
{
public:
	C()
	{
		cout << "C()" << endl;
	}
	~C()
	{
		cout << "~C()" << endl;
	}
};
class D
{
public:
	D()
	{
		cout << "D()" << endl;
	}
	~D()
	{
		cout << "~D()" << endl;
	}
};
C c;
int main()
{
	A a;
	B b;
	static D d;
}
//  C  D  A  B
// `B `A `D `C  //静态的局部对象，只有在走到时才会初始化







//全局变量 —— 数据段       main 函数之前就初始化   在哪都能使用，作用域是全局的

//非静态的局部变量 —— 栈

//静态局部变量 —— 数据段     //运行到main函数在初始化 它的作用域在test函数中，
                           //只能在test函数中使用

//那么这两个全局的有什么区别？
//链接属性不一样：globalVar 所有文件可见
                //staticGlobalVar 只在当前文件可见 
//静态全局变量 —— 数据段

//数组  变量 —— 栈

//*char 2取的首元素地址，char是个数组，*char2 —— 栈

//* + 名称 看的是后面的所在的位置

int mian()
{
	//c语言
	int* p1 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int)*10);

	free(p1);
	free(p3);


	//C++操作符
	//int* p2 = new int ;
	int* p2 = new int(10);      //申请一个int 4个字节空间，初始化为10
	int* p4 = new int[10];      //申请10个int 的40个字节的空间

	delete p2;
	delete[] p4;


	return 0;
}

//既然有了malloc和free 那new 和 delete的区别是
//对于上面内置类型是一样的
//对于自定义类型就有区别



class A
{
public:
	A()
	{
		_a = 0;
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};


int main()
{
	int* p1 = new int;
	int* p2 = (int*)malloc(sizeof(int));

	A* p3 = (A*)malloc(sizeof(A));        //申请空间
	A* p4 = new A;                        //申请空间 + 构造函数初始化

	free(p3);                             //释放空间
	delete p4;                            //析构函数

	return 0;
}