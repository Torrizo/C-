#include<iostream>
#include<string>
using namespace std;
string maxnum(const string& s)
{
	int i = 0;
	int max = 0;//记录最长的数字串长度
	string ret;//记录最长的数字串
	int len = 0;//记录每个数字串长度

	while (i < s.size())
	{
		string str;
		len = 0;
		while (isdigit(s[i]))//计算每一个数字串的长度，以及记下这个数字串
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
		//养成好的习惯，开始的时候一定要判断为空的情况
		if (array == null || array.length == 0)
		{
			return 0;
		}
		//Boyer-Moore Majority Vote Algorithm算法
		//找到序列中出现次数最多的元素
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
		//判断题目的条件，看是否出现次数超过了一半
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