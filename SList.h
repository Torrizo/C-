#include<stdio.h>
typedef struct SListNode SListNode;

struct SListNode
{
	int val;
	struct SListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val){
	ListNode* prev = NULL, *cur = head;
	while (cur != NULL)
	{
		if (cur->val == val)
		{
			ListNode* next = cur->next;
			free(cur);
			// É¾³ý
			if (cur == head)
			{
				head = next;
			}
			else
			{
				prev->next = next;
			}

			cur = next;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}

typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head){
	ListNode* slow = head, *fast = head;
	//while(!(fast == NULL || fast->next == NULL))
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}
