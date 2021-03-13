#include<iostream>
#include<vector>
using namespace std;
class bitMap
{
public:
	//通过数据范围u，确定需要开的空间大小
	bitMap(int range)
	{
		_bitMap.resize(range / 32 + 1, 0);
	}
	//存放信息
	void set(int data)
	{
		//计算位置
		//1.计算整数位置 ：data /32 》》 5
		int idx = data / 32;
		//计算bit位置 data%32
		int bitNum = data % 32;
		//3.对应的bit位置：bitMap【idx】 | 1 << bitNum
		_bitMap[idx] |= 1 << bitNum;
	}
	//查找信息
	int test(int data)
	{
		//计算位置
		//1.整数位置
		int idx = data / 32;
		//2.bit位置
		int bitNum = data % 32;
		return (_bitMap[idx] >> bitNum) & 1;
	}
	//删除信息
	void reset(int data)
	{
		//整数位置
		int idx = data / 32;
		//bit位置
		int bitNum = data % 32;
		_bitMap[idx] &= ~(1 << bitNum);
	}
private:
	vector<int> _bitMap;
	//size_t _size;
};

void test()
{
	//存放100数据的二值信息（0-99）
	//范围在0-99之间的数据
	bitMap b(100);
	b.set(1);
	b.set(32);
	b.set(96);
	b.set(99);
}
int main()
{
	test();
	system("pause");
	return 0;
}