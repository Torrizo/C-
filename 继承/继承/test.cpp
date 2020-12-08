#include<iostream>
#include<string>
using namespace std;



class Person
{
public://公有
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected://保护   在类外不可见，在子类中可见
	string _name = "peter"; // 姓名
	int _age = 18; // 年龄
private: //私有
	int _id = 2;
};
//继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了Student和
//Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可以看到变量的复用。
//调用Print可以看到成员函数的复用。
class Student : public Person
//class Student : protected Person
//class Student : private Person
{
public:
	void setId()
	{
		//基类的私有成员在子类中不可见 ,但是确实被子类继承
		//_id = 10;
		//需要用sizeof看
	}
	void setName()
	{
		_name = "peter";
		_age = 18;
	}
protected:
	int _stuid = 2020; // 学号  // name age print
};
class Teacher : public Person
{
protected:
	int _jobid; // 工号  //name age print
};


void test()
{
	int a = 2.5;//隐式类型转换
	Person p;
	Student s;
	//切片
	p = s;
	Person* ptr = &s;
	Person& ref = s;
}

int main()
{

	test();
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