#include<iostream>
#include"test.h"
using namespace std;

//ģ�岻֧�ַ�����룺�����Ͷ��嶼д��ͷ�ļ�����
void test()
{
	int a = add(1, 2);
}
//����ģ��Ĵ��룬�����Ͷ��岻�ֿܷ��������Ͷ���Ҫд��.h/,hpp����
int main()
{
	test();
	return 0;
}

//template <class T1��class T2>
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
////���ػ�
////��ģ���������һ��������
//template <class T1��class T2>
//class Data<T1*,T2*>
//{
//public:
//	Data(){ cout << "Data<T1,T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template <class T1��class T2>
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
////���ػ�
////�ػ�������
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
//	//�����༭���ᱨ��ֻ�����ε�һ��ģ��
//	Data<double, double>d4; //��ͨģ��ʵ����
//}
////ģ�����ȫ�ػ�
////������һ����ͨ��ģ����
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
//	Date<int, int> d1; //��ͨ��ģ��
//	Date<int, char>d2; //�ػ���ȫ�ػ���
//}