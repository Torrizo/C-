#include<iostream>
#include<string>
using namespace std;
	
	

int main()
{
	string str1 = "hello";
	string str2;
	cin >> str1;
	cin >> str2;
	char *pos = const_cast<char*>(str1.c_str());
	
	
	return 0;
}