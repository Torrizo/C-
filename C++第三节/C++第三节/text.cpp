#include<iostream>
using namespace std;



class Date
{
public:
	/*Date()
	{
		_year = 1;                      
		_month = 0;                   //���߲���ͬʱ����
		_day = 0;
	}*/
	 /*  Date()
	   {
		   _year = year;
		   _month = month;
		   _day = day;
	   }*/
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date()" << this << endl;
	}
	~Date()  //��������   ��������Բ�д������������Ϊû����Դ��������
	{
		cout << "Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	//��������/�������� int/char���ᴦ��
	//�Զ�������  �������Ĺ��캯����ʼ��
};


class Stack
{
public:
	//���󴴽�ʱ�Զ�������ɳ�ʼ��
	Stack(int n = 10)
	{
		_a = (int*)malloc(sizeof(int)*n);
		_size = 0;
		_capacite = n;
	}

	void Push(int x);
	void Pop();
	size_t Size();
	//...


	//������������ڵ����Ժ����������
	~Stack()
	{
		free(_a);
		_a = nullptr;
		_size = _capacite = 0;
	}

private:
	int* _a;
	int _size;
	int _capacite;
};



int main()
{
	Date d1;//1.���ǲ�д�������� 2.ȫȱʡ��3.�޲ε� ����Ĭ�Ϲ��캯��
	//���������ο��Ե��õ�
	Date d2;
	Stack st;
	return 0;
}


class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
//Date d2(d1)
	Date(const Date& d)   //
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator==(const Date& d)
	{
		return this->_year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;
	}

private:
	int _year;
	int _month;
	int _day;

};

//bool IsDateEqual(const Date& d1, const Date& d2)
//{
//	//...
//}
//������м�����������operator���صĺ������м�������
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

//�Զ��������ǲ�����������ģ�Ҫ�þ͵�ʵ�����غ������Զ��������õ�ʱ��
//�ȼ��ڵ��õ�������غ���
int main()
{
	Date d1(2020,5,21);
	Date d2(d1);//���ÿ�������
	//����Date�Ķ���Ƚϴ�С���

	d1 == d2; //һ�㲻����ôд�ɶ��Բ��ã�
	//operator==(d1, d2);//�ɶ���ǿ�����߹���һ��
	d1 > d2;//�༭���޷������Ƚ�
	return 0;
}



class Date
{
public:
	int GetMonthDay(int year, int month)
	{
		 static int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month = 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthDay[month];
	}

	Date(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0 && month >= 1
			&& month <= 12 && _day >= 1
			&& _day <= GetMonthDay(year, month))
		{
		}
		else
		{
			cout << "�Ƿ�����" << endl;
		}
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	bool operator<(const Date& d)
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year&&_month < d._month)
			return true;
		else if (_year == d._year&&_month == d._month&&_day < d._day)
			return true;
		else
			return false;
	}
	bool operator==(const Date& d)
	{
		return this->_year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	//d1<=d2;
	//d1.operator<=(&d1,d2)
	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;//����������ʵ��  this����d1
	}
	bool operator<(const Date& d)
	{
		return !(*this <= d);
	}
	bool operator>(const Date& d)
	{
		return !(*this < d);
	}
	bool operator>=(const Date& d)
	{
		return !(*this > d || *this == d);
	}
	bool operator<=(const Date& d)
	{
		return !(*this >= d);
	}

	//d1+10//i+10 i+=10
	//d1+100
	//d1+1000
	Date operator+(int day)
	{
		Date ret = *this;//Date ret(*this)
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			//������ڲ��Ϸ�������Ҫ���½�λ
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;
			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}


	Date operator+=(int day)
	{
		_day += day;
		while (day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}

		return *this;
	}








	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;
	d1.Print();

	Date d2(2020,4,20);
	d2.Print;

	Date d3(2021, 4, 20);
	d3.Print;

	cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;


	return 0;
}