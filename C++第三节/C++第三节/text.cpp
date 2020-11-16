#include<iostream>
using namespace std;



class Date
{
public:
	/*Date()
	{
		_year = 1;                      
		_month = 0;                   //三者不能同时存在
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
	~Date()  //析构函数   日期类可以不写析构函数，因为没有资源用来清理
	{
		cout << "Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	//内置类型/基本类型 int/char不会处理
	//自定义类型  调用它的构造函数初始化
};


class Stack
{
public:
	//对象创建时自动调用完成初始化
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


	//对象的生命周期到了以后，完成清理工作
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
	Date d1;//1.我们不写编译生成 2.全缺省的3.无参的 —》默认构造函数
	//—》不传参可以调用的
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
//运算符有几个操作数，operator重载的函数就有几个参数
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

//自定义类型是不能用运算符的，要用就得实现重载函数，自定义类型用的时候
//等价于调用的这个重载函数
int main()
{
	Date d1(2020,5,21);
	Date d2(d1);//调用拷贝构造
	//比如Date的对象比较大小相等

	d1 == d2; //一般不会这么写可读性不好；
	//operator==(d1, d2);//可读性强，二者功能一样
	d1 > d2;//编辑器无法自主比较
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
			cout << "非法日期" << endl;
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
		return *this < d || *this == d;//复用上面来实现  this就是d1
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
			//如果日期不合法，就需要往月进位
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