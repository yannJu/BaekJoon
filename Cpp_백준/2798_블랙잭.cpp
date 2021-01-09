#include <iostream>
using namespace std;

int main(){
	int n, m; //n : n장의 카드 , m : 최대합 m
	int s = 0; //n장의 카드의 
	int mx = -1; //최대값
	int tmp; //임시변
	cin >> n >> m;

	int *card = new int[n];

	for (int i = 0; i < n; i++){
		cin >> card[i];
	}

	for (int i = 0; i < n - 2; i++){
		for (int j = i + 1; j < n - 1; j++){
			for (int k = j + 1; k < n; k++){
				tmp = card[i] + card[j] + card[k];
				if ((mx < tmp) && (tmp <= m)) mx = tmp;
			}
		}
	}

	cout << mx << endl;
}
