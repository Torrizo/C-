#include<iostream>
using namespace std;

//class Solution
//{
//public:
//	Solution Print()
//	{
//		cout << " Solution()" << endl;
//	}
//	int Sum_Solutin(int n)
//	{
//		cout << "~Solution()" << endl;
//		return n;
//	}
//};
//int main()
//{
//	Solution s1;
//	s1.Sum_Solutin(10); //S1������������һ��
//
//
//	//Solution();//��������
//	Solution().Sum_Solutin(10);   //ֻ����һ�л�ʹ������������󣬱��˲���Ҫʹ��
//                                   //������������һ��
//
//
//	return 0;
//}

//int main()
//{
//	static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	int year; int month; int day;
//	// �������Բ��Ͻ�������  ��ctrl+c����
//	while (cin >> year >> month >> day)
//	{
//		int n = 0;
//		for (int i = 1; i < month; ++i)
//		{
//			n += monthDays[i];
//		}
//		n += day;
//		if (month > 0 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//		{
//			n += 1;
//		}
//		cout << n << endl;
//	}
//	return 0;
//}



class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};
class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
};
class C
{
public:
	C()
	{
		cout << "C()" << endl;
	}
	~C()
	{
		cout << "~C()" << endl;
	}
};
class D
{
public:
	D()
	{
		cout << "D()" << endl;
	}
	~D()
	{
		cout << "~D()" << endl;
	}
};
C c;
int main()
{
	A a;
	B b;
	static D d;
}
//  C  D  A  B
// `B `A `D `C  //��̬�ľֲ�����ֻ�����ߵ�ʱ�Ż��ʼ��







//ȫ�ֱ��� ���� ���ݶ�       main ����֮ǰ�ͳ�ʼ��   ���Ķ���ʹ�ã���������ȫ�ֵ�

//�Ǿ�̬�ľֲ����� ���� ջ

//��̬�ֲ����� ���� ���ݶ�     //���е�main�����ڳ�ʼ�� ������������test�����У�
                           //ֻ����test������ʹ��

//��ô������ȫ�ֵ���ʲô����
//�������Բ�һ����globalVar �����ļ��ɼ�
                //staticGlobalVar ֻ�ڵ�ǰ�ļ��ɼ� 
//��̬ȫ�ֱ��� ���� ���ݶ�

//����  ���� ���� ջ

//*char 2ȡ����Ԫ�ص�ַ��char�Ǹ����飬*char2 ���� ջ

//* + ���� �����Ǻ�������ڵ�λ��

int mian()
{
	//c����
	int* p1 = (int*)malloc(sizeof(int));
	int* p3 = (int*)malloc(sizeof(int)*10);

	free(p1);
	free(p3);


	//C++������
	//int* p2 = new int ;
	int* p2 = new int(10);      //����һ��int 4���ֽڿռ䣬��ʼ��Ϊ10
	int* p4 = new int[10];      //����10��int ��40���ֽڵĿռ�

	delete p2;
	delete[] p4;


	return 0;
}

//��Ȼ����malloc��free ��new �� delete��������
//������������������һ����
//�����Զ������;�������



class A
{
public:
	A()
	{
		_a = 0;
		cout << "A()" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};


int main()
{
	int* p1 = new int;
	int* p2 = (int*)malloc(sizeof(int));

	A* p3 = (A*)malloc(sizeof(A));        //����ռ�
	A* p4 = new A;                        //����ռ� + ���캯����ʼ��

	free(p3);                             //�ͷſռ�
	delete p4;                            //��������

	return 0;
}