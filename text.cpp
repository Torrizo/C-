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
class Car
{
public:
	virtual void Drive() = 0;
};
class Benz :public Car
{
public:
	 void Drive()
	{
		cout << "Benz-����" << endl;
	}
};
class BMW :public Car
{
public:
	 void dDrive()
	{
		cout << "BMW-�ٿ�" << endl;
	}
};
void Test()
{
	Car* pBenz = new Benz;
	pBenz->Drive();
	Car* pBMW = new BMW;
	pBMW->Drive();
}
int main()
{
	//cout << sizeof(Base) << endl;
	Test();
	system("pause");
	return 0;
}