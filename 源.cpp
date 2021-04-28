/*
#include <iostream>
#include <string>
using namespace std;
int main() {
	string input;
	cin >> input;
	if (input.size() == 5) {
		cout << "horse" << endl;
	}
	else {
		int p = 0;
		int c = 0;
		string cat = "cat";
		string pig = "pig";
		for (int i = 0; i < input.size(); i++) {
			p += abs(input[i] - pig[i]);
			c += abs(input[i] - cat[i]);
		}
		if (p < c) {
			cout << "pig" << endl;
		}
		else {
			cout << "cat" << endl;
		}
	}
}

*/

#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> input(m, 0);
	for (int i = 0; i < m; i++) {
		cin >> input[i];
	}
	//表示电灯状态
	vector<int> state(n, 1);
	//状态改变的时间
	vector<int> changeTime(n, -1);
	for (int i = 0; i < m; i++) {
		for (int j = input[i] - 1; j < n; j++) {
			if (state[j] == 1) {
				state[j] = 0;
				if (changeTime[j] == -1) {
					changeTime[j] = i+1;
				}
			}
		}
	}
	for (int i = 0; i < changeTime.size(); i++) {
		cout << changeTime[i] << " ";
	}
	cout << endl;
}