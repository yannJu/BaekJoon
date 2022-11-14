/*
행렬 제곱
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	24795	8674	6896	33.937%
문제
크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

입력
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.

예제 입력 1
2 5
1 2
3 4
예제 출력 1
69 558
337 406
예제 입력 2
3 3
1 2 3
4 5 6
7 8 9
예제 출력 2
468 576 684
62 305 548
656 34 412
예제 입력 3
5 10
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
예제 출력 3
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
*/

#include <iostream>
#include <vector>
#define vll vector<vector<long long> >
using namespace std;

vll calc(long long m, vll matrix);
vll calcMatrix(vll A, vll B);
int main() {
	long long n, m;

	cin >> n >> m;
	vll result, matrix(n, vector<long long>(n, 0));

	//Create Matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> matrix[i][j];
	}

	result = calc(m, matrix);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) cout << result[i][j] % 1000 << " ";
		cout << endl;
	}
}

vll calc(long long m, vll matrix) {
	if (m == 1) return matrix; 
	if (m % 2 == 0) { // 짝수인 경우
		vll tmpMatrix = calc(m / 2, matrix); // m의 절반만큼만 제곱된 행렬을 구함
		return calcMatrix(tmpMatrix, tmpMatrix);
	}
	else { // 홀수인 경우
		vll tmpMatrix = calc(m - 1, matrix); // m - 1승의 행렬을 구함
		return calcMatrix(tmpMatrix, matrix);
	}
}

vll calcMatrix(vll A, vll B) {
	vll result(A.size(), vector<long long>(A[0].size(), 0));

	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[0].size(); j++) {
			for (int k = 0; k < B[0].size(); k++) {
				result[i][j] += (A[i][k] * B[k][j]) % 1000;
			}
		}
	}
	
	return result;
}