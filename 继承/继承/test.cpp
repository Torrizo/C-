#include<iostream>
#include<string>
using namespace std;



class Person
{
public://����
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected://����   �����ⲻ�ɼ����������пɼ�
	string _name = "peter"; // ����
	int _age = 18; // ����
private: //˽��
	int _id = 2;
};
//�̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��
//Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�
//����Print���Կ�����Ա�����ĸ��á�
class Student : public Person
//class Student : protected Person
//class Student : private Person
{
public:
	void setId()
	{
		//�����˽�г�Ա�������в��ɼ� ,����ȷʵ������̳�
		//_id = 10;
		//��Ҫ��sizeof��
	}
	void setName()
	{
		_name = "peter";
		_age = 18;
	}
protected:
	int _stuid = 2020; // ѧ��  // name age print
};
class Teacher : public Person
{
protected:
	int _jobid; // ����  //name age print
};


void test()
{
	int a = 2.5;//��ʽ����ת��
	Person p;
	Student s;
	//��Ƭ
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