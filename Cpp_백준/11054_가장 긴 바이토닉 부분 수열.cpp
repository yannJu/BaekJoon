/*
가장 긴 바이토닉 부분 수열
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	38583	19679	15380	50.791%
문제
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  
{1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

예제 입력 1 
10
1 5 2 1 4 3 4 5 2 1
예제 출력 1 
7
*/

#include <iostream>
using namespace std;

int main() {
    int  n, *ary, *ckLeftAry, *ckRightAry, result = -1;

    cin >> n;
    ary = new int[n];
    ckLeftAry = new int[n];
    ckRightAry = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> ary[i];
        ckLeftAry[i] = 1;
        ckRightAry[i] = 1;
    }

    //set ckLeftAry 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (ary[j] < ary[i]) ckLeftAry[i] = max(ckLeftAry[i], ckLeftAry[j] + 1);
        }
    }

    for (int k = n - 1; k > -1; k--) {
        for (int l = n - 1; l > k; l--) {
            if (ary[l] < ary[k]) ckRightAry[k] = max(ckRightAry[k], ckRightAry[l] + 1);
        }
    }

    for (int i = 0; i < n; i++) result = max(result, ckLeftAry[i] + ckRightAry[i] - 1);

    cout << result << endl;
}