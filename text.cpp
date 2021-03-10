#include<iostream>
#include<utility>
#include<vector>
using namespace std;

//��ϣ��ͻ ��ͬ������ͼͨ����ϣ���������λ����ͬ
//1.��ϣ����������
//2.�ռ�̫С

//��ɢ��
//�ȼ���һ��λ�ã����Ϊ��ֱ�ӷ��룬�����Ϊ�գ�������ͻ������̽�⣬Ѱ����һ����λ
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
	//����
	bool insert(const pair<K, V>& kv)
	{
		//�������
		checkCapcity();
		//ͨ����������λ��
		int idx = kv.first % _ht.size();
		//�жϵ�ǰλ���Ƿ���Ч����
		//�����Ϊ�գ��������
		while (_ht[idx]._state == EXIST)
		{
			//�жϼ�ֵ�Ƿ����
			//�����ֵ��ǰ״̬ΪEXITS����ʾ������Ч���鿴��ǰ��ֵ���Ƿ����
			if (_ht[idx].state == EXIST && _ht[idx]._kv.first == kv.first)
				return false;
			++idx;
			//�ж��Ƿ�Խ��
			if (idx == _ht.size())
				idx = 0;
		}

		//���������Ч���ݣ��յ�λ��ֱ��ɾ������ֱ�Ӳ���
		_ht[idx] = kv;
		_ht[idx]._state = EXIST;
		++_size;
		return true;
	}

	void checkCapacity()
	{
		//�������ӣ�Ԫ�ظ���/�ռ�Ĵ�Сһ����0.7���߸�С
		//����̽���У���������һ��С����Խ�ӽ�1��ϣ��ͻ����Խ��
		if (_ht.size() == 0 || _size * 10 / _ht.size() >= 7)
		{
			//����
			int newC = _ht.size() == 0 ? 5 : 2 * _ht.size();
			//_ht.resize(newC); //ֻ���������ݣ�����λ�÷����˱仯����Ϊ��ϣ����Ҫ�ÿռ��СΪ������
			HashTable<K, V> newHT(newC);
			//�����ɱ��е�Ԫ�أ�����ЧԪ�ش����±�
			for (int i = 0 < _ht.size(); ++i)
			{
				if (_ht[i]._state == EXIST)
					newHT.insert(_ht[i]._kv);
			}

			//�����ű�����
			swap(_ht, newHT._ht);

		}

	}
	//����
	Node* find(const K& key)
	{
		//����λ��
		int idx = key % _ht.size();
		while (_ht[idx]._state != EMPTY)
		{
			//�ж������Ƿ���Ч
			if (_ht[idx]._state == EXIST && _ht[idx]._kv.first == key)
				return &_ht[idx];
			++idx;
			if (idx == _ht.size)
				idx = 0;
		}
		return nullptr;
	}

	//ɾ��
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

	//����
private:
	vector<Node>* _ht;
	size_t _size;  //ʵ��Ԫ�صĸ���
};
//��ɢ��

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