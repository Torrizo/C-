#include<iostream>
#include<string>
using namespace std;
string maxnum(const string& s)
{
	int i = 0;
	int max = 0;//��¼������ִ�����
	string ret;//��¼������ִ�
	int len = 0;//��¼ÿ�����ִ�����

	while (i < s.size())
	{
		string str;
		len = 0;
		while (isdigit(s[i]))//����ÿһ�����ִ��ĳ��ȣ��Լ�����������ִ�
		{
			str += s[i];
			len++;
			i++;
		}
		if (len > max)
		{
			ret = str;
		}
		i++;
	}
	return ret;

}

public class Solution 
{
	public int MoreThanHalfNum_Solution(int[] array) 
	{
		//���ɺõ�ϰ�ߣ���ʼ��ʱ��һ��Ҫ�ж�Ϊ�յ����
		if (array == null || array.length == 0)
		{
			return 0;
		}
		//Boyer-Moore Majority Vote Algorithm�㷨
		//�ҵ������г��ִ�������Ԫ��
		int most = array[0];
		int count = 1;
		for (int i = 1; i<array.length; i++)
		{
			count = most == array[i] ? count + 1 : count - 1;
			if (count == 0)
			{
				most = array[i];
				count = 1;
			}
		}
		//�ж���Ŀ�����������Ƿ���ִ���������һ��
		count = 0;
		for (int i = 0; i<array.length; i++)
		{
			if (most == array[i])
			{
				count++;
			}
		}
		return count>array.length / 2 ? most : 0;
	}
}


int main()
{
	string str = "asd5a41d3s468d5a1sdas654d685as4d65a4s9846541321546adsdas";
	cout << maxnum(str) << endl;
	system("pause");
	return 0;
}