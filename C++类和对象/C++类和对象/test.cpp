//#include<iostream>
//using namespace std;
//
//////��ζ���һ����
//////��װ
//////1.�����ݺͷ����ŵ�����һ��
//////2.������㿴�������ݶ���ɸ��㿴��������㿴�ķ�װ������   �����޶���
////
////
////class Stack  //дһ��ջ
////{
////public:
////	//1.��Ա����
////	void Push(int x);
////	void Pop();
////	void Empty();
////	//...
////private:
////	//2.��Ա����
////	int* _a;
////	int _size;
////	int _capacity;
////};
////
////
//////c������struct����������ṹ���
//////c++�У�����c��struct����ṹ����÷�������ͬʱstructҲ��������������
//////c++��ʹ��class��struct�����������-��Ĭ�ϵķ����޶���
////struct ListNode_C   //Ĭ�Ϲ���
////{
////	int _val;
////	struct ListNode_C* _next; //����c���÷�
////	struct ListNode_C* _prev;
////
////};
////
////struct ListNode_CPP  
////{
////	int _val;
////	ListNode_CPP* _next;    //����c++���÷�
////	ListNode_CPP* _prev;
////	//�����Զ��庯��-����Ա����
////	ListNode_CPP CreateNode(int val);
////};
////
//////1.�����Ͷ��������   ������һ�ֳ�ŵ����ŵҪ���
//////���ǻ�û����������ǰ�����������ˣ�
//
//class Stack   //дһ��ջ
//{
//public:
//	//1.��Ա����
//	void Push(int x)//�������涨��
//	{
//		//...
//	}
//
//	void Pop();
//	bool Empty(); //����Ҳ������
//	//...
//private:
//	//2.��Ա����
//	int* _a;     //���������������������涨��
//	int _size;
//	int _capacity;//����������
//};
//
//
//int main()
//{
//	//��ʵ�����������൱�ڶ��������ĳ�Ա����
//	struct s1;
//	struct s2;
//	struct s3;
//	//s1._a = nullptr;
//
//	//������ֻ�洢��Ա���� ���洢��Ա����
//	cout << sizeof(s1) << endl;   //��12
//	//һ��ʵ������N������ÿ������ĳ�Ա���������Դ治ͬ��ֵ�������õĺ���ȴ��ͬһ��
//	//���ÿ�����󶼷ų�Ա����������Щ��Ա��������һ���ģ��˷ѿռ䡣
//	//��μ���һ��ʵ�������Ķ���Ĵ�С�������Ա����֮�ͣ����ҿ����ڴ�������
//	//û�г�Ա��������Ĵ�С��1
//	//Ϊʲô��1
//	return 0;
//}

 //ʵ����-�������Լ���������Ͷ��������
//1.�������ͣ��������� int/char/double
//2.�Զ������ͣ�class / struct

//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	//thisָ����˭�����ã�this��ָ��˭
//	void Init(int year, int month, int day) //void Init(Date* this,int year, int month, int day)
//	{
//		/*_year = year;
//		_month = month;
//		_day = day;*/
//		this -> _year = year;
//		this -> _month = month;//�����ã�����һ�㲻���
//		this -> _day = day;
//	}
//	void print() //void print(Date* this)
//	{
//		cout << _year << "-" << _month << "_" << _day << endl;
//	}//������thisָ��ɲ����͹��� �������ӵ�
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////thisָ���������
////ջ�ϵĴ洢�� 
//
//
//
//
//class A
//{
//public:
//	void printA()
//	{
//		cout << _a << endl;//		cout << this-> _a << endl;���ⱨ��
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//
//int main()
//{
//	Date d1;
//	d1.Init(2020, 4, 7);
//
//	A* p = NULL;
//	p->printA();//��ָ�벻����ڱ��벻ͨ�������⡣
//	p->Show(); //���ʳ�Ա�����Ż�ȥ��
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Date
//{
//public:
//	//���캯�� -���ڶ������ʱ����õĺ��������������ɳ�ʼ���Ĺ���
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//
//
//	Date() //�����ǳ�ʼ�������� 
//	{
//		_year = 0;
//		_month = 1;
//		_day = 1;
//	}
//
//
//
//
//
//
//
//	//thisָ����˭�����ã�this��ָ��˭
//	void Init(int year, int month, int day) //void Init(Date* this,int year, int month, int day)
//	{
//		/*_year = year;
//		_month = month;
//		_day = day;*/
//		this -> _year = year;
//		this -> _month = month;//�����ã�����һ�㲻���
//		this -> _day = day;
//	}
//	void print() //void print(Date* this)
//	{
//		cout << _year << "-" << _month << "_" << _day << endl;
//	}//������thisָ��ɲ����͹��� �������ӵ�
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//	
//
//int main()
//{
//	//����ʵ�л�ʱ�Զ�����
//	Date d1(2020, 4, 8);  //�Զ�����
//	d1.print();
//	d1.Init(2020, 4, 7);
//	
//
//
//	Date d2; //���ܼ����ţ������ű༭������ʶ�ᱨ��ʶ�𲻳����ء�
//	d2.Init(2020, 4, 7);
//	d2.print();
//	return 0;
//}
#include<iostream>
using namespace std;






