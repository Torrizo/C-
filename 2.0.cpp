#include <assert.h>
#include <iostream>
using namespace std;
template < class T >
class Vector   //vector占12个字节
{
public:
	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _endOfstorage(nullptr)
		();
	size_t size() const
	{
		return _finish - _start;
	}
	size_t capacity() const
	{
		return _endOfstorage - _start;
	}

	void push_back(const T& val)
	{
		//1.检查容量
		if (_finish == _endOfstorage)
		{
			size_t newCapacity = _start == nullptr ? 1 : 2 * capacity();
			reserve newCapacity;
		}
		//2.尾插
		*_finish = val;

		//3.更新size
		++_finish;

	}


	void reserve(size_t n)
	{
		//只增加容量
		if (n > capacity)
		{
			size_t sz = size();
			//1.开空间
			T*tmp = new T[n];
			//2.内容拷贝
			memcpy(tmp, _start, sizeof(T)*size());
			//3.释放原有空间
			delete[] _start;
			//4.更新成员变量
			_start = tmp;
			_finish = _start + sz;
			_endOfstorage = _start + n;
		}
	}
	operator[] (size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}
	const operator[] (size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}
	operator[] (size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}

	typedef T* iteratro;
	typedef T* const_iteratro;

	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	const_iterator begin() const
	{
		return _start;
	}
	const_iterator end() const
	{
		return _finish;
	}

	void resize(size_t n, const T& val = T())
	{
		if (n > capacity())
		{
			reserve(n);
		}
		if (n > size())
		{
			iterator it = end();
			while (it != _start + n)
			{
				*it = val;
				++it;
			}
		}
		_finish = _strat + n;
	} 

	void insert(iterator pos, coust T& val)
	{
		//获取pos 和 begin的偏移量
		int offset = pos - _start;
		assert(pos >= begin() && pos <= end());
		//检查容量
		if (_finish == _endOfstorage)
		{
			size_t newCapacity = (_start == nullptr) ? 1 : 2 * capacity;
			//发生增容，迭代器失效
			reserve(newCapacity)
		}
		//更新pos  //增容会引起迭代器失效
		pos = _start + offset;
		//元素移动
		iterator it = end();
		while (it != pos)
		{
			*it = *(it - 1);
			--it;
		}

		//插入
		*pos = val;
 
		//更新size
		++_finish; 
	}

	void erase(iterator pos)
	{
		assert(pos >= begin() && pos < end());
		iterator it = pos +1;
		while (it!= end())
		{
			*(it - 1) = *it;
		}
	}
private;
	T* _start;//首元素的地址
	T* _finish;//尾元素下一个位置
    T* _endOfstorage;
};


void pruntFor(const Vector<int>& v)
{
	for (const auto e : v)
	{
		cout << e << endl;
	}
	cout << endl;
}

void printiterator(const Vector<int>& v)
{
	Vector<int>::iteratro it = v.begin();
	while (it != v.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;
}

void printVet(const Vector<int>& vec)
{
	for (int i = 0; i <= vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
}

void test()
{
	Vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.resize(9);
	printiterator(v);
	v.resize(4, 20);//
	printiterator(v);
	v.resize(6, 30); //1234  30 30 

	/*for (int i = 0; i < v.size; ++i)
	{
		cout << v[i] << endl;
	}
*/
}
int main()
{
	test();
	system("pasue");
	return 0;
}

