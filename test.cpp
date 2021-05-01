#include<iostream>
#include"test.h"
using namespace std;

//模板不支持分离编译：生命和定义都写在头文件里面
void test()
{
	int a = add(1, 2);
}
//含有模板的代码，声明和定义不能分开，声明和定义要写在.h/,hpp里面
int main()
{
	test();
	return 0;
}

//template <class T1，class T2>
//class Data
//{
//public:
//	Data(){ cout << "Data<T1,T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//
////半特化
////对模板参数做进一步的限制
//template <class T1，class T2>
//class Data<T1*,T2*>
//{
//public:
//	Data(){ cout << "Data<T1,T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template <class T1，class T2>
//class Data<T1&, T2&>
//{
//public:
//	Data(){ cout << "Data<T1,T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//void test()
//{
//	Date<int, char >d1;
//	Date<int&, char&>d2;
//	Date<int*, char*>d3;
//}
////半特化
////特化部分类
//template<class T>
//class Data<T, char>
//{
//public:
//	Data(){ cout << "Data<T,char>" << endl; }
//private:
//	T _d1;
//	char _d2;
//};
//
//void test()
//{
//	Data<int, int>d1;
//	Data<char, char>d2;
//	Data<int, char>d3;
//	//这样编辑器会报错，只能屏蔽到一个模板
//	Data<double, double>d4; //普通模板实例化
//}
////模板类的全特化
////必须有一个普通的模板类
//template<>
//class Data<int, char>
//{
//public:
//	Data(){ cout << "Data<int,char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//
//
//void TestVector()
//{
//	Date<int, int> d1; //普通类模版
//	Date<int, char>d2; //特化（全特化）
//}