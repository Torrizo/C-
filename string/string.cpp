#include <assert.h>
#include <string>
#include <iostream>
using namespace std;

class String
{
public:
	//构造
	String(char* str = "")
	{
		_size = strlen(str);
		_capacity = _size;
		_ptr = new char[_size + 1];
		strcpy(_ptr, str);
	}
	//拷贝构造
	/*String(const String& str)
		:_ptr(new char[str._capacity + 1])
		, _size(str._size)
		, _capacity(str._capacity)
		{
		strcpy(_ptr, str._ptr);
		}
		*/
	String(const String& str)
		:_ptr(nullptr)
		, _size(0)
		, _capacity(0)
	{
		//复用构造函数
		String tmp(str._ptr);
		Swap(tmp);
	}

	//String& operator=(const String& str)
	//{
	//	if (this != &str)
	//	{
	//		//开空间，拷贝，释放原有空间
	//		char* tmp = new char[str._capacity + 1];
	//		strcpy(tmp, str._ptr);
	//		delete[] _ptr;
	//		_ptr = tmp;
	//		_size = str._size;
	//		_capacity = str._capacity;
	//	}
	//	return *this;
	//}

	//赋值
	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}

	void Swap(String& str)
	{
		swap(_ptr, str._ptr);
		swap(_size, str._size);
		swap(_capacity, str._capacity);
	}

	//析构
	~String()
	{
		if (_ptr)
		{
			delete[] _ptr;
			_ptr = nullptr;
			_size = _capacity = 0;
		}
	}

	//尾插
	void push_back(const char& ch)
	{
		/*
		//判断容量
		if (_size == _capacity)
		{
			//增容
			size_t newCapcity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapcity);
		}

		//插入
		_ptr[_size++] = ch;
		//加上字符串的结束标记
		_ptr[_size] = '\0';
		*/
		insert(_size, ch);
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//开新的空间
			char* tmp = new char[n + 1];
			////拷贝原始空间内容
			//strcpy(tmp, _ptr);
			for (int i = 0; i <= _size; ++i)
			{
				tmp[i] = _ptr[i];
			}
			//释放原有空间
			delete[] _ptr;
			_ptr = tmp;
			//更新容量
			_capacity = n;
		}
	}

	size_t size() const
	{
		return _size;
	}


	//可读可写  str[i]
	char& operator[](size_t pos)
	{
		//判断位置是否越界
		assert(pos < _size);
		return _ptr[pos];
	}

	const char& operator[](size_t pos) const
	{
		//判断位置是否越界
		assert(pos < _size);
		return _ptr[pos];
	}

	//迭代器：访问容器元素的一种机制
	//操作：类似于指针
	//常用操作： 迭代器的移动， 迭代器的解引用， 迭代器的判断
	//string迭代器的实现： char*
	typedef char* iterator;
	typedef const char* const_iterator;

	
	//begin:第一个元素的位置
	iterator begin()
	{
		return _ptr;
	}

	//end:最后一个元素的下一个位置
	iterator end()
	{
		return _ptr + _size;
	}

	const_iterator begin() const
	{
		return _ptr;
	}

	const_iterator end() const
	{
		return _ptr + _size;
	}
	
	//resize(n, ch)
	// 1. n <= _size: 只需要修改size
	// 2. _size < n <= _capacity: 赋值ch--> [_size, _capcity), 修改size
	// 3. n > _capacity: 增容， 赋值， 修改size
	void resize(size_t sz, char ch = '\0')
	{
		if (sz > _capacity)
		{
			//增容
			reserve(sz);
		}
		if (sz > _size)
		{
			//赋值
			memset(_ptr + _size, ch, sz - _size);
		}

		_size = sz;
		_ptr[_size] = '\0';
	}

	void Append(const char* str)
	{
		/*
		//获取插入字符串的长度
		int len = strlen(str);
		//剩余空间是否可以存储整个字符串
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		//尾插字符串
		strcpy(_ptr + _size, str);
		_size += len;
		*/
		insert(_size, str);
	}

	String& operator+=(const char& ch)
	{
		push_back(ch);
		return *this;
	}
	String& operator+= (const char* str)
	{
		Append(str);
		return *this;
	}

	String& operator+=(const String& str)
	{
		Append(str._ptr);
		return *this;
	}

	void insert(size_t pos, const char& ch)
	{
		//判断边界
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapacity);
		}
		//移动元素： 从后向前移动
		size_t end = _size;
		while (end > pos)
		{
			_ptr[end] = _ptr[end - 1];
			--end;
		}
		/*
		//pos为0时，死循环
		while (end >= pos)
		{
			_ptr[end + 1] = _ptr[end];
			--end;
		}
		*/
		//插入新的字符
		_ptr[pos] = ch;

		//添加新的结束标记
		_ptr[++_size] = '\0';
	}

	void insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		int len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		//移动元素
		// _size --->  _size + len   pos ---> pos + len
		size_t end = _size + len;
		// end: [pos + len, _size + len]
		while (end > pos + len - 1)
		{
			_ptr[end] = _ptr[end - len];
			--end;
		}
		//插入字符串
		memcpy(_ptr + pos, str, len * sizeof(char));

		_size += len;
	}

	void erase(size_t pos, size_t len)
	{
		assert(pos < _size);

		if (pos + len >= _size)
		{
			_size = pos;
			_ptr[_size] = '\0';
			return;
		}
		//删除，从前向后移动
		size_t start = pos + len;
		while (start < _size)
		{
			_ptr[pos++] = _ptr[start++];
			/*
			_ptr[start - len] = _ptr[start];
			++start;
			*/
		}
		_size -= len;
		_ptr[_size] = '\0';

	}

	size_t find(const char& ch, size_t pos = 0)
	{
		for (size_t i = pos; i < _size; ++i)
		{
			if (_ptr[i] == ch)
				return i;
		}
		//未找到
		return npos;
	}

	size_t find(const char* str, size_t pos = 0)
	{
		char* start = strstr(_ptr + pos, str);
		if (start)
		{
			return start - _ptr;
		}
		return npos;
	}

	const char* c_str() const
	{
		return _ptr;
	}

