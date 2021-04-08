#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int knapsack(int products_count, int capacity, vector<int> &weights, vector<int> &values, vector<vector<int>> &res){
	for (int i = 1; i <= products_count; i++){//i个物品 
		for (int j = 1; j <= capacity; j++){//背包容量为j 
			if (weights[i] > j){//当前背包的容量 j 放不下第 i 件商品时
				res[i][j] = res[i - 1][j];
			}
			else
			{
				res[i][j] = max(res[i - 1][j - weights[i]] + values[i], res[i - 1][j]);
			}
		}
	}

	return res[products_count][capacity];
}
int main(){
	int products_count, capacity;
	//cout << "please input products count and knapsack's capacity: " << endl; 
	cin >> products_count;
	vector<int> weights(products_count + 1, 0);
	vector<int> values(products_count + 1, 0);
	for (int i = 1; i <= products_count; i++)
		cin >> weights[i];
	for (int i = 1; i <= products_count; i++)
		cin >> values[i];
	cin >> capacity;
	vector<vector<int>> res(products_count + 1, vector<int>(capacity + 1, 0));
	knapsack(products_count, capacity, weights, values, res);
	cout << "knapsack result is " << res[products_count][capacity] << endl;
	system("pause");
	return 0;
}