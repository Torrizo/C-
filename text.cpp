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
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
////struct A{ int a[10000]; };
////A a;
////// ֵ����
////A TestFunc1() { return a; }
////// ���÷���
////A& TestFunc2(){ return a; }
////void TestReturnByRefOrValue()
////{
////	// ��ֵ��Ϊ�����ķ���ֵ����
////	size_t begin1 = clock();
////	for (size_t i = 0; i < 100000; ++i)
////		TestFunc1();
////	size_t end1 = clock();
////	// ��������Ϊ�����ķ���ֵ����
////	size_t begin2 = clock();
////	for (size_t i = 0; i < 100000; ++i)
////		TestFunc2();
////	size_t end2 = clock();
////	// �������������������֮���ʱ��
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
//	//auto e; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
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