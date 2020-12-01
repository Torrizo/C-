#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;

int available[1][3] = { 3, 3, 2 };//系统可用资源A,B,C
int max[5][3] = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 }, { 4, 3, 3 } };//五个进程三个资源
int allocation[5][3] = { { 0, 1, 0 }, { 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } };//已分配数目
int need[5][3] = { { 7, 4, 3 }, { 1, 2, 2 }, { 6, 0, 0 }, { 0, 1, 1 }, { 4, 3, 1 } };//每个进程尚需的资源
int request[1][3] = { 0, 0, 0 };//请求
int work[1][3] = { 3, 3, 2 };
int pah[5] = { -1, -1, -1, -1, -1 };//安全序列
void Show(int pah[]) {
	cout << "process****work*****Need*****Allocation***Work+Allocation  " << endl;
	//cout << "process    work     Need     Allocation   Work+Allocation  " << endl;
	for (int i = 0; i < 5; i++) {
		int n = pah[i];
		cout << "  P" << n << "     ";
		for (int j = 0; j < 3; j++) {
			cout << work[0][j] << "  ";
		}
		cout << "|";
		for (int j = 0; j < 3; j++) {
			cout << need[n][j] << "  ";
		}
		cout << "|";
		for (int j = 0; j < 3; j++) {
			cout << allocation[n][j] << "  ";
		}
		cout << "|";
		cout << endl;
	}
}
bool compareto(int req[], int arr[]) {
	bool a = false;
	int i = 0;
	if (req[0] <= arr[0] && req[1] <= arr[1] && req[2] <= arr[2]) {
		a = true;
	}
	return a;
}//void 
int security() {
	bool a = true;
	cout << "process****work**********Need*****Allocation***Work+Allocation  " << endl;
	//cout << "process    work          Need     Allocation   Work+Allocation  " << endl;
	int count = 0, count1 = 0, count2 = 0;
	bool finish[5] = { false, false, false, false, false };
	for (int i = 0; i < 3; i++) {
		work[0][i] = available[0][i];
	}//for
	while (count<15) {
		if (count >= 5) {
			count1 = count % 5;
		}
		else {
			count1 = count;
		}
		while (finish[count1] == false && compareto(need[count1], work[0])) {
			cout << "  P" << count1 << "     ";
			for (int j = 0; j < 3; j++) {
				cout << work[0][j] << "   ";
			}
			for (int i = 0; i < 3; i++) {
				work[0][i] += allocation[count1][i];
				finish[count1] = true;
				pah[count2] = count1;
			}//for
			//    int n = pah[i];
			cout << "|";
			for (int j = 0; j < 3; j++) {
				cout << need[count1][j] << "   ";
			}
			cout << "|";
			for (int j = 0; j < 3; j++) {
				cout << allocation[count1][j] << "   ";
			}
			cout << "|";
			for (int j = 0; j < 3; j++) {
				cout << work[0][j] << "   ";
			}
			cout << endl;
			count2++;
		}//while2
		count++;
	}//while1
	for (int i = 0; i < 5; i++) {
		if (pah[i] <0) {
			a = false;
		}
	}//for
	return count2;
}
void Request() {
	int n;
	cin >> n;
	while (n != -1) {
		for (int i = 0; i < 3; i++) {
			cin >> request[0][i];
		}
		if (compareto(request[0], need[n])) {
			if (compareto(request[0], available[0])) {
				for (int i = 0; i < 3; i++) {
					available[0][i] -= request[0][i];
					allocation[n][i] += request[0][i];
					need[n][i] -= request[0][i];//资源分配

				}//for
				int b = security();
				if (b < 4) {
					for (int i = 0; i < 3; i++) {
						available[0][i] += request[0][i];
						allocation[n][i] -= request[0][i];
						need[n][i] += request[0][i];//撤销操作

					}//for
					cout << "false";
				}
				else if (b == 4) {
					Show(pah);
				}
			}//if2
			else if (!compareto(request[0], available[0])) {
				cout << "please wait";
			}
		}//if1
		else if (!compareto(request[0], need[n])) {
			cout << "value error";
		}
		cin >> n;
	}
}//void 

int main() {
	if (security()) {};
	Request();
	system("pause");
	//return 0;
}

