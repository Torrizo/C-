#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
void add()
{
	int n;
	while (cin >> n)
	{
		vector<int> a(3 * n);
		long long sum = 0;
		for (int i = 0; i<3 * n; i++)
		{
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
}



void Cut_out(char str1[],char str2[])
{
	char *p1 = str1;
    char *p2 = str2;
	int a[256] = { 0 };
	int i;
	int n = strlen(str2);
	for (i = 0; i < n; ++i){
		a[str2[i]] = 1;
	}
	while (*p1){
		if (a[*p1] == 1){
			*p1++;
		}
		*p2++ = *p1++;
	}

	*p2 = '\0';

}

int main()
{
	char str1[] = {0};
	char str2[] = {0};
	cin >> str1;
	cin >> str2;
	Cut_out(str1, str2);
	cout << "" << str2 << endl;
	system("pause");
	//add();
	return 0;
}