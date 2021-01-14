//9440
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(int a, int b){
	return a > b;
}
int main(){
	int cNum;
	int first, second, tmp, firstArySize;
	int result;
	int *firstAry;
	int *secondAry;
	while(true){
		cin >> cNum;
		if (cNum == 0) break;
		if (cNum % 2 == 0) firstArySize = cNum / 2;
		else firstArySize = cNum / 2 + 1;
		first = 0;
		second = 0;

		secondAry = new int[cNum/2];
		firstAry = new int[firstArySize];
		int* allAry = new int[cNum];

		for (int i = 0; i < cNum; i++) {
			cin >> allAry[i]; 
		}

		sort(allAry, allAry + cNum);

		for (int j = 0; j < firstArySize; j ++){
			firstAry[j] = allAry[2 * j];
		}
		for (int j = 0; j < cNum/2; j ++){
			firstAry[j] = allAry[2 * j];
			secondAry[j] = allAry[2 * j + 1];
		}

		for (int k = 0; k < firstArySize; k++) {
			if (firstAry[0] != 0) break;
			else if (firstAry[0] == 0 && firstAry[k] != 0){
				cout << k << endl;
				tmp = firstAry[k];
				firstAry[k] = firstAry[0];
				firstAry[0] = tmp;
			}
			cout << k << endl;
		}

		for (int l = 0; l < cNum / 2; l++) {
			if (secondAry[0] == 0){
				tmp = secondAry[l];
				secondAry[l] = secondAry[0];
				secondAry[0] = tmp;
			}
			else break;
		}
/*

		for (int l = 0; l <= cNum / 2; l++) {
			cout << firstAry[l] << " ";
		}
		cout << endl;

		for (int l = 0; l < cNum/ 2; l++){
			cout << secondAry[l] << " " ;
		}
		cout << endl;
*/

		for (int i = 0; i < firstArySize; i++) first += pow(10, firstArySize - i - 1) * firstAry[i]; 
		for (int i = 0; i < cNum/2; i++) second += pow(10, cNum/2 - i - 1) * secondAry[i];

		cout << first + second << endl;
		//cout << first << " " << second << endl;
	}
}
