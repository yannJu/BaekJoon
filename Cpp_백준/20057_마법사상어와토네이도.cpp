/*
마법사 상어와 토네이도
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	512 MB	8049	5708	3817	70.803%
문제
마법사 상어가 토네이도를 배웠고, 오늘은 토네이도를 크기가 N×N인 격자로 나누어진 모래밭에서 연습하려고 한다. 위치 (r, c)는 격자의 r행 c열을 의미하고, A[r][c]는 (r, c)에 있는 모래의 양을 의미한다.

토네이도를 시전하면 격자의 가운데 칸부터 토네이도의 이동이 시작된다. 토네이도는 한 번에 한 칸 이동한다. 다음은 N = 7인 경우 토네이도의 이동이다.



토네이도가 한 칸 이동할 때마다 모래는 다음과 같이 일정한 비율로 흩날리게 된다.



토네이도가 x에서 y로 이동하면, y의 모든 모래가 비율과 α가 적혀있는 칸으로 이동한다. 비율이 적혀있는 칸으로 이동하는 모래의 양은 y에 있는 모래의 해당 비율만큼이고, 계산에서 소수점 아래는 버린다. α로 이동하는 모래의 양은 비율이 적혀있는 칸으로 이동하지 않은 남은 모래의 양과 같다. 모래가 이미 있는 칸으로 모래가 이동하면, 모래의 양은 더해진다. 위의 그림은 토네이도가 왼쪽으로 이동할 때이고, 다른 방향으로 이동하는 경우는 위의 그림을 해당 방향으로 회전하면 된다.

토네이도는 (1, 1)까지 이동한 뒤 소멸한다. 모래가 격자의 밖으로 이동할 수도 있다. 토네이도가 소멸되었을 때, 격자의 밖으로 나간 모래의 양을 구해보자.

입력
첫째 줄에 격자의 크기 N이 주어진다. 둘째 줄부터 N개의 줄에는 격자의 각 칸에 있는 모래가 주어진다. r번째 줄에서 c번째 주어지는 정수는 A[r][c] 이다.

출력
격자의 밖으로 나간 모래의 양을 출력한다.

제한
3 ≤ N ≤ 499
N은 홀수
0 ≤ A[r][c] ≤ 1,000
가운데 칸에 있는 모래의 양은 0
예제 입력 1 
5
0 0 0 0 0
0 0 0 0 0
0 10 0 0 0
0 0 0 0 0
0 0 0 0 0
예제 출력 1 
10
예제 입력 2 
5
0 0 0 0 0
0 0 0 0 0
0 100 0 0 0
0 0 0 0 0
0 0 0 0 0
예제 출력 2 
85
예제 입력 3 
7
1 2 3 4 5 6 7
1 2 3 4 5 6 7
1 2 3 4 5 6 7
1 2 3 0 5 6 7
1 2 3 4 5 6 7
1 2 3 4 5 6 7
1 2 3 4 5 6 7
예제 출력 3 
139
예제 입력 4 
5
100 200 300 400 200
300 243 432 334 555
999 111 0 999 333
888 777 222 333 900
100 200 300 400 500
예제 출력 4 
7501
예제 입력 5 
5
0 0 100 0 0
0 0 100 0 0
0 0 0 0 0
0 0 100 0 0
0 0 100 0 0
예제 출력 5 
283
예제 입력 6 
9
193 483 223 482 858 274 847 283 748
484 273 585 868 271 444 584 293 858
828 384 382 818 347 858 293 999 727
818 384 727 373 636 141 234 589 991
913 564 555 827 0 999 123 123 123
321 321 321 983 982 981 983 980 990
908 105 270 173 147 148 850 992 113
943 923 982 981 223 131 222 913 562
752 572 719 590 551 179 141 137 731
예제 출력 6 
22961
*/

#include <iostream>
#include <vector>
#define vii vector<vector<int> >
using namespace std;

struct DIR {
    int  y, x;
    DIR(int _y, int _x) : y(_y), x(_x) {};
};
DIR dir[4] = {
    DIR(0, -1), 
    DIR(1, 0),
    DIR(0, 1),
    DIR(-1, 0)
}; // 왼, 하, 우, 상

vector<vector<double>> origin = {
    {0, 0, 0.02, 0, 0},
    {0, 0.1, 0.07, 0.01, 0},
    {0.05, 0, 0, 0, 0},
    {0, 0.1, 0.07, 0.01, 0},
    {0, 0, 0.02, 0, 0}
};

void rotate();
int main() {
    int N, answer = 0, sumSand = 0;

    cin >> N;

    // setting Map
    vii map(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            sumSand += map[i][j];
        }
    }

    DIR now(N / 2, N / 2);
    int dirIdx = 0;
    // 1. N번 반복
    for (int i = 1; i <= N; i++) {
        // 2. 동일한 간격으로 "2"번 움직인다. -> 단 i == N 인경우는 1번
        for (int j = 0; j < 2; j++) {
            if (i == N && j == 1) break;
            for (int k = 0; k < i; k++) { // N 크기만큼 이동
                if (i == N && k == N - 1) break;
                DIR next(now.y + dir[dirIdx].y, now.x + dir[dirIdx].x);

                int tmp = 0;
                for (int oi = -2; oi <= 2; oi++) {
                    for (int oj = -2; oj <= 2; oj++) {
                        if (origin[oi + 2][oj + 2] != 0) { // 비율이 있는경우
                            if ((next.y + oi >= 0 && next.y + oi < N) && (next.x + oj >= 0 && next.x + oj < N))  map[next.y + oi][next.x + oj] += map[next.y][next.x] * origin[oi + 2][oj + 2];
                            else answer += map[next.y][next.x] * origin[oi + 2][oj + 2];

                            tmp += map[next.y][next.x] * origin[oi + 2][oj + 2];
                        }
                    }
                }
                
                if ((next.y + dir[dirIdx].y  >= 0 && next.y + dir[dirIdx].y < N) && (next.x + dir[dirIdx].x >= 0 && next.x + dir[dirIdx].x < N)) map[next.y + dir[dirIdx].y][next.x + dir[dirIdx].x] += map[next.y][next.x] - tmp;
                else answer += map[next.y][next.x] - tmp;
                now.y = next.y; now.x = next.x;

                map[now.y][now.x] = 0;
            }

            if (now.y == 0 && now.x == 0) break;
            // ==== 다음 turn 으로 돌기 위해 방향 전환 및 비율 회전
            ++dirIdx %= 4;
            rotate();
        }
    }
    cout << answer << endl;
}

void rotate() {
    vector<vector<double> > temp(5, vector<double>(5, 0));

    // cp
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) temp[i][j] = origin[i][j];
    }

    // rotate
    for (int i = 0;  i  < 5; i++) {
        for (int j = 0; j < 5; j++) origin[4 - j][i] = temp[i][j];
    }
}