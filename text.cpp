#include<iostream>
#include<string>
#include<vector>
using namespace std;



//1.4个默认成员函数


void test_string1()
{
	string s1; //ok
	string s2("hello"); //ok
	string s3("hello", 2);  
	string s4(s2);  //ok
	string s5(s2, 1, 8);
	string s6(s2, 1, string::npos);
	string s7(10, 'a');

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	s1 = s7; //ok
	cout << s7 << endl;

}
//1.遍历
void test_string2()
{
	string s1("hello");
	s1 += ' ';
	s1 += "world";
	cout << s1 << endl;
	//[]+下标
	//写            每一个字符都要遍历出来
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
	}
	//读
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i]<<" ";
	}
	cout << endl;
	//迭代器
	string::iterator it = s1.begin();  //暂时可以理解为指针，但是不一定是指针。
	while (it != s1.end())
	{
		*it -= 1;
		++it;
	}
	it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
	}
	cout << endl;
}

int string2int(const string& str)
{
	int val = 0;
	// cosnt 只能读不能写
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		val *= 10;
		val += (*it - '0');
		++it;
	}
}



void test_string3()
{
	string s1("hello world");
	//倒叙遍历
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	string nums("123456");
	cout << string2int(nums) << endl;


	//迭代器分三种
	//方向：正向和反向
	//const和普通
}


void test_string4()
{
	string s1("hello world");
	string s2("hello");
	cout << s1.size() << endl;
	cout << s2.size() << endl;
	cout << s1.length() << endl;
	cout << s2.length() << endl;

	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;
	s1 += "11111";
	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;
}
void test_string5()
{
	/*string s;
	s.push_back('x');
	s.append("111111");
	s += 'x';
	s += "xxxxxx";
	cout << s << endl;*/
	string s;
	s += '1';
	s += "123";
	cout << s << endl;
	s.insert(s.begin(), '0');
	cout << s << endl;
	s.insert(2, "2");
	cout << s << endl;
	s.insert(2, "2");
	cout << s << endl;
}



int main()
{
	test_string1();
	test_string2();
	return 0;
}





class Solution
{
public:
	bool IsChar(char ch)
	{
		if ((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string reverseOnlyLetters(string S)
	{
		int begin = 0;
		int end = S.size() - 1;
		while (begin < end)
		{
			while (begin < end&&IsChar(S[begin]) == false)
			{
				++begin;
			}
			while (begin < end && IsChar(S[end]) == true)
			{
				--end;
			}

			swap(S[begin], S[end]);
		}
		return S;
		++begin;
		--end;
	}
};




class Solution
{
public:
	int firstUniqChar(string s)
	{
		int count[26] = { 0 };
		for (auto ch : s)
		{
			count[ch - 'a']++;
		}

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (count[s[i] - 'a'] == 1)
				return i;
		}
		return -1;
	}
};
