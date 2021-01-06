//#include<iostream>
//#include<vector>
//#include<stack>
//using namespace std;
////struct TreeNode
////{
////	int val;
////	TreeNode *left;
////	TreeNode *right;
////	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
////	TreeNode(int x,TreeNode *left,TreeNode *right) : val(x), left(nullptr), right(nullptr){}
////};
////前序遍历
//class  Solution
//{
//public:
//	vector<int>preorderTraversal(TreeNode* root){
//		stack<TreeNode*> st; 
//		TreeNode* cur = root;
//		vector<int> vec; 
//		while (cur || st.empty())
//		{
//			//首先访问最左路径节点
//			while (cur)
//			{
//				//访问根
//				vec.push_back(cur->val);
//				st.push(cur);
//				cur = cur->left;
//			}
//			cur = st.top();
//			st.pop();
//			//访问右子树
//			cur = cur->right;
//		}
//		return vec;
//	}
//};
////中序遍历
//class  Solution
//{
//public:
//	vector<int>preorderTraversal(TreeNode* root){
//		stack<TreeNode*> st;
//		TreeNode* cur = root;
//		vector<int> vec;
//		while (cur || st.empty())
//		{
//			//首先访问最左路径节点
//			while (cur)
//			{
//				//左子树
//				st.push(cur);
//				cur = cur->left;
//			}
//			//节点
//			TreeNode * top = st.top();
//			st.pop();
//			vec.push_back(top->val);
//			//访问右子树
//			cur = cur->right;
//		}
//		return vec;
//	}
//}; 
//struct TreeNode
//{
//	int val;
//	TreeNode *left;
//	TreeNode *right;
//	TreeNode() :val(0), left(nullptr), right(nullptr){}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
//};
//class Soluion
//{
//public:
//	vector<int> postorderTraversal(TreeNode* root){
//		stack<TreeNode*> st;
//		vector<int> vec;
//		TreeNode* cur = root;
//		while (cur || !st.empty())
//		{
//			while (cur)
//			{
//				st.push(cur);
//				cur = cur->left;
//			}
//			TreeNode top = st.top();
//			if (top->right == nullptr ||  top->right == prev)
//			{
//				vec.push_back(top->val);
//				st.pop();
//				prev = top;
//			}
//			else
//			{
//				//如果右子树没有访问，首先访问右子树
//				cur = top->right;
//			}
//		}
//	}
//};
//int mian()
//{
//	return 0;
//}