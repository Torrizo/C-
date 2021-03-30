#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


int main() {

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		cin >> n >> m;
		vector<vector<int> > parter;
		vector<vector<int> > com;
		class Compare {
		public:
			bool operator()(vector<int> &a, vector<int> &b) {
				return a[0] > b[0];
			}
		};
		sort(parter.begin(), parter.end(), Compare());
		sort(com.begin(), com.end(), Compare());
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			parter.push_back({ x, j + 1 });
		}
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			com.push_back({ x, j + 1 });
		}
		sort(parter.begin(), parter.end(), [](vector<int>& a, vector<int>& b) {
			return a[0] > b[0];
		});
		sort(com.begin(), com.end(), [](vector<int>& a, vector<int>& b) {
			return a[0] > b[0];
		});
		for (int i = 0, j = 0; i < parter.size(); ++i) {

			if (com[j][0] >= parter[i][0]) {
				parter[i][0] = com[j++][1];
			}
			else{
				parter[i][0] = -1;
			}
		}
		sort(parter.begin(), parter.end(), [](vector<int>& a, vector<int>& b) {
			return a[1] < b[1];
		});
		for (vector<vector<int>>::iterator it = parter.begin(); it != parter.end(); ++it) {
			cout << (*it)[0] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}