#include<iostream>
using namespace std;
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
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
private:
	int _b = 1;
};
void test()
{
	cout << sizeof(Base) << endl;
	//A* pa = new A;//������
	//C* pc = new C;//�����������
}

int main()
{
	test();
	system("pause");
	return 0;
}