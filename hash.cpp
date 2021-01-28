#include<utility>
#include<vector>
using namespace std;
//闭散列：线性探测

enum State
{
	EMPTY,
	EXIST,
	DELETE
};

template<class K, class V>
struct HashNode
{
	pair<K, V> _kv = pair<K, V>();
	State _state;

	
};

template<class K, class V>
class HashTable
{
public:
	typedef HashNode<K, V> Node;
	HashTable(size_t n = 5)
		:_size(0)
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
		//判断当前是否为空
		//如果不为空，向后搜索
		while (_ht[idx]._state != EMPTY)
		{
			//判断键值是否存在
			//如果当前状态是EXITS：表示数据有效，查看当前数据的键值是否存在
			if (_ht[idx]._state == EXIST && _ht[idx].kv.frist == kv.first)
				return false;

			++idx;
			if (idx == _ht.size())
				idx = 0;
		}
		//如果为空，直接插入
		_ht[idx]._kv = kv;
		_ht[idx]._state = EXIST;
		++_size;
		return true;
	}
	void checkCapacity()
	{
		//负载因子：元素个数 / 空间大小
		//线下探测，负载因子一定小于1，越接近1，哈希冲突率约高
		//一般小于0.7
		if (_size * 10 / _ht.size() >= 7)
		{
			//扩容
			int newC = _ht.size() == 0 ? 5 : 2 * _ht.size();
			HashTable<K, V>newHT(newC);
			//重新插入：空间改变之后，数据位置可能会发生改变
			//遍历旧表中的元素，把有效元素存入新表

			for (int i = 0; i < _ht.size(); ++i)
			{
				if (_ht[i]._state == EXIST)
					newHT.insert(_ht[i]._kv);
			}
			swap(_ht, newHT._ht);
		}
	}

	//搜索
	Node* find(const K& key)
	{
		//计算位置
		int idx = key & _ht.size();
		while (_ht[idx].state != EMPTY)
		{
			if (_ht[idx]._state == EXIST && _ht[idx].kv.first == key)
				return &_ht[idx];
			++idx;
			if (idx == _ht.size())
				idx = 0;
		}
		return nullptr;
	}


	//删除
	bool erase(const K& key)
	{
		Node* node = find(key);
		if (node)
		{
			//假删除 只修改状态
			node->_state = DELETE;
			--_size;
			cout << key << "delete success" << endl;
			return true;
		}
		cout << key << "delete failed" << endl;
		return false;
	}


private:
	vector<Node> _ht;
	size_t _size;  //表示实际元素的个数
};