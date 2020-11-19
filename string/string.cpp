#include <assert.h>
#include <string>
#include <iostream>
using namespace std;

class String
{
public:
	//����
	String(char* str = "")
	{
		_size = strlen(str);
		_capacity = _size;
		_ptr = new char[_size + 1];
		strcpy(_ptr, str);
	}
	//��������
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
		//���ù��캯��
		String tmp(str._ptr);
		Swap(tmp);
	}

	//String& operator=(const String& str)
	//{
	//	if (this != &str)
	//	{
	//		//���ռ䣬�������ͷ�ԭ�пռ�
	//		char* tmp = new char[str._capacity + 1];
	//		strcpy(tmp, str._ptr);
	//		delete[] _ptr;
	//		_ptr = tmp;
	//		_size = str._size;
	//		_capacity = str._capacity;
	//	}
	//	return *this;
	//}

	//��ֵ
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

	//����
	~String()
	{
		if (_ptr)
		{
			delete[] _ptr;
			_ptr = nullptr;
			_size = _capacity = 0;
		}
	}

	//β��
	void push_back(const char& ch)
	{
		/*
		//�ж�����
		if (_size == _capacity)
		{
			//����
			size_t newCapcity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapcity);
		}

		//����
		_ptr[_size++] = ch;
		//�����ַ����Ľ������
		_ptr[_size] = '\0';
		*/
		insert(_size, ch);
	}

	void reserve(size_t n)
	{
		if (n > _capacity)
		{
			//���µĿռ�
			char* tmp = new char[n + 1];
			////����ԭʼ�ռ�����
			//strcpy(tmp, _ptr);
			for (int i = 0; i <= _size; ++i)
			{
				tmp[i] = _ptr[i];
			}
			//�ͷ�ԭ�пռ�
			delete[] _ptr;
			_ptr = tmp;
			//��������
			_capacity = n;
		}
	}

	size_t size() const
	{
		return _size;
	}


	//�ɶ���д  str[i]
	char& operator[](size_t pos)
	{
		//�ж�λ���Ƿ�Խ��
		assert(pos < _size);
		return _ptr[pos];
	}

	const char& operator[](size_t pos) const
	{
		//�ж�λ���Ƿ�Խ��
		assert(pos < _size);
		return _ptr[pos];
	}

	//����������������Ԫ�ص�һ�ֻ���
	//������������ָ��
	//���ò����� ���������ƶ��� �������Ľ����ã� ���������ж�
	//string��������ʵ�֣� char*
	typedef char* iterator;
	typedef const char* const_iterator;

	
	//begin:��һ��Ԫ�ص�λ��
	iterator begin()
	{
		return _ptr;
	}

	//end:���һ��Ԫ�ص���һ��λ��
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
	// 1. n <= _size: ֻ��Ҫ�޸�size
	// 2. _size < n <= _capacity: ��ֵch--> [_size, _capcity), �޸�size
	// 3. n > _capacity: ���ݣ� ��ֵ�� �޸�size
	void resize(size_t sz, char ch = '\0')
	{
		if (sz > _capacity)
		{
			//����
			reserve(sz);
		}
		if (sz > _size)
		{
			//��ֵ
			memset(_ptr + _size, ch, sz - _size);
		}

		_size = sz;
		_ptr[_size] = '\0';
	}

	void Append(const char* str)
	{
		/*
		//��ȡ�����ַ����ĳ���
		int len = strlen(str);
		//ʣ��ռ��Ƿ���Դ洢�����ַ���
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		//β���ַ���
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
		//�жϱ߽�
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newCapacity = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newCapacity);
		}
		//�ƶ�Ԫ�أ� �Ӻ���ǰ�ƶ�
		size_t end = _size;
		while (end > pos)
		{
			_ptr[end] = _ptr[end - 1];
			--end;
		}
		/*
		//posΪ0ʱ����ѭ��
		while (end >= pos)
		{
			_ptr[end + 1] = _ptr[end];
			--end;
		}
		*/
		//�����µ��ַ�
		_ptr[pos] = ch;

		//����µĽ������
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
		//�ƶ�Ԫ��
		// _size --->  _size + len   pos ---> pos + len
		size_t end = _size + len;
		// end: [pos + len, _size + len]
		while (end > pos + len - 1)
		{
			_ptr[end] = _ptr[end - len];
			--end;
		}
		//�����ַ���
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
		//ɾ������ǰ����ƶ�
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
		//δ�ҵ�
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
	//size: ��Ч�ַ��ĸ���
	size_t _size;
	//capacity: ���Դ�ŵ������Ч�ַ�����
	size_t _capacity;
	//��̬��Ա�������ʼ��
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
//	//ͷɾ
//	s.erase(0, 1);
//	//βɾ
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
//	//insert(pos = 0): ͷ��
//	s.insert(0, '5');  // 5
//	//s.insert(0, '4');  // 45
//	s.insert(1, 'a');  // 4a5
//	//insert(pos = size): β��
//	s.insert(3, '6');  // 4a56
//	//posԽ�磺0 <= pos <= size
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




