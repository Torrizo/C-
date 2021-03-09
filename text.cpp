#include<iostream>
using namespace std;

//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
////class Car
////{
////public:
////	virtual void Drive() final {}
////};
////class Benz :public Car
////{
////public:
////	virtual void Drive() { cout << "Benz-舒适" << endl; }
////};
////class Car{
////public:
////	virtual void Drive(){}
////};
////class Benz :public Car {
////public:
////	virtual void Drive() override { cout << "Benz-舒适" << endl; }
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
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
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
		cout << "Benz-舒适" << endl;
	}
};
class BMW :public Car
{
public:
	 void dDrive()
	{
		cout << "BMW-操控" << endl;
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