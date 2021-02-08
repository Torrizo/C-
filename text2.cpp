#include <assert.h>
#include <iostream>
using namespace std;
int main()


{
	

	int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int n = sizeof(ar) / sizeof(int);

	vector<int> v(ar, ar + n);

	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(100);

	v.resize(20);

	cout << v.size() << ":" << v.capacity() << endl;

	v.reserve(50);

	v.resize(5);

	cout << v.size() << ":" << v.capacity() << endl;

}


}

