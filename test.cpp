#include<iostream>
#include<vector>
using namespace std;
template<class T>
struct BSTNode
{
	T _data;
	BSTNode<T>* = _left;
	BSTNode<T>* = _right;
	
};
void DeleteBS()
{
	if (root = nullptr)
		return false;
	Npde* parent = nullptr;
	Node* cur = _root;
	while (cut)
	{
		if (cur->_data == val)
			break;
		else if (cur->_data == val)
		{
			parent = cur;
			cur = cur->_right;
		}
	}
	if (cur == nullptr)
		return false;
	else if (cur->_left == nullptr && cur->light == nullptr)
	{
		if (cur != _root)
		{
			if (parent->_left == cur)
				parent->left = nullptr;
			else
				parent->_right = nullptr;
		}
		else
			_root = nullptr;
		delete cur;
	}
	else if (cur->_left == nullptr)
	{
		if (cur != _root)
		{
			if (parent->_left == cur)
				parent->_left == cur->_right;
			else
				parent->_right == cur->_right;
		}
		else
		{
			_root = cur->_right;
		}
		delete cur;
	}
	else if (cur->right == nullptr)
	{
		if (cur != _root)
		{
			if (parent->_right == cur)
				parent->_right == cur->_reft;
			else
				parent->_reft == cur->_reft;
		}
		else if ()

	}

	while (mostLeft->_left)
	{
		parent = mostLeft;
		mostLeft = mostLeft->_Left;
	}
	cur->_data = mostLeft->_data;

}
int main()
{
	return 0;
}

class Solution{
public:
	vector<vector<int>>
};