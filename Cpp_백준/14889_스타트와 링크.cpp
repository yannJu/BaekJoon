//14889
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int **ary, mn = 20000; //min, score Ary

void Combination(int **ckAry, int idx, int n, int r){
	int startSum = 0, linkSum = 0, *ck = *ckAry;
	if (n == r){
		vector<int> start, link;

		for (int i = 0; i < 2*r; i++){
			if (ck[i] == 1) start.push_back(i);
			else link.push_back(i);
		}

		for (int i = 0; i < r; i++){
			for (int j = i + 1; j < r; j++){
				startSum += ary[start.at(i)][start.at(j)] + ary[start.at(j)][start.at(i)];
				linkSum += ary[link.at(i)][link.at(j)] + ary[link.at(j)][link.at(i)];
			}
		}
		if (mn > abs(startSum - linkSum)) mn = abs(startSum - linkSum);
	
		return;
	}
	for (int i = idx; i < 2*r; i++){
		if (ck[i] == 1) continue;
		ck[i] = 1;
		Combination(ckAry, i, n+1, r);
		ck[i] = 0;
	}
}

int main(){
	int n, *Ck;
	cin >> n;

	//create Ary
	ary = new int*[n];
	Ck = new int[n];
	for (int i = 0; i < n; i++) ary[i] = new int[n];

	//input Score
	for (int i = 0; i < n; i++){
		Ck[i] = 0;
		for (int j = 0; j < n; j++) cin >> ary[i][j]; 
	}

	//DFS
	Combination(&Ck, 0, 0, n / 2);
	cout << mn << endl;
}