//class Time
//{
//public:
//	Time()
//	{
//		_hour = 0;
//		_minute = 0;
//		_second = 0;
//
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//
//};
//
//
//
////5���������û����ʽ���幹�캯������C++���������Զ�����һ���޲ε�Ĭ�Ϲ��캯����һ���û���ʽ������������������ɡ�
//
//class Date
//{
//public:
//	//����û����ʾ���幹�캯������������������޲�Ĭ�Ϲ��캯��
//	void print() //void print(Date* this)
//	{
//		cout << _year << "-" << _month << "_" << _day << endl;
//	}//������thisָ��ɲ����͹��� �������ӵ�
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//
//
//int main()
//{
//	Date d1; //���ñ��������ɹ��캯��
//	d1.print();
//	
//	return 0;
//}

//6.�޲εĹ��캯����ȫȱʡ�Ĺ��캯������ΪĬ�Ϲ��캯��������Ĭ�Ϲ��캯��ֻ����һ����ע�⣺�޲ι��캯����ȫȱʡ���캯��������ûд������Ĭ�����ɵĹ��캯������������Ϊ��Ĭ�Ϲ��캯����
// Ĭ�Ϲ��캯��
//class Date
	//{
	//public:
	//	// һ���û���ʽ������������������ɡ�
	//	/*Date()
	//	{
	//	_year = 0;
	//	_month = 1;
	//	_day = 1;
	//	}
	//	*/
	//	
	//	Date(int year, int month, int day)
	//	{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//	}
	//
	//	// ���õķ�ʽ->ȫȱʡ
	//	/*Date(int year = 0, int month = 1, int day = 1)
	//	{
	//		_year = year;
	//		_month = month;
	//		_day = day;
	//	}*/
	//
	//	void Print()  // void Print(Date* this) 
	//	{
	//		cout << _year << "-" << _month << "-" << _day << endl;
	//	}
	//private:
	//	int _year;
	//	int _month;
	//	int _day;
	//};
	//
	//int main()
	//{
	//	Date d1;   // ����Ĭ�Ϲ��캯��  -��1���Լ�ʵ���޲εĹ��캯�� 2���Լ�ʵ�ֵ�ȫȱʡ���캯��  3�����ǲ�д�������Զ����ɵ�
	//	                                   // �ص㣺���ô�����
	//	d1.Print();
	//
	//	//Date d2(2020, 3, 8);
	//	//d2.Print();
	//
	//	return 0;
	//}

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		cout << "Date(int year = 0, int month = 1, int day = 1)" << endl;
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()  // void Print(Date* this) 
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

class Stack
{
public:
	Stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int)*n);
		cout << "malloc:" << _a << endl;
		_size = 0;
		_capacity = n;
	}

	~Stack()
	{
		free(_a);
		cout << "free:" << _a << endl;
		_a = nullptr;
		_size = _capacity = 0;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};

int main()
{
	// �����������������ڵ����Ժ��Զ����á���ɶ����������Դ���������������d1��d2����
	Date d1;
	Date d2;

	Stack s1;
	Stack s2;

	// ...Push

	return 0;
}






