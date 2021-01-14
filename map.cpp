#include<iostream>
#include<map>
#include<functional>
#include<string>
#include<set>
using namespace std;


void test()
{
	multimap<int,int> mp;
	mp.insert(make_pair(1, 1));
	mp.insert(make_pair(1, 2));
	mp.insert(make_pair(1, 3));
	mp.insert(make_pair(1, 4));
	mp.insert(make_pair(1, 5));
	mp.insert(make_pair(1, 6));
	mp.insert(make_pair(1, 7));
	mp.insert(make_pair(1, 8));

	auto it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << "-->" << it->second << endl;
		++it;
	}

}



void test()
{
	multiset<int> s;  //可以存放重复的数据，遍历是有序的  中序遍历
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(6);
	s.insert(1);
	s.insert(1);

	for (const auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	pair<multiset<int>::iterator,multiset<int>::iterator> it = s.equal_range(1);
	multiset<int>::iterator start = it.first;
	while (start != it.second)
	{
		cout << *start << " ";
		++start;
	}
	cout << endl;
	//find 返回第一个数据的位置
	start = s.find(1);
	cout << *start << endl;

	cout << s.count(1) << endl;
}

template <class K,class V>
void printMap(const map<K, V, less<K>>& mp)
{
	for (const auto& p : mp)
	{
		cout << p.first << "-->" << p.second << endl;
	}
}
template <class K, class V>
void printMap(const map<K, V, greater<K>>& mp)
{
	for (const auto& p : mp)
	{
		cout << p.first << "-->" << p.second << endl;
	}
}
void test()
{
	map<int, int> mp;
	map<string, int> mp2;

	//插入数据单元：pair类型
	pair<int, int> arr[] = { { 1, 2 }, { 3, 4 } };

	//greater<>是改变从key大到key小还是从key小到key大
	map<int, int,greater<int>> mp3(arr, arr + 2);
	pair<string, int> arr2[] = { { "a", 10 }, { "bcd", 5 } };
	map<string, int,greater<string>>mp4(arr2, arr2 + 2);


	//遍历也是有序的，按照K的大小关系有序遍历，本质也是搜素树的中序遍历
	map<int, int>::iterator it = mp3.begin();
	while (it != mp3.end())
	{
		//错误写法：解引用之后类型是pair，pair不支持cout
		//cout << *it << " ";
		//++it;

		//pair有多个成员，可以通过迭代器的->访问每一个成员
		cout << it->first << " -->" << it->second << endl;
		++it;
	}

	map<string, int>::iterator it2 = mp4.begin();
	while (it2 != mp4.end())
	{
		cout << it2->first << "-->" << it2->second << endl;
		++it2;
	}
	cout << "value修改之后" << endl;
	it = mp3.begin();
	while (it != mp3.end())
	{
		//错误写法：解引用之后类型是pair，pair不支持cout
		//cout << *it << " ";   `
		//++it;
		it->second = 100;

		//pair有多个成员，可以通过迭代器的->访问每一个成员
		cout << it->first << " -->" << it->second << endl;

		//通过迭代器可以修改value，但是不能修改key key是const类型
		//it->first = 10;
		++it;
	}
	cout << mp4["a"] << endl;
	mp4["a"] = 1000;
	cout << mp4["a"] << endl;
	cout << "[]修改" << endl;
	printMap(mp4);
	//operator[]key不存在走插入
	//operator[]:支持插入操作
	mp4["f"] = 10;
	cout << "[]插入" << endl;
	printMap(mp4);


	//mp4.insert("ffff", 5);  错误写法

	//需要插入pair类型的数据
	//1.需要调用构造函数
	mp4.insert(pair<string, int>("ffff", 5));
	//2.调用make_pair函数
	mp4.insert(make_pair("aa", 10));
	printMap(mp4);

	mp4["q"] = 5; //key不存在不会抛异常，而是插入一个新元素
	mp4.at("q");//会抛出一个异常


}

int main()
{
	test();
	system("pause");
	return 0;
}