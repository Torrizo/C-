#include <iostream>
#include <vector>
using namespace std;

void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2(v1);
	for(size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for(size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);
	v3.push_back(30);
	v3.push_back(40);

	v1 = v3;
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}
 

void test_vector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//1.  �����޸�����
	//1.operator[] + size
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	//2.������
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
	}
	cout << endl;


	//3.��Χfor ��>���������滻�ɵ�������ʽ����֧�ֵ�
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}
void print_vector(vector<int>& vt)
{
	//ֻ��
	vector<int>::const_iterator it = vt.begin();
	while (it != vt.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

//�������͵ĵ�����
void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//��ͨ���������  �ɶ���д
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it *= 2;
		cout << *it << " ";
		++it;
	}
	cout << endl;
	print_vector(v);

	//reverse ����
	//reserve ����
	vector<int>:: reverse_iterator rit = v.rbegin();  //���������
	while (rit !=v.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}


void test_vector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);



	cout << v.size() << endl;
	cout << v.capacity () << endl;
	size_t sz;
	std::vector<int> foo;
	//foo.reserve(1067);//��ǰ���ÿռ�Ͳ�������
	foo.resize(1067);//���ݲ���ֱ�ӳ�ʼ��
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i<100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	//v[4] = 5;
	v.at(4) = 5;
}
void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	v.insert(v.begin(), 0);
	v.insert(v.begin(), -1);//ͷ��

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.erase(v.begin());//ͷɾ

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

}

void text_vector7()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(5);
	v.push_back(2);
	v.push_back(5);
	v.push_back(50);
	v.push_back(4);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//Ҫ��ɾ��5
	//v.erase(v.begin() + 1);     ɾ�������±�Ϊ1��λ�õ�ֵ
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos != v.end())
	{
		v.erase(pos);
	}

	for (auto e : v)
	{
		cout << e << endl;
	}
	cout << endl;
}

//int main()
//{
//	size_t sz;
//	std::vector<int> foo;
//	sz = foo.capacity();
//	std::cout << "making foo grow:\n";
//	for (int i = 0; i<100; ++i) {
//		foo.push_back(i);
//		if (sz != foo.capacity()) {
//			sz = foo.capacity();
//			std::cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}


//class Solution
//{
//public:
//	int singleNumber(vector<int>& nums)
//	{
//		cout << nums.size << endl;
//		for (int i = 0; i < nums.size;++i)
//
//		vector<int>::iterator pos = find(nums.begin(), nums.end(), num);
//		if (pos != nums.end())
//		{
//			nums.erase(pos);
//		}
//	}
//};



int main()
{
	test_vector6();
	system("pause");
	return 0;
}