#include<iostream>
//#include<list>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr)
		{
			return nullptr;
		}
		ListNode* p_fast = pHead->next;
		pHead->next = NULL;
		while (p_fast != NULL)
		{
			ListNode* temp = p_fast->next;
			p_fast->next = pHead;
			pHead = p_fast;
			p_fast = temp;
		}
		return pHead;

	}
};
void test()
{
	
}
int main()
{
	
	test();
	system("pasue");
	return 0;
}