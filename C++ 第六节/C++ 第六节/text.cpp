#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	//��̬��Ա�������Ե��÷Ǿ�̬��Ա������    ����
	void f1()
	{

	}
	static void f2()
	{
		//f1();//û��thisָ��
	}
	//�Ǿ�̬��Ա�������Ե�����ľ�̬��Ա������  ����
	void f3()
	{
		f4();//ͻ������+�����޶����Ϳ��Է��ʣ�
		    //��������һ�����嶼�������У������治�ܷ����޶�������
	}
	static void f4()
	{
	}

private:
	int _year;
	int _month;
	int _day;

};

//static��Ա
//1.
//2.
//3.

//��1+2+3+...+n.Ҫ����ʹ�ó˳���for while��if��else��...

class Sum {
public:
	Sum() {
		_sum += _i;
		++_i;
	}

	static void Init()
	{
		_i = 1;
		_sum = 0;
	}

	static int GetSum() {
		return _sum;
	}
private:
	static int _i;
	static int _sum;
};
int Sum::_i = 1;
int Sum::_sum = 0;

class Solution {
public:
	int Sum_Solution(int n) {
		Sum::Init();
		Sum* p = new Sum[n];
		return Sum::GetSum();
	}
};


int main()
{
	Date d1(1, 2, 3);
	Date d2 = 1;
	Date d3 = { 1, 2 };
	Date d4 = { 1, 2, 3 };

	//ͻ�Ʒ����޶��������ַ�ʽ������������֪�����Ǹ���+�����޶����Ƿ���Է���
	d1.f4();
	Date::f4;


    return 0;
}




��Ԫ
#include<iostream>
using namespace std;
class Date
{
	friend void f(Date& d); //��Ԫ����
public:
	/*Date()
		:_year(10)
	{}*/

	void Print()
	{
		cout << _year << "-" << _month << "-" << "-" << _day << endl;
	}
private:
	//C++11
	//����ʱ��ȱʡ
	int _year = 0;
	int _month = 1;
	int _day = 1;
	////ֻ������������ж���
	//static int _n;
};

void f(Date& d)
{
	d._year = 10;
	cout << d._year << endl;
}

int main()
{
	Date d1;
}


#include<iostream>
using namespace std;
class Date
{
	friend istream& operator<<(istream& in, Date& d);
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	/*void operator<<(ostream& out, const Date& d)
	{
		out << _year << "/" << _month << "/" << _day << endl;
	}*/

	Date(int year = 0,int month = 1,int day = 1)
	:_year(year)
	, _month(month)
	, _day(day)
	{}
private:
	//C++11
	//����ʱ��ȱʡ
	int _year = 0;
	int _month = 1;
	int _day = 1; 
	////ֻ������������ж���
	//static int _n;
};
ostream& operator<<(ostream& out,const Date& d)
{
	out << d._year << "/" << d._month << "/" << d._day << endl;

	return out;
}

//cout -> ostream
//cin -> istream
istream& operator>>(istream& in, Date& d)
{
	in >> d._year>>d._month >> d._day;
    return in;
}


int main()
{
	Date d1(2020, 4, 20);
	Date d2(2020, 4, 21);
	//d1.Print();
	cout << d1;
	//d1 << cout;//d1.operator<<(cout);
	cin >> d1 >> d2;
	return 0;
}
class Time
{
	friend class Date;   // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_t._hour = 1;
	}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		// ֱ�ӷ���ʱ����˽�еĳ�Ա����
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	return 0;
}