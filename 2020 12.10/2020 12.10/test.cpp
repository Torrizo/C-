#include<iostream>
using namespace std;

int test(int dec)
{
    /*int result = 0, temp = dec, j = 1;
	while (temp){
		result = result + j * (temp % 2);
		temp = temp / 2;
		j = j * 10;
	}*/
	//unsigned int c = 0; // ������
	//while (result >0)
	//{
	//	if ((result & 1) == 1) // ��ǰλ��1
	//		++c; // ��������1
	//	result >>= 1; // ��λ
	//}
	//return c;
	//return result;
	int count = 0;
	//int result = 5;
	while(dec)
	{
	    dec &= (dec- 1);
		count++;
	}
	return count;
}

int main()
{
	cout << test(5) << endl;;
	system("pause");
	return 0;
}