#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <functional>
using namespace std;
struct Date
{

};

template<class T>
struct Less
{
	bool operator()(const T& val1, const T& val2)
	{
		return val1 < val2;
	}

};
template <class T,class containet>
//template <class T, class containet,>

class PriorityQueue
{
public:
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (_com.operator()(_c[parent], _c[parent]))
			//if (_com(_c[parent], _c[parent]))//用比较器比较
			//if (_c[parent] < _c[child])
			{
				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
		
	}
	void push(const T& val)
	{
		//尾插+向上调整
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}
	void pop()
	{
		//尾删+向下调整
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDow(0);
	}
	T& top()
	{
		return _c[0];
	
	}

	bool empty
	{
		return _c.empty();
	}

	size_t size()
	{
		return _c.size();
	}
	void shiftDow(int parent)
	{
		//int child1 = (2 * parent);
		//int childe2 = (2 * parent) + 1;
		//	while ()//child2 != NULL
		//	{
		//		if (_c[child1] > _c[parent])
		//		{
		//			swap(_c[child1], _c[parent]);
		//			parent = child1;
		//			child1 = (2 * parent);
		//		}
		//		else
		//		{
		//			swap(_c[child2], _c[parent]);
		//			parent = child2;
		//			child2 = (2 * parent) + 1;
		//		}
		//       else
		//	       break;
		//	}
		int child = 2 * parent + 1;
		while (child < c.size())
		{
			//左右孩子中找最大值
			if (child + 1 < c.size() && _c[child] < _c[child + 1])
				++child;
			//和父亲节点比较
			if (_c[parent] < _c[child])
			{
				swap(_c[child], _c[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
		
	}
private:
	Container _c;
	compare;
};


void test2()
{
	//优先级队列默认容器： vector ————> 随机访问的效率高于双端队列
	//PriorityQueue<int, vector<int>> pq; == PriorityQueue<int> pq;
	//PriorityQueue<int, queue<int>> pq;
	//PriorityQueue<int, vector<int>,less<int>> pq;  
	//list不支持随机访问，不能优先级队列的底层容器
	PriorityQueue<int, vector<int>> pq;
	for (int i = 1; i <= 100; ++i)
	{
		pq.push(i);
	}
	for (int i = 1; i <= 100; ++i)
	{
		cout << pq.top() << "";
		pq.pop();
	}
}


void test()
{
	//大堆
	PriorityQueue<int, vector<int>> pq;
	pq.push(10);
	pq.push(5);
	pq.push(32);
	pq.push(23);
	pq.push(6);
	pq.push(1);

	pq.pop();
	pq.pop();
	pq.pop();
	pq.pop();
	pq.pop();
	pq.pop();


}


int main()
{
	test();
	return 0;
}