/*
행렬 곱셈
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	128 MB	9492	6518	5626	70.360%
문제
N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.

입력
첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 
그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. 
N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

출력
첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.

예제 입력 1 
3 2
1 2
3 4
5 6
2 3
-1 -2 0
0 0 3
예제 출력 1 
-1 -2 6
-3 -6 12
-5 -10 18
*/

#include <iostream>
using namespace std;

int main(){
    int AN, AM, BM, BK;
    int **A, **B, **C;

    cin >> AN >> AM;
    A = new int*[AN];
    for (int i = 0; i < AN; i++){
        int* tmp = new int[AM];
        A[i] = tmp;
    }
    for (int i = 0; i < AN; i++){
        for (int j = 0; j < AM; j++){
            cin >> A[i][j];
        }
    }

    cin >> BM >> BK;
    B = new int*[BM];
    for (int i = 0; i < BM; i++){
        int* tmp = new int[BK];
        B[i] = tmp;
    }
    for (int i = 0; i < BM; i++){
        for (int j = 0; j < BK; j++){
            cin >> B[i][j];
        }
    }

    C = new int*[AN];
    for (int i = 0; i < AN; i++){
        int *tmp = new int[BK];
        for (int j = 0; j < BK; j++) tmp[j] = 0;
        C[i] = tmp;
    }

    //Calc-------
    for (int i = 0; i < AN; i++){
        for (int j = 0; j < BK; j++){
            int tmpResult = 0;
            for (int k = 0; k < AM; k++){
                tmpResult += A[i][k] * B[k][j];
                C[i][j] = tmpResult;
            }
        }
    }

    for (int i = 0; i < AN; i++){
        for (int j = 0; j < BK; j++) cout << C[i][j] << " ";
        cout << endl;
    }
}