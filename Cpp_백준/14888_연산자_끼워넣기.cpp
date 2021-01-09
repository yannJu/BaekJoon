#include<iostream>
using namespace std;

int mx = -1000000000, mn = 1000000000;

void permutation(int* nums, int** ck, int** pAr, int**resultpAr, int depth, int r){
	int *check = *ck;
	int *pArr = *pAr;
	int *resultpArr = *resultpAr;
	
	//cout << " D : " << depth << " R : " << r << endl;
	if (depth == r){
		int result = nums[0];
		for (int i = 1; i < r; i++){
			if (resultpArr[i] == 1) result += nums[i];
			else if (resultpArr[i] == 2) result -= nums[i];
			else if (resultpArr[i] == 3) result *= nums[i];
			else if (resultpArr[i] == 4) result /= nums[i];
			else return;
		}

		//cout << "result : " << result << " c : " << resultpArr[r - 1] << endl;
		if (result > mx) mx = result;
		if (result < mn) mn = result;
	}

	else {
		for (int i = 1; i <= r; i++){
			if (check[i] == 0) {
				check[i] = 1;
				resultpArr[depth] = pArr[i];
				permutation(nums, &check, &pArr, &resultpArr, depth+1, r);
				check[i] = 0;
			}
		}
	}
}

int main(){
	int n,  tmp = 1; //입력개수, 연산자의 합
	int *nums; //계산할 숫자를 담는 배열
	int calNums[4] = {0,}; //계산할 연산자의 개수를 담는 배열
	int *pArr, *check, *resultpArr; //순열을 만들 배열, check할 배열

	cin >> n; //입력개수 입력

	nums = new int[n]; //입력개수만큼 배열 할당
	pArr = new int[n + 1];
	check = new int[n + 1];
	resultpArr = new int[n + 1];

	for (int i = 0; i < n; i++){
		cin >> nums[i]; //계산할 숫자 입력
	}

	for (int i = 0; i < 4; i ++){
		cin >> calNums[i];
		for (int j = 0; j < calNums[i]; j++){
			check[tmp] = 0;
			pArr[tmp++] = i + 1; //순열배열 값 할당
		}
	}

/* --출력
	cout << "n : " << n << endl;
	cout << "nums : " << endl;
	for (int i = 0; i < n; i++){
		cout << nums[i] << endl;
	}

	cout << "cal : " << endl;
	for (int i = 0; i <n; i++){
		cout << pArr[i] << endl;
	}
*/

	permutation(nums, &check, &pArr, &resultpArr, 0, n);

	cout << mx << endl << mn << endl;
}
