////#include<iostream>
////
////using namespace std;
////class Base {
////public:
////	void f() {
////		cout << "Base\n";
////	}
////};
////
////class Derived :public Base {
////public:
////	void f() {
////		cout << "Derived\n";
////	}
////};
////
////
////using namespace std;
////int main() {
////	class student {
////		int rno = 10;
////	} v;
////
////	cout << v.rno;
////}
//////int main() {
//////	Base *p = new Derived();  
//////   
//////	p->f();
//////	system("pause");
//////	return 0;
//////}
//#include<iostream>
//
//using namespace std;
//class Base {
//public:
//	void f() {
//		cout << "Base\n";
//	}
//};
//class Derived :public Base {
//public:
//	void f() {
//		cout << "Derived\n";
//	}
//};
//int main() {
//	Derived obj;
//	obj.Base::f();
//	system("pause");
//	return 0;
//}
#include<iostream>

using namespace std;
int main() {
	int i;
    char s[] = "hello";

    for (i = 0; s[i]; ++i);
    cout << i << endl;

    i = 0;
	cout << sizeof(s);
    while (s[i++]);
    cout << i;
	system("pause");
	return 0;
}