#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<queue>
using namespace std;
//class Solution {
//public:
//	int ans;
//	int evalRPN(vector<string>& tokens) {
//		stack<int> stk;
//		int str_mid1, str_mid2;
//		for (auto v_mate : tokens) {
//			if (v_mate == "+") {
//				str_mid1 = stk.top();
//				stk.pop();
//				str_mid2 = stk.top();
//				stk.pop();
//				stk.push(str_mid2 + str_mid1);
//			}
//			else if (v_mate == "-") {
//				str_mid1 = stk.top();
//				stk.pop();
//				str_mid2 = stk.top();
//				stk.pop();
//				stk.push(str_mid2 - str_mid1);
//			}
//			else if (v_mate == "*") {
//				str_mid1 = stk.top();
//				stk.pop();
//				str_mid2 = stk.top();
//				stk.pop();
//				stk.push(str_mid2 * str_mid1);
//			}
//			else if (v_mate == "/") {
//				str_mid1 = stk.top();
//				stk.pop();
//				str_mid2 = stk.top();
//				stk.pop();
//				stk.push(str_mid2 / str_mid1);
//			}
//			else stk.push(atoi(v_mate.c_str()));
//		}
//		ans = stk.top();
//		return ans;
//	}
//};
//
//int main()
//{
//	return  0;
//}

//template <class T>
//class Queue
//{
//	
//public:
//	void push(const T& val)
//	{
//		ls.push_back(val);
//	}
//	void pop()
//	{
//		ls.pop_front();
//	}
//	T& front()
//	{
//		return ls.front();
//	}
//	bool empty()
//	{
//		return ls.empty();
//	}
//	T& back()
//	{
//		return ls.back();
//	}
//	T& size()
//	{
//		return ls.size()
//	}
//private:
//	list<T> ls;
//};

void test()
{
	priority_queue<int,vector<int>,>
}



















