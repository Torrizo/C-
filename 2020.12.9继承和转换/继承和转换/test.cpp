#include<iostream>
#include<string>
using namespace std;


class A
{
public:
	static int _i;
};

int A::_i = 10;
class B : public A
{

};

class C : public B
{

};

void test()
{
	A a;
	B b;
	C c;
	int* prt = &a._i;
	prt = &b._i;
    prt = &c._i;

}
//class A
//{
//public:
//	A()//���캯��
//	{
//		cout << "A()" << endl;
//	}
//	A(int a)
//		:_a(a)
//	{
//		cout << "A()" << endl;
//	}//��������
//	A(const A& a)
//	{
//		cout << "A(const A& a)" << endl;
//	}
//	A& operator=(const A& a)
//	{
//		cout << "operator=(const A& a)" << endl;
//		return *this;
//	}
//	~A()//��������  //desturctorduo��̬
//	{
//		cout << "~A" << endl;
//	}
//private:
//	int _a;
//
//};
//
//
//class B : public A
//{
//public:
//
//	//���๹�������๹���ʼ���б���Զ�����
//	//��ִ�и���Ĺ��캯������ִ�����๹�캯���ĺ�����
//	//�������û��Ĭ�Ϲ��죬��Ҫ��ʾָ��
//	//
//	B()
//		:A() //��ʾָ��
//	{
//		cout << "B()" << endl;
//	}
//	//�̳��Ը���ĳ�Ա������ø��๹����ɳ�ʼ��
//	//����ֱ�������๹���н��г�ʼ��
//	B(int a, int b)
//		:A(a)
//		, _b(b)
//	{}
//	//��ʾ����
//	B(const B& b)
//		:A(b)
//	{
//		cout << "B(const B& b)" << endl;
//	}
//	B& operator=(const B& b)
//	{
//		cout << "operator=(const B& b)" << endl;
//		//�����operator=�͸����operator=����ͬ������ 
//		A::operator= (b);//�ݹ�ĵ���  //ͬ�����ء���Ҫָ��������
//		return *this;
//	}
//
//	//�ײ����֮�����������͸���������������ͬ������ͬ������
//	~B()//desturctor
//	{
//		A::A();
//		//~A(); �Լ�����ø�������������û��������Լ�����
//		cout << "~B()" << endl;
//	}
//
//private:
//	int _b;
//};
//
//void test()
//{
//
//	//����Ĭ�ϵĸ�ֵ������Զ����ø���ĸ�ֵ�����
//	B b1;
//	//B b2;
//	//b2 = b1;
//	//��ʽ����ĸ�ֵ����������Զ����ø���ĸ�ֵ�����
//
//	//���캯���ĵ���˳������������ĵ���˳��
//	//���죺 ���๹�졪�������๹��
//	//������ ����������������������  
//
//	//���������κ�����£������Զ����ø������������
//	//����Ҫ��������������ʾ���ø����������ᵼ�¸����������ջᱻ��������
//}


//void test()
//{
//	//�����������ʱ�����Զ����ø����Ĭ�Ϲ���
//	B b;
//
//	//û����ʾ��������Ŀ������죺
//	//ִ�п����������ʱ������Ĭ�ϵĿ��������Զ����ø���Ŀ�������
//	//ִ�п�������ʱ������Ŀ��������Զ����ø���Ĺ��캯��
//	B b2 = b;
//}

//class Person
//{
//public://����
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	void  func(int n)
//	{
//		cout << "Person::func() " << endl;
//	}
//protected://����   �����ⲻ�ɼ����������пɼ�
//	string _name = "peter"; // ����
//	int _age = 18; // ����
////private: //˽��
//	int _id = 2; //����������
//};
////�̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��
////Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�
////����Print���Կ�����Ա�����ĸ��á�
//class Student : public Person
//	//class Student : protected Person
//	//class Student : private Person
//{
//public:
//	void setId()
//	{
//		//�����˽�г�Ա�������в��ɼ� ,����ȷʵ������̳�
//		//_id = 10;
//		//��Ҫ��sizeof��
//
//
//
//		//���������е�ID
//		//�����м̳е�ͬ��Id�����أ��С�ͬ�����ء�
//		_id = 10;
//		//�����Ҫ���ʸ����е�ͬ���ĳ�Ա����������ͨ��ָ���������������
//		Person::_id = 20;
//	}
//	void setName()
//	{
//		_name = "peter";
//		_age = 18;
//	}
//
//	void  func()
//	{
//		cout << "Student::func() " << endl;
//	}
//
////protected:
//	int _stuid = 2020; // ѧ��  // name age print
//	int _id = 2;
//};
//class Teacher : public Person
//{
//protected:
//	int _jobid; // ����  //name age print
//};
//
//
////void test()
////{
////	int a = 2.5;//��ʽ����ת��
////	Person p;
////	Student s;
////	//��Ƭ  ���������ת��
////	//����������ת���ǷǷ���
////
////	p = s;//���ำֵ������
////	Person* ptr = &s;
////	Person& ref = s;
////	//�Ƿ�����������ȫ�����ʲ��������������Ա
////	//�ǲ����Ե�s = p;
////
////	//�����ָ��/���ò���ֱ��ת��Ϊ�����ָ��/����
////	//Student* ptr2 = &p;
////	Student* ptr2 = (Student*)&p;
////	Student& ref2 = (Student&)p;
////	//Խ�����  �Ƿ�����
////	ptr2->_stuid = 2;
////	ref2._stuid = 3;
////}
//void test()
//{
//	Student s;
//	s.setId();//������Ա���Ӹ����������м̳�������
//	//������Ҳ��
//
//	//��Ա������ֻҪ��������ͬ���ͻṹ��ͬ������
//
//	s.func( );//���ʵ�ǰ����
//	s.Person::func(10);//���ʸ���
//
//	//�������о�����Ҫ����ͬ���ĺ����������������
//}

int main()
{
	test();
	system("pause");
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