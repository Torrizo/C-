
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
//	struct ListNode_CPP* _next;   //兼容c struct 的用法
//	ListNode_CPP* _prev;  //在cpp中 struct已经可以认为是类，和class一样
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
//	//operator new 和 malloc 的区别是什么？
//	//结论；使用方式都一样，处理错误方式不一样
//	void* p4 = malloc(size * 1024 * 1024 * 1024);
//	cout << p4 << endl; //返回失败0
//	//free(p4)
//	try
//	{
//		void* p5 = operator new(size * 1024 * 1024 * 1024);
//		cout << p5 << endl;  //失败抛异常 （面对对象处理问题的一种方式）
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
//	//operator new   ==> malloc + 失败抛异常实现
//	//new            ==> operator new + 构造函数
//	//new 比起malloc不一样的地方：1.调用函数初始化 2.失败了抛异常
//	//delete 比起 free不一样的地方：1.调用析构函数清理
//	//operator free 和free 没区别，因为释放空间失败直接终止进程，是因为operator new 和 operator delete成对出现 
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