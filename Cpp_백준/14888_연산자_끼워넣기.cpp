/*
문제
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 
연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.

우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.

예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다. 
예를 들어, 아래와 같은 식을 만들 수 있다.

1+2+3-4×5÷6
1÷2+3+4-5×6
1+2÷3×4-5+6
1÷2×3-4+5+6
식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 
음수를 양수로 나눌 때는 C++14의 기준을 따른다. 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.

1+2+3-4×5÷6 = 1
1÷2+3+4-5×6 = 12
1+2÷3×4-5+6 = 5
1÷2×3-4+5+6 = 7
N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 
셋째 줄에는 합이 N-1인 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다. 

출력
첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 
또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.

예제 입력 1 
2
5 6
0 0 1 0
예제 출력 1 
30
30
예제 입력 2 
3
3 4 5
1 0 1 0
예제 출력 2 
35
17
예제 입력 3 
6
1 2 3 4 5 6
2 1 1 1
예제 출력 3 
54
-24
*/

#include <iostream>
#include<cmath>
using namespace std;

int calc(int n1, int n2, int op){
	switch (op)
	{
	case 0:
		return n1 + n2;
	case 1:
		return n1 - n2;
	case 2:
		return n1 * n2;
	case 3:
		return n1 / n2;
	}
}

void makeTurn(int idx, int count, int *num, int *oper, int *turn, int *ckAry, int t, int *mxRes, int *mnRes){
	int result;
	int cnt = count + 1;
	//cout << " IDX : " << idx << " COUNT : " << cnt << endl;
	// --- 연산자가 정렬된 경우 ---
	if (cnt == t){
		//for (int i = 0; i < t; i++)  cout <<  "num : " << num[i] << " oper : " << turn[i] << endl;
		for (int i = 0; i < t; i++){
			if (i == 0) result = num[i]; /// 첫번째 숫자 초기화 
			else{
				result = calc(result, num[i], turn[i]);
			}
		}
		*mxRes = max(result, *mxRes);
		*mnRes = min(result, *mnRes);
		//cout << "mx : " << *mxRes << " mn : " << *mnRes << endl;
		return;
	}

	for (int i = 1; i < t; i++){
		if (ckAry[i] == 0){
			ckAry[i] = 1;
			turn[idx] = oper[i];
			makeTurn(idx + 1, cnt, num, oper, turn, ckAry, t, mxRes, mnRes);
			ckAry[i] = 0;
		}
	}
}

int main(){
	int t_case, *num, *OPERATOR, *turn, *ckAry, cnt = 0; //테스트케이스 수, 계산 정수, 계산 연산자, 연산자의 모든 경우의 수의 순서를 담을 배열, ck배열
	int maxRes = pow(10, 9) * -1, minRes = pow(10, 9); //최대, 최소
	int tmp;

	// --- 배열 및 변수 초기화 ---
	cin >> t_case;

	num = new int[t_case];
	OPERATOR = new int[t_case];
	turn = new int[t_case];
	ckAry = new int[t_case];
	
	OPERATOR[cnt++] = -1;
	turn[0] = -1;

 // --- 계산할 정수, ck배열, 연산자 배열 초가화 ---
	for (int i = 0; i < t_case; i++) {
		cin >> num[i];
		ckAry[i] = 0;
	}
	for (int j = 0; j < 4; j++){
		cin >> tmp;
		while(tmp--) OPERATOR[cnt++] = j; // 연산자에 +가 2일경우 0, 0 과 같이 idx를 남김
	}

	makeTurn(1, 0, num, OPERATOR, turn, ckAry, t_case, &maxRes, &minRes);
	cout << maxRes << endl << minRes << endl;
}