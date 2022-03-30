/*
팩토리얼
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	103584	52691	43782	51.218%
문제
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)이 주어진다.

출력
첫째 줄에 N!을 출력한다.

예제 입력 1 
10
예제 출력 1 
3628800
예제 입력 2 
0
예제 출력 2 
1
*/

#include<iostream>
using namespace std;

int fecto(int t){
    if (t == 1) return 1;
    return t * fecto(t - 1);
}

int main(){
    int t, answer = 1;

    cin >> t;

    if (t > 0) answer = fecto(t);
    cout << answer << endl;
}