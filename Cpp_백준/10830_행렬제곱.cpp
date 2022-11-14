/*
��� ����
�ð� ����	�޸� ����	����	����	���� ���	���� ����
1 ��	256 MB	24795	8674	6896	33.937%
����
ũ�Ⱑ N*N�� ��� A�� �־�����. �̶�, A�� B������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� �ſ� Ŀ�� �� ������, A^B�� �� ���Ҹ� 1,000���� ���� �������� ����Ѵ�.

�Է�
ù° �ٿ� ����� ũ�� N�� B�� �־�����. (2 �� N ��  5, 1 �� B �� 100,000,000,000)

��° �ٺ��� N���� �ٿ� ����� �� ���Ұ� �־�����. ����� �� ���Ҵ� 1,000���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٺ��� N���� �ٿ� ���� ��� A�� B������ ����� ����Ѵ�.

���� �Է� 1
2 5
1 2
3 4
���� ��� 1
69 558
337 406
���� �Է� 2
3 3
1 2 3
4 5 6
7 8 9
���� ��� 2
468 576 684
62 305 548
656 34 412
���� �Է� 3
5 10
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
���� ��� 3
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
	if (m % 2 == 0) { // ¦���� ���
		vll tmpMatrix = calc(m / 2, matrix); // m�� ���ݸ�ŭ�� ������ ����� ����
		return calcMatrix(tmpMatrix, tmpMatrix);
	}
	else { // Ȧ���� ���
		vll tmpMatrix = calc(m - 1, matrix); // m - 1���� ����� ����
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