#include<iostream>
using namespace std;

//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // ����
//public:
//	static int _count; // ͳ���˵ĸ�����
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // ѧ��
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // �о���Ŀ
//};
////class Car
////{
////public:
////	virtual void Drive() final {}
////};
////class Benz :public Car
////{
////public:
////	virtual void Drive() { cout << "Benz-����" << endl; }
////};
////class Car{
////public:
////	virtual void Drive(){}
////};
////class Benz :public Car {
////public:
////	virtual void Drive() override { cout << "Benz-����" << endl; }
////};
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//}
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	 void Drive()
//	{
//		cout << "Benz-����" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	 void Drive()
//	{
//		cout << "BMW-�ٿ�" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}
class Base
{
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// ����ȡ����е��麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	return 0;
}
//int main()
//{
//	//cout << sizeof(Base) << endl;
//	Test();
//	system("pause");
//	return 0;
//}