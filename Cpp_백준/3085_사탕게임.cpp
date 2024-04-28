/*
문제
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

출력
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.

예제 입력 1 
3
CCP
CCP
PPC
예제 출력 1 
3
예제 입력 2 
4
PPPP
CYZY
CCPY
PPCC
예제 출력 2 
4
예제 입력 3 
5
YCPZY
CYZZP
CCPPP
YCYZC
CPPZZ
예제 출력 3 
4
*/

#include <iostream>
#include <vector>
using namespace std;

void checkMax(vector<vector<int>> ary, int &result);
int main() {
    int N;
    int result = -1;
    cin >> N;

    pair<int, int>* dir = new pair<int, int>[4]{
        {-1, 0}, 
        {0, 1},
        {1, 0},
        {0, -1}
    };

    // Setting Ary
    vector<vector<int>> ary(N, vector<int>(N, 0)), tmpAry(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++) {
            switch(tmp[j]) {
                case 'C':
                    ary[i][j] = 0;
                    break;
                case 'P':
                    ary[i][j] = 1;
                    break;
                case 'Z':
                    ary[i][j] = 2;
                    break;
                case 'Y':
                    ary[i][j] = 3;
                    break;
            }
        }
    }

    // checkMax(ary, result);
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int origin_n = ary[i][j];
            
            // 상하좌우 사탕을 교환
            for (int k = 0; k < 4; k++) {
                int next_y = i + dir[k].first, next_x = j + dir[k].second;
                int change_n;

                if ((next_y >= 0 && next_y < N) && (next_x >= 0 && next_x < N)) {
                    change_n = ary[next_y][next_x];
                    if (change_n == origin_n) continue;

                    ary[i][j] = change_n;
                    ary[next_y][next_x] = origin_n;
                    checkMax(ary, result);
                    ary[next_y][next_x] = change_n;
                    ary[i][j] = origin_n;
                }
            }
        }
    }

    cout << result << endl;
}

void checkMax(vector<vector<int>> ary, int& result){
    int answer_col = 1, answer_row = 1;
    int s , e;

    for (int i = 0; i < ary.size(); i++) {
        s = 0, e = 1;
        while((s <= e) && (e < ary.size())) {
            if (ary[i][e] == ary[i][s]) {
                answer_col = max((e - s) + 1, answer_col);
                e++;
            }
            else s++;
        }
    }

    for (int i = 0; i < ary.size(); i++) {
        s = 0; e = 1;
        while((s <= e) && (e < ary.size())) {
            if (ary[e][i] == ary[s][i]) {
                answer_row = max((e - s) + 1, answer_row);
                e++;
            }
            else s++;
        }
    }

    int resultTmp = max(answer_col, answer_row);
    result = max(result, resultTmp);
}