private:
	char* _ptr;
	//size: 有效字符的个数
	size_t _size;
	//capacity: 可以存放的最大有效字符个数
	size_t _capacity;
	//静态成员在类外初始化
	static const size_t npos;
};

const size_t String::npos = -1;

void printString(const String& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		const char& ch = str[i];
		cout << ch << " ";
	}
	cout << "end" << endl;
}

ostream& operator<<(ostream& _cout, const String& str)
{
	/*_cout << str.c_str();*/
	for (const auto& ch : str)
		cout << ch;
	return _cout;
}
istream& operator>>(istream& _cin, String& str)
{
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '\n')
			return _cin;
		str += ch;
	}

	return _cin;
}

#include <string>

void test()
{
	String s;
	cin >> s;
}

int main()
{
	test();
	return 0;
}

//void test()
//{
//	string s = "123";
//	s.resize(6);
//	cout << s << "end" << endl;
//	String s2 = "123";
//	s2.resize(6);
//	cout << s2 << "end" << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//	
//}
//void test()
//{
//	String s = "123456789";
//	size_t pos = s.find('3');
//	pos = s.find("78");
//	pos = s.find("356");
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//void test()
//{
//	String s = "1234567890";
//	//头删
//	s.erase(0, 1);
//	//尾删
//	s.erase(8, 1);
//
//	s.erase(4, 2);
//	s.erase(0, 6);
//}
//
//int main()
//{
//	test();
//	return 0;
//
//}



//void test()
//{
//	String s;
//	s += '1';
//	s += "23";
//	s += 'a';
//	s += "4567890";
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//void test()
//{
//	String s = "000";
//	s.insert(0, "456");
//	s.insert(3, "789");
//	s.insert(3, "abc");
//	s.insert(12, "def");
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//void test()
//{
//	String s = "ab";
//	//insert(pos = 0): 头插
//	s.insert(0, '5');  // 5
//	//s.insert(0, '4');  // 45
//	s.insert(1, 'a');  // 4a5
//	//insert(pos = size): 尾插
//	s.insert(3, '6');  // 4a56
//	//pos越界：0 <= pos <= size
//	//s.insert(6, '8');
//}
//
//int main()
//{
//	test();
//	return 0;
//}

//void test()
//{
//	String str = "123";
//	str.operator+=('4');
//	str += '4';
//
//	str.operator+=("567");
//	str += "567";
//
//	String str2 = "abc";
//	str.operator+=(str2);
//	str += str2;
//
//}
//
//int main()
//{ 
//	test();
//	return 0;
//}

//void test()
//{
//	String str;
//	str.Append("12345678");
//	str.Append("12345678");
//	str.Append("12345678");
//
//}
//
//int main()
//{
//	test();
//	return 0;
//}




