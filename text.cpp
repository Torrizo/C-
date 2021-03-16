#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
//#include <time.h>
using namespace std;
////int& Add(int a, int b) {
////	int c = a + b;
////	return c;
////}
///*int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1, 2) is :" << ret << endl;
//	system("pause");
//	return 0;
//}*/
//struct A{ int a[10000]; };
//void TestFunc1(A a){}
//void TestFunc2(A& a){}
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
////struct A{ int a[10000]; };
////A a;
////// 值返回
////A TestFunc1() { return a; }
////// 引用返回
////A& TestFunc2(){ return a; }
////void TestReturnByRefOrValue()
////{
////	// 以值作为函数的返回值类型
////	size_t begin1 = clock();
////	for (size_t i = 0; i < 100000; ++i)
////		TestFunc1();
////	size_t end1 = clock();
////	// 以引用作为函数的返回值类型
////	size_t begin2 = clock();
////	for (size_t i = 0; i < 100000; ++i)
////		TestFunc2();
////	size_t end2 = clock();
////	// 计算两个函数运算完成之后的时间
////	cout << "TestFunc1 time:" << end1 - begin1 << endl;
////	cout << "TestFunc2 time:" << end2 - begin2 << endl;
////}
////int main()
////{
////	TestRefAndValue();
////	TestReturnByRefOrValue();
////	system("pause");
////	return 0;
////}
//int TestAuto()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = TestAuto();
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
//	system("pause");
//	return 0;
//}
class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};
int main()
{
	String s1("hello");
	String s2 = s1;
	return 0;
}