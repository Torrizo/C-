#include<iostream>
#include<vector>
using namespace std;
class bitMap
{
public:
	//ͨ�����ݷ�Χu��ȷ����Ҫ���Ŀռ��С
	bitMap(int range)
	{
		_bitMap.resize(range / 32 + 1, 0);
	}
	//�����Ϣ
	void set(int data)
	{
		//����λ��
		//1.��������λ�� ��data /32 ���� 5
		int idx = data / 32;
		//����bitλ�� data%32
		int bitNum = data % 32;
		//3.��Ӧ��bitλ�ã�bitMap��idx�� | 1 << bitNum
		_bitMap[idx] |= 1 << bitNum;
	}
	//������Ϣ
	int test(int data)
	{
		//����λ��
		//1.����λ��
		int idx = data / 32;
		//2.bitλ��
		int bitNum = data % 32;
		return (_bitMap[idx] >> bitNum) & 1;
	}
	//ɾ����Ϣ
	void reset(int data)
	{
		//����λ��
		int idx = data / 32;
		//bitλ��
		int bitNum = data % 32;
		_bitMap[idx] &= ~(1 << bitNum);
	}
private:
	vector<int> _bitMap;
	//size_t _size;
};

void test()
{
	//���100���ݵĶ�ֵ��Ϣ��0-99��
	//��Χ��0-99֮�������
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