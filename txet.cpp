
#include<iostream>
using namespace std;
//struct ListNode
//{
//	int _val;
//	struct ListNode* _next;
//	struct ListNode* _prev;
//};
//
//
//typedef struct ListNode;
//ListNode* BuyListNode(int val)
//{
//	ListNode* node_c = (ListNode*)malloc(sizeof(ListNode));
//	node_c->_val = 1;
//	node_c->_next = NULL;
//	node_c->_prev = NULL;
//
//	return node_c;
//}
//
//
//
//
//struct ListNode_CPP
//{
//	int _val;
//	struct ListNode_CPP* _next;   //����c struct ���÷�
//	ListNode_CPP* _prev;  //��cpp�� struct�Ѿ�������Ϊ���࣬��classһ��
//
//	ListNode_CPP(int val = 0)
//	   :_val(val)
//	   , _next(nullptr)
//	   , _prev(nullptr)
//	{}
//};
//
//
//
//int main()
//{
//	int *p1 = (int*)malloc(sizeof(int));
//	int *p2 = new int;
//}
















//class A
//{
//public:
//
//
//private:
//	int _a;
//};
//
//
//
//
//
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	A* p3 = (A*)operator new(sizeof(A));
//
//	//operator new �� malloc ��������ʲô��
//	//���ۣ�ʹ�÷�ʽ��һ�����������ʽ��һ��
//	void* p4 = malloc(size * 1024 * 1024 * 1024);
//	cout << p4 << endl; //����ʧ��0
//	//free(p4)
//	try
//	{
//		void* p5 = operator new(size * 1024 * 1024 * 1024);
//		cout << p5 << endl;  //ʧ�����쳣 ����Զ����������һ�ַ�ʽ��
//		//operateor delete(p5)
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//int mian()
//{
//	//malloc /free 
//	//operator new   ==> malloc + ʧ�����쳣ʵ��
//	//new            ==> operator new + ���캯��
//	//new ����malloc��һ���ĵط���1.���ú�����ʼ�� 2.ʧ�������쳣
//	//delete ���� free��һ���ĵط���1.����������������
//	//operator free ��free û������Ϊ�ͷſռ�ʧ��ֱ����ֹ���̣�����Ϊoperator new �� operator delete�ɶԳ��� 
//}



//struct ListNode
//{
//
//public:
//	////List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//
//	~List()
//};



int main()
{
	A* p = new A;
	delete p;
}