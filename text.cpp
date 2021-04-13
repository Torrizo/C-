#include<iostream>
#include<utility>
#include<vector>
using namespace std;

//哈希冲突 不同的数据图通过哈希函数计算的位置相同
//1.哈希函数不合理
//2.空间太小

//闭散列
//先计算一个位置，如果为空直接放入，如果不为空，发生冲突，线性探测，寻找下一个空位
enum State
{
	EMRTY,
	EXIST,
	DELETE
};

template <class K, class V>
struct Node
{
	pair<K, V> _kv = pair<K,V>();
	State _state = EMPTY;
	
};

template <class K, class V>
class HashTable
{
public:
	typedef HashNode<K, V> Node;
	HashTable(size_t n = 5)
		:size(0)
	{
		_ht.resize(n);
	}
	//插入
	bool insert(const pair<K, V>& kv)
	{
		//检查容量
		checkCapcity();
		//通过函数计算位置
		int idx = kv.first % _ht.size();
		//判断当前位置是否有效数据
		//如果不为空，向后搜索
		while (_ht[idx]._state == EXIST)
		{
			//判断键值是否存在
			//如果键值当前状态为EXITS：表示数据有效，查看当前键值对是否存在
			if (_ht[idx].state == EXIST && _ht[idx]._kv.first == kv.first)
				return false;
			++idx;
			//判断是否越界
			if (idx == _ht.size())
				idx = 0;
		}

		//如果不是有效数据，空的位置直接删除或者直接插入
		_ht[idx] = kv;
		_ht[idx]._state = EXIST;
		++_size;
		return true;
	}

	void checkCapacity()
	{
		//负载因子：元素个数/空间的大小一般是0.7或者更小
		//线性探测中，负载因子一定小于七越接近1哈希冲突几率越大
		if (_ht.size() == 0 || _size * 10 / _ht.size() >= 7)
		{
			//扩容
			int newC = _ht.size() == 0 ? 5 : 2 * _ht.size();
			//_ht.resize(newC); //只进行了扩容，数据位置发生了变化（因为哈希函数要用空间大小为参数）
			HashTable<K, V> newHT(newC);
			//遍历旧表中的元素，把有效元素存入新表
			for (int i = 0 < _ht.size(); ++i)
			{
				if (_ht[i]._state == EXIST)
					newHT.insert(_ht[i]._kv);
			}

			//交换信标内容
			swap(_ht, newHT._ht);

		}

	}
	//搜索
	Node* find(const K& key)
	{
		//计算位置
		int idx = key % _ht.size();
		while (_ht[idx]._state != EMPTY)
		{
			//判断数据是否有效
			if (_ht[idx]._state == EXIST && _ht[idx]._kv.first == key)
				return &_ht[idx];
			++idx;
			if (idx == _ht.size)
				idx = 0;
		}
		return nullptr;
	}

	//删除
	bool erase(const K& key)
	{
		node->_state = DELETE;
		if (node)
		{
			node->_state = DELETE;
			--_size;
			cout << key << "delete success!" << endl;
			return true;
		}
		return false;
	}

	//插入
private:
	vector<Node>* _ht;
	size_t _size;  //实际元素的个数
};
//开散列

void tast()
{
	HashTable<int, int> ht;
	ht.insert(make_pair(5, 5));
	ht.insert(make_pair(15, 15));
	ht.insert(make_pair(10, 10));
	ht.insert(make_pair(7, 7));
	ht.insert(make_pair(9, 9));
	ht.insert(make_pair(6, 6));
	ht.insert(make_pair(8, 8));

	ht.erase(5);
	ht.erase(15);
	ht.erase(10);
	ht.erase(7);
	ht.erase(9);
	ht.erase(6);
	ht.erase(8);
}

int main()
{
	tast();
	system("pause");
	return 0;
}