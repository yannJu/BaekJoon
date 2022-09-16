/*
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

예제 입력 1 
8
예제 출력 1 
92
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

void setQueen(int y, int** MAP, int* Result, int N);
int ckQueen(int y, int x, int* map);
int main() {
    int N, *map, result = 0;

    cin >> N;
    map = new int[N];

    for (int i = 0; i < N; i++) {
        map[0] = i;
        setQueen(1, &map, &result, N);
    }

    cout << result << endl;
}

void setQueen(int y, int** MAP, int* Result, int N) {
    int *map = *MAP;
    
    if (y == N) {
        Result[0] += 1;
        // cout << y - 1 << " " << map[y - 1] << endl;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (ckQueen(y, i, *MAP) == 1) {
            map[y] = i;
            MAP = &map;
            setQueen(y + 1, MAP, Result, N);
        }
    }
}

int ckQueen(int y, int x, int* map) {
    for (int i = 0; i < y; i++) {
        if (map[i] == x) return 0;
        else if (abs(y - i) == abs(x - map[i])) return 0;
    }
    return 1;
}