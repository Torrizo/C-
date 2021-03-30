//#include<iostream>
//#include<memory>
//void fun(std::shared_ptr<int> p)
//{
//	*p = 5;
//}
////int main()
////{
////	int arar = 6;
////	for (int i = 0; i < 1000000; i++)
////	{
////		std::shared_ptr<int> p = std::make_shared<int>(arar);
////		fun(p);
////		std::cout << *p;
////	}
////	system("pause");
////	return 0;
////}
//void func(int *a, int&c)
//{
//	a = &c;
//}
//int main()
//{
//	int b = 1;
//	int *a = &b;
//	int c = 2;
//	func(a, c);
//	std::cout << *a << std::endl;
//	system("pause");
//	return 0;
//}