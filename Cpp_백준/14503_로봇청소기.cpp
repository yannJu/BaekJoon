/*
로봇 청소기
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	512 MB	44483	24156	16143	53.578%
문제
로봇 청소기가 주어졌을 때, 청소하는 영역의 개수를 구하는 프로그램을 작성하시오.

로봇 청소기가 있는 장소는 N×M 크기의 직사각형으로 나타낼 수 있으며, 1×1크기의 정사각형 칸으로 나누어져 있다. 각각의 칸은 벽 또는 빈 칸이다. 청소기는 바라보는 방향이 있으며, 이 방향은 동, 서, 남, 북중 하나이다. 지도의 각 칸은 (r, c)로 나타낼 수 있고, r은 북쪽으로부터 떨어진 칸의 개수, c는 서쪽으로 부터 떨어진 칸의 개수이다.

로봇 청소기는 다음과 같이 작동한다.

현재 위치를 청소한다.
현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
로봇 청소기는 이미 청소되어있는 칸을 또 청소하지 않으며, 벽을 통과할 수 없다.

입력
첫째 줄에 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 50)

둘째 줄에 로봇 청소기가 있는 칸의 좌표 (r, c)와 바라보는 방향 d가 주어진다. d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽을 바라보고 있는 것이다.

셋째 줄부터 N개의 줄에 장소의 상태가 북쪽부터 남쪽 순서대로, 각 줄은 서쪽부터 동쪽 순서대로 주어진다. 빈 칸은 0, 벽은 1로 주어진다. 지도의 첫 행, 마지막 행, 첫 열, 마지막 열에 있는 모든 칸은 벽이다.

로봇 청소기가 있는 칸의 상태는 항상 빈 칸이다.

출력
로봇 청소기가 청소하는 칸의 개수를 출력한다.

예제 입력 1 
3 3
1 1 0
1 1 1
1 0 1
1 1 1
예제 출력 1 
1
예제 입력 2 
11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
예제 출력 2 
57
*/

#include <iostream>
#include <vector>
#define vii vector<vector<int> >
using namespace std;

vii DIR(4, vector<int>(3, 0));
void ckClean(vii* MAP, int r, int c, int d, int* result, int isclean);
int main() {
    int n, m; //세로, 가로
    int r, c, d; //북쪽으로 부터 떨어진 정도, 서쪽으로 부터 떨어진 정도(즉 y, x), 방향 -> 동서남북(1320)
    int result = 0;

    cin >> n >> m;
    cin >> r >> c >> d;
    vii map(n, vector<int>(m, 0));
    
    DIR[0][0] = -1; DIR[0][1] = 0; DIR[0][2] = 3; // 방향이 북일경우 서쪽을 바라보게 됨
    DIR[1][0] = 0; DIR[1][1] = 1; DIR[1][2] = 0; // 방향이 동일경우 북쪽을 바라보게 됨
    DIR[2][0] = 1; DIR[2][1] = 0; DIR[2][2] = 1; // 방향이 남일경우 동쪽을 바라보게 됨
    DIR[3][0] = 0; DIR[3][1] = -1; DIR[3][2] = 2; // 방향이 서일경우 남쪽을 바라보게 됨

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> map[i][j];
    }

    ckClean(&map, r, c, d, &result, 1);
    cout << result << endl;
}

void ckClean(vii* MAP, int r, int c, int d, int* result, int isclean) {
    vii map = *MAP;
    int dir = d, y = r, x = c, n = map.size(), m = map[0].size(), cnt = 0;
    int nextY, nextX, nextDir;

    if (isclean == 1) {
        map[y][x] = -1; // 후진해서 온게 아니면 청소
        result[0] += 1;
    } 
    int i = 0;
    for (i; i < 4; i++) {
        // cout << y << " " << x << "  dir : " << dir << " CN T "   << cnt << " result : " << result[0] << endl;
        nextDir = DIR[dir][2];
        nextX = x + DIR[nextDir][1];  nextY = y + DIR[nextDir][0]; 
        // cout << "next :  " << nextY << " " << nextX << "  I : " << i << endl;
        if (cnt == 4) {
            nextY =  y + (DIR[dir][0] * -1); nextX = x + (DIR[dir][1] * -1); // 후진 하는 좌표
            if ((nextY >= 0 && nextY < n) && (nextX >= 0 && nextX < m)) {
                if (map[nextY][nextX] == 1) return; // 4방향 모두 청소 or 벽이면서 뒤쪽이 벽인 경우 작동 멈춤
                else { // 후진이 가능한 경우
                    i = 0; // 2번으로 돌아간다.
                    x = nextX; y = nextY; // 후진
                    cnt = 0;
                }
            }
            else return; 
        }
        else {
            if ((nextY >= 0 && nextY < n) && (nextX >= 0 && nextX < m)) {
                if (map[nextY][nextX] == 0) {
                    ckClean(&map, nextY, nextX, nextDir, result, 1); // 청소가 가능한 경우 1번부터 다시 진행
                    break;
                }
                else if (map[nextY][nextX] != 0) {
                    cnt += 1;
                    dir = nextDir; //방향회전
                    i = 0; // 2번으로 돌아간다.
                }
            }
            else cnt += 1;
        }
    }
}