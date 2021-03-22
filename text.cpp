#include<iostream>
#include<set>
#include<functional>
using namespace std;
template <class T>
void printSet(const set<T>& set)
{
	for (const auto& e : set)
	{
		cout << e << " ";
	}
	cout << endl;
}


//void test()   //查找
//{
//	set<int> s;
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(5);
//	s.insert(6);
//	s.insert(7);
//	s.insert(8);
//	auto it = s.find(5);
//	cout << (it == s.end()) << endl;
//	it = s.find(10);
//	cout << (it == s.end()) << endl;
//
//	cout << s.count(5) << endl;
//	cout << s.count(10) << endl;
//
//	pair<set<int>::iterator, set<int>::iterator> p = s.equal_range(5);
//	cout << *(p.first) << endl;
//	cout << *(p.second) << endl;
//
//}
//void test()   //插入元素
//{
//	
//	set<int> s;
//
//	//插入元素：成功-->返回值：bool：true，iterator：插入新元素的位置
//	pair < set<int>::iterator, bool > kvRet = s.insert(1);
//	bool ret = kvRet.second;
//	cout << ret << endl;
//	set<int>::iterator it = kvRet.first;
//	cout << *it << endl;
//
//
//	//重复元素插入失败，返回0，但是查询依然可以查到 iterator已经存在的元素位置
//	kvRet = s.insert(1);
//	ret = kvRet.second;
//	cout << ret << endl;
//	it = kvRet.first;
//	cout << *it << endl;
//
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(5);
//	s.insert(6);
//	s.insert(7);
//	s.insert(8);
//
//	it = s.begin();
//	//insert(iterator, value); iterator只是参考作用不一定会真的吧值放在那个位置
//	it = s.insert(it, 12);
//	cout << *it << endl;
//	++it;
//	//cout << *it << endl;
//	//不会插入新的元素，所有元素已经存在
//	s.insert(s.begin(), s.end());
//	set<int> s2;
//	//插入所有元素
//	s2.insert(s.begin(), s.end());
//}



//void test()  //删除
//{
//	set<int> s;
//	pair < set<int>::iterator, bool > kvRet = s.insert(1);
//	bool ret = kvRet.second;
//	set<int>::iterator it = kvRet.first;
//	s.insert(2);
//	s.insert(3);
//	s.insert(4);
//	s.insert(5);
//	s.insert(6);
//	s.insert(7);
//	s.insert(8);
//	while (it != s.end())
//	{
//		cout << *it << endl;
//		++it;
//	}
//	
//	s.erase(3);
//	printSet(s);
//	s.erase(s.begin());
//	printSet(s);
//	s.erase(s.begin(), s.end());
//	printSet(s);
//
//	printSet(s);
//	s.clear();
//	printSet(s);
//}



//void test()   //遍历元素
//{
//	set<int> s;
//	int arr[] = { 10, 25, 13, 4, 55, 6 };
//	set<int> s2(arr, arr + sizeof(arr) / sizeof(arr[0]));
//	set<int>copy(s2);
//	//遍历有序
//	set<int>::iterator sit = s2.begin();
//	while (sit != s2.end())
//	{
//		cout << *sit << " ";
//		//set不能修改   而且set的值不能重复，重复的话只会显示一个值
//		//*sit = 10;
//		++sit;
//	}
//	cout << endl;
//
//
//	//遍历顺序是递减的
//	set<int, greater<int>> s3(arr, arr + sizeof(arr) / sizeof(arr[0]),greater<int>());
//	set<int, greater<int>>::iterator sit2 = s3.begin();
//	while(sit2 != s3.end())
//	{
//		cout << *sit2 << " ";
//		++sit2;
//	}
//	cout << endl;
//
//	//反向输出
//	set<int>::reverse_iterator rit = s2.rbegin();
//	while (rit != s2.rend())
//	{
//		cout << *rit << " ";
//		++rit;
//	}
//	cout << endl;
//}


//int main()
//{
//	test();
//	system("pause");
//	return 0;
//} 