#include<iostream>
using namespace std;

class Person {
public:
	virtual void func()
	{

	}
	virtual void func2()
	{

	}
	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
};
void Func(Person& p)
{
	p.BuyTicket();
}

//�����ࣺ�������麯������
//�����಻��ʵ��������Ϊ���������д��麯����
class A
{
public:
	//finalʵ�ּ̳� 
	virtual void func()final //�����ε��麯�����������в�����д
	{
		cout << "A :: func()" << endl;
	}
	virtual void func2()
	{
		cout << "A::func2()" << endl;
	}
	//���麯��
	virtual void func4() = 0;
	virtual ~A() //��������д���麯�����ᱣ֤��Դ������ȫ�������ڴ�й©
	{
		cout << "~A()" << endl;
	}
};
class B:public A
{
public:
	//override ǿ������ĺ���������д�����һ���麯��   �����˽ӿڼ̳�
	virtual void func2() override
	{
		cout << "A::func3()" << endl;
	}
	//��д�����еĴ��麯��
	virtual void func4() override
	{
		cout << "A::func4()" << endl;
	}
	virtual ~B()  //��д����������������ײ㺯������ͬ
	{
		cout << "~B()" << endl;
	}
};

//�����˴��麯�����඼�ǳ����࣬�����������Ҳ�ǳ�����
class C : public A
{

};
//void test()
//{
//	//A* pa = new A;//������
//	//C* pc = new C;//�����������
//}

//void test()
//{
//	A* pa = new A;
//	B* pb = new B;
//	delete pa;
//	delete pb;
//
//	//��Ƭ  �����ڴ�й©�ķ��գ��������Ƕ�̬������������������Դ���룬�ᵼ��ֻ����ø��������
//	//�������Դû���ͷŵ��������ڴ�й¶�ķ��ա�
//
//
//	//��̬�����󣬷Ƕ�̬������
//	//������󡪡�����������
//	//����ָ�룬����
//	A* pc = new B;
//	delete pc;
//}

class Base
{
public:
	virtual void Func1()//���麯����СΪ8��û���麯���ڴ�Ϊ4
	{
		cout << "Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Func2()" << endl;
	}
    void Func3() //��ͨ������������в����ڣ�������Ҳ���func3�Ĵ���
	{
		cout << "Func3()" << endl;
	}

private:
	int _b = 1;
};
//��̬�������麯����Ա������д�ŵ�ʵ�ʵ�ַ������
//��̬���̣�
//1.ͨ��ָ��/���ö�λ��ʵ�ʵĶ���2.�Ӷ����л�ȡʵ�������׵�ַ�����ָ�룩3.�����ָ���ҵ�ʵ�ʵ�ַ
//���ָ����һ������ָ��
class Derive :public Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
	virtual void Func4()
	{
		cout << "Func4()" << endl;
	}
	virtual void Func5()
	{
		cout << "Func5()" << endl;
	}
};
void test()
{
	//cout << sizeof(Base) << endl;
	//A* pa = new A;//������
	//C* pc = new C;//�����������
	//���ݶ�
	static int a = 3;
	//ջ
	int stackval = 10;
	//����
	int *pHeap = new int;
	//�����
	char* pc = "1234";
	//�鱨ָ��
	Base b;

}

int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);

	test();
	system("pause");
	return 0;
}