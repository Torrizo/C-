#include<iostream>
#include<vector>
using namespace std;

//��ɢ��
//��ϣ���д�Žڵ�ָ��
//ÿһ����ϣ���λ�ö���һ��������
//���в�����ͬ��ϣλ�õ����ݻ�ŵ�ͬһ��������


template <class V>
struct HashNode
{
	V _data;
	HashNode<V>* _next;
};


//��ϣ��
template<class K,class V class KeyOfValue>
class HashTable
{
public:
	typedef HashNode<V> Node;
private:
	vector<Node*> _ht;
	size_t _size = 0;
};