#include<iostream>
#include<list>
using namespace std;

void test_listl()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

	list<int>::iterator it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	list<int> lt2(lt1);
	print_list(lt2);
	list<int>lt3;
	lt3.push_back(10);
	lt3.push_back(20);
	lt3.push_back(30);
	lt3.push_back(40);

	lt1 = lt3;
	//只要一个容器支持迭代器，就可以使用范围for的操作
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::reverse_iterator retl = lt1.rbegin();
	while (ritl != lt1.rend())
	{
		cout << *ritl << " ";
		++ritl;
	}
	cout << endl;
}

int mian()
{
	test_list1();

	return  0;
}