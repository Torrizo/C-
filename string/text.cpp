#include<iostream>
#include<assert.h>
using namespace std;



template<class T>
class vector
{
public:
	vector()
		:_a(nullptr)
		, _size(0)
		, _capacity(0)
	{}
	~vector()
	{
		delete[] _a;
		_a = nullptr;
		_size = _capacity = 0;
	}
	//类里面声明
	void push_back(const T& x);
	void push_pop(const T& x);
	size_t size()
	{
		return _size;
	}

	T& operator[] (size_t i) //临时对象具有常性
	{
		assert(i < _size);
		return _a[i];
	}
private:
	T* _a;
	size_t _size;
	size_t _capacity;
};


template<class T>
void vector<T>::push_back(const T& x)
{
	//如果空间不够需要增容
	if (_size == _capacity)
	{
		size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
		T* tmp = new T[newcapacity];
		if (_a)
		{
			memcpy(tmp, _a, sizeof(T)*_size);
			delete[] _a;
		}
		_a = tmp;
		_capacity = newcapacity;
	}
	_a[_size] = x;
	++_size;
}

template<class T>
void vector<T>::push_pop(const T& x)
{

}


int main()
{
	vector<int> v; //vector<int>是类型
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (size_t i = 0; i < v.size(); ++i)
	{
		//v[i] *= 2;
	}
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}

int Add(int left, int right)
{
	return left + right;
}


template<class T>
T Add(const T& left, const T& reight)
{
	return left + right;
}

int mian()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	//隐式实例化（T的类型是编译器自己推导的）
	Add(a1, a2);
	Add(d1, d2);


	Add(a1, (int)d1);
	Add<int>(a1, d2);


	Add(1, 2);     //与非模板函数
	Add<int>(1, 2);//调用编译器特化的Add版本
	return 0;
}


#include <string>



int mian()
{
	string s1;
	string s2("hello");
	string s3(s2);
	string s4(10, 'a');
	string s5 = "hello";//还是拷贝构造
	string s6 = s2;


	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	return 0;

}

int main()
{
	/*string s("12345");
	s.push_back('6');
	s.append("789");
	s += '1';
	s += "1111";*/

	//实现字符串转成整形
	string s("12345");
	int val = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		val *= 10;
		val += s[i] - '0';
	}
	return 0;
}