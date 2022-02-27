/*
수들의 합
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	128 MB	24091	10232	8666	43.380%
문제
서로 다른 N개의 자연수의 합이 S라고 한다. S를 알 때, 자연수 N의 최댓값은 얼마일까?

입력
첫째 줄에 자연수 S(1 ≤ S ≤ 4,294,967,295)가 주어진다.

출력
첫째 줄에 자연수 N의 최댓값을 출력한다.

예제 입력 1 
200
예제 출력 1 
19
*/

//Greedy Algorithm

#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long int S, N, maxVal = 1, maxKey = 1;

    cin >> S;
    while(true) {
        if (S < 3 || S <= maxVal + maxKey)  break;
        maxVal += ++maxKey;
    }

    cout << maxKey << endl;
}