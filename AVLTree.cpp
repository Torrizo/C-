#include<vector>
#include<iostream>
using namespace std;
template < class T >
struct AVLTreeNode
{
	T _data;
	//左右孩子的指针
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	//父节点的指针
	AVLTreeNode<T>* _parent;
	//平衡因子
	int _bf;

	AVLTreeNode(const T& val = T())
		: _data(val)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template < class T >
class AVLTree
{
public:
	typedef AVLTreeNode<T> Node;

	bool insert(const T& val)
	{
		//空树，创建根节点
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		//搜索
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_data == val)
				return false;
			else if (cur->_data > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(val);
		if (parent->_data > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		//链接parent指针
		cur->_parent = parent;
		//更新平衡因子，从parent开始
		// 更新范围:从parent一直到root这条路径上的祖先节点
		while (parent)  //刚插入节点的直接父节点，也可能为祖先节点
		{
			if (parent->_left == cur)
				parent->_bf--;
			else
				parent->_bf++;
			if (parent->_bf == 0) //从-1到1变化过来的
				//parent节点某一子树补齐，parent的高度并没有发生变化
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)  //从0变化过来
			{
				//继续更新
				cur = parent;
				parent = parent->_parent;
			}
			else
			{
				//调整搜索树，重新达到平衡状态
				if (parent->_bf == -2 && cur->_bf == 1)
				{
					//左边的左边高：右旋
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					//右边的右边高：左旋
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					//左右双旋
					RotateL(cur);
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					//右左双旋
					RotateR(cur);
					RotateL(parent);
				}
				break;

			}
		}
		return true;
	}

	void RotateR(Node* parent)
	{
		//左子树的根节点
		Node* subL = parent->_left;
		//左子树的右子树的根节点
		Node* subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = parent;
		}

		//如果parent为根节点，则需要更新根节点
		if (parent == _root)
		{
			_root = subL;
			//根节点没有父节点
			subL->_parent = nullptr;
		}

		Node* pparent = parent->_parent;
		if (pparent->_left == parent)
			pparent->_left = subL;
		else
			pparent->_right = subL;
		subL->_parent = pparent;
		parent->_parent = subL;

		//更新平衡因子
		parent->_bf = subL->_bf = 0;
	}
	void RotateL(Node* parent)
	{
		//右子树的根节点
		Node* subR = parent->_right;
		//右子树的左子树的根节点
		Node* subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		//如果parent为根节点，则需要更新根节点
		if (parent == _root)
		{
			_root = subR;
			//根节点没有父节点
			subR->_parent = nullptr;
		}

		Node* pparent = parent->_parent;
		if (pparent->_right == parent)
			pparent->_right = subR;
		else
			pparent->_left = subR;
		subR->_parent = pparent;
		parent->_parent = subR;

		//更新平衡因子
		parent->_bf = subR->_bf = 0;
	}

	void inorder()
	{
		_inorder(_root);
		cout << endl;
	}
	void _inorder(Node* root)
	{
		if (root)
		{
			_inorder(root->_left);
			cout << root->_data << "_data" <<" ";
			_inorder(root->_right);
		}
	}

	int getHeight(Node* root)
	{
		if (root == nullptr)
			return 0;
		int left = getHeight(root->_left);
		int right = getHeight(root->_right);
		return left > right ? left + 1 : right + 1;
	}

	bool isBalance()
	{
		return _isBalance(_root);
	}
	bool _isBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		int rightHeight = getHeight(root->_right);
		int leftHeight = getHeight(root->_left);
		//判断平衡因子是否正确：bf = right - left
		if (root->_bf != rightHeight - leftHeight)
		{
			//平衡因子有问题
			cout << "当前位置" << root->_data << " bf: " << root->_bf <<"left:" << leftHeight << "right:" << rightHeight << endl;
			return false;
		}
		return abs(root->_bf) < 2 
			&& _isBalance(root->_left) 
			&& _isBalance(_root->_right);
	}
private:
	Node* _root = nullptr;
};

void test()
{
	AVLTree<int> avl;
	//avl.insert(60);
	//avl.insert(30);
	//avl.insert(65);
	//avl.insert(15);
	//avl.insert(50);
	//avl.insert(10); //右旋
	//avl.insert(60);
	//avl.insert(30);
	//avl.insert(65);
	//avl.insert(63);
	//avl.insert(70);
	//avl.insert(79 );//左旋
	//avl.insert(69);
	//avl.insert(60);
	//avl.insert(70);
	//avl.insert(30);
	//avl.insert(63);
	//avl.insert(62);//左右双旋
	vector<int> vec = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (const auto& e : vec)
	{
		avl.insert(e);
	}
	avl.inorder();
	avl.isBalance();
}

int main()
{

	test();
	system("pause");
	return 0;
} 