/*
예제 입력 1 
6 2
3 3 3 3 3 3
2 3 3 3 3 3
2 2 2 3 2 3
1 1 1 2 2 2
1 1 1 3 3 1
1 1 2 3 3 2
예제 출력 1 
3
예제 입력 2 
6 2
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
예제 출력 2 
7
예제 입력 3 
6 3
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
예제 출력 3 
3
예제 입력 4 
6 1
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
예제 출력 4 
11
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, L;
    int answer = 0;

    cin >> N >> L;
    vector<vector<int>> map(N, vector<int>(N, 0));

    // setting map
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> map[i][j];
    }

    vector<vector<int>> ramp_row(N, vector<int>(N, 0)); // row 용
    vector<vector<int>> ramp_col(N, vector<int>(N, 0)); // col 용
    // row 기준
    for (int i = 0; i < N; i++) {
        // i -> row
        int j = 1;
        for (j; j < N; j++)  {
            if (map[i][j] == map[i][j - 1]) continue;
            if (abs(map[i][j] - map[i][j - 1]) == 1) { // 차이가 1일때 (사다리 놓을 수 있음)
                if (map[i][j] - map[i][j - 1] > 0) { // 왼-> 오로 경사로 두기
                    if ((j - L) < 0) break;
                    int prev = map[i][j - 1];
                    int k = 1;
                    for (k; k <= L; k++) {
                        if ((prev != map[i][j - k]) || (ramp_row[i][j - k])) break; // L개의 길이 같지 않음 || 이미 경사로가 있는 경우
                    }
                    if (k <= L) break;
                    else {
                        for (int l = 1; l <= L; l++) ramp_row[i][j - l] = 1; // 경사로가 있음을 표시
                    }
                }
                else { // 오 -> 왼으로 경사로 두기
                    if ((j + (L - 1)) >= N) break;
                    int now = map[i][j];
                    int k = 0;
                    for (k; k < L; k++) {
                        if ((now != map[i][j + k]) || (ramp_row[i][j + k])) break; // L개의 길이 같지 않음 || 이미 경사로가 있는 경우
                    }
                    if (k + 1 < L) break;
                    else {
                        for (int l = 0; l < L; l++) ramp_row[i][j + l] = 1; // 경사로가 있음을 표시
                    }
                }
            }
            else break;
        }
        if (j == N) answer += 1; // 한 줄을 모두 탐색했을 경우
    }
    
    //col 기준
    for (int i = 0; i < N; i++) {
        // i -> col
        int j = 1;
        for (j; j < N; j++)  {
            if (map[j][i] == map[j - 1][i]) continue;
            if (abs(map[j][i] - map[j - 1][i]) == 1) { // 차이가 1일때 (사다리 놓을 수 있음)
                if (map[j][i] - map[j - 1][i] > 0) { // 왼-> 오로 경사로 두기
                    if ((j - L) < 0) break;
                    int prev = map[j - 1][i];
                    int k = 1;
                    for (k; k <= L; k++) {
                        if ((prev != map[j - k][i]) || (ramp_col[j - k][i])) break; // L개의 길이 같지 않음 || 이미 경사로가 있는 경우
                    }
                    if (k <= L) break;
                    else {
                        for (int l = 1; l <= L; l++) ramp_col[j - 1][i] = 1; // 경사로가 있음을 표시
                    }
                }
                else { // 오 -> 왼으로 경사로 두기
                    if ((j + (L - 1)) >= N) break;
                    int now = map[j][i];
                    int k = 0;
                    for (k; k < L; k++) {
                        if ((now != map[j + k][i]) || (ramp_col[j + k][i])) break; // L개의 길이 같지 않음 || 이미 경사로가 있는 경우
                    }
                    if (k + 1 < L) break;
                    else {
                        for (int l = 0; l < L; l++) ramp_col[j + l][i] = 1; // 경사로가 있음을 표시
                    }
                }
            }
            else break;
        }
        if (j == N) answer += 1;
    }

    cout << answer << endl;
    return 0;
}