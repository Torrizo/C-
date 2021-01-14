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
	multiset<int> s;  //���Դ���ظ������ݣ������������  �������
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
	//find ���ص�һ�����ݵ�λ��
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

	//�������ݵ�Ԫ��pair����
	pair<int, int> arr[] = { { 1, 2 }, { 3, 4 } };

	//greater<>�Ǹı��key��keyС���Ǵ�keyС��key��
	map<int, int,greater<int>> mp3(arr, arr + 2);
	pair<string, int> arr2[] = { { "a", 10 }, { "bcd", 5 } };
	map<string, int,greater<string>>mp4(arr2, arr2 + 2);


	//����Ҳ������ģ�����K�Ĵ�С��ϵ�������������Ҳ�����������������
	map<int, int>::iterator it = mp3.begin();
	while (it != mp3.end())
	{
		//����д����������֮��������pair��pair��֧��cout
		//cout << *it << " ";
		//++it;

		//pair�ж����Ա������ͨ����������->����ÿһ����Ա
		cout << it->first << " -->" << it->second << endl;
		++it;
	}

	map<string, int>::iterator it2 = mp4.begin();
	while (it2 != mp4.end())
	{
		cout << it2->first << "-->" << it2->second << endl;
		++it2;
	}
	cout << "value�޸�֮��" << endl;
	it = mp3.begin();
	while (it != mp3.end())
	{
		//����д����������֮��������pair��pair��֧��cout
		//cout << *it << " ";   `
		//++it;
		it->second = 100;

		//pair�ж����Ա������ͨ����������->����ÿһ����Ա
		cout << it->first << " -->" << it->second << endl;

		//ͨ�������������޸�value�����ǲ����޸�key key��const����
		//it->first = 10;
		++it;
	}
	cout << mp4["a"] << endl;
	mp4["a"] = 1000;
	cout << mp4["a"] << endl;
	cout << "[]�޸�" << endl;
	printMap(mp4);
	//operator[]key�������߲���
	//operator[]:֧�ֲ������
	mp4["f"] = 10;
	cout << "[]����" << endl;
	printMap(mp4);


	//mp4.insert("ffff", 5);  ����д��

	//��Ҫ����pair���͵�����
	//1.��Ҫ���ù��캯��
	mp4.insert(pair<string, int>("ffff", 5));
	//2.����make_pair����
	mp4.insert(make_pair("aa", 10));
	printMap(mp4);

	mp4["q"] = 5; //key�����ڲ������쳣�����ǲ���һ����Ԫ��
	mp4.at("q");//���׳�һ���쳣


}

int main()
{
	test();
	system("pause");
	return 0;
}