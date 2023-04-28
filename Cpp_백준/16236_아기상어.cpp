/*
아기 상어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	512 MB	50892	23190	13803	42.075%
문제
N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다. 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 칸에는 물고기가 최대 1마리 존재한다.

아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다. 가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다. 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다. 즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 칸은 빈 칸이 된다.

아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 공간의 크기 N(2 ≤ N ≤ 20)이 주어진다.

둘째 줄부터 N개의 줄에 공간의 상태가 주어진다. 공간의 상태는 0, 1, 2, 3, 4, 5, 6, 9로 이루어져 있고, 아래와 같은 의미를 가진다.

0: 빈 칸
1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
9: 아기 상어의 위치
아기 상어는 공간에 한 마리 있다.

출력
첫째 줄에 아기 상어가 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는 시간을 출력한다.

예제 입력 1 
3
0 0 0
0 0 0
0 9 0
예제 출력 1 
0
예제 입력 2 
3
0 0 1
0 0 0
0 9 0
예제 출력 2 
3
예제 입력 3 
4
4 3 2 1
0 0 0 0
0 0 9 0
1 2 3 4
예제 출력 3 
14
예제 입력 4 
6
5 4 3 2 3 4
4 3 2 3 4 5
3 2 9 5 6 6
2 1 2 3 4 5
3 2 1 6 5 4
6 6 6 6 6 6
예제 출력 4 
60
예제 입력 5 
6
6 0 6 0 6 1
0 0 0 0 0 2
2 3 4 5 6 6
0 0 0 0 0 2
0 2 0 0 0 0
3 9 3 0 0 1
예제 출력 5 
48
예제 입력 6 
6
1 1 1 1 1 1
2 2 6 2 2 3
2 2 5 2 2 3
2 2 2 4 6 3
0 0 0 0 0 6
0 0 0 0 0 9
예제 출력 6 
39
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define vii vector<vector<int>> 
using namespace std;

struct DIR {
    int y, x;
    DIR(int _y, int _x): y(_y), x(_x) {};
};
DIR dir[4] = {
    DIR(-1, 0), //up
    DIR(0, -1), // left
    DIR(0, 1), //right
    DIR(1, 0) // down
};

struct compare {
    bool operator() (pair<DIR, int> a, pair<DIR, int> b) {
        if (a.second > b.second) return true;
        else if (a.second == b.second) {
            DIR aD = a.first, bD = b.first;

            if (aD.y > bD.y) return true;
            else if (aD.y == bD.y) {
                if (aD.x > bD.x) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
};

int main() {
    int N, answer = 0;
    queue<DIR> q;
    cin >> N;

    vii map(N, vector<int>(N, 0));
    for (int i =0; i < N; i++) {
        for (int j =0; j < N; j++) {
            cin >> map[i][j];
            
            if (map[i][j] == 9) {
                map[i][j] = 0;
                q.push(DIR(i, j));
            }
        }
    }

    int size = 2, eat = 0;
    while(!q.empty()) {
        priority_queue<pair<DIR, int> , vector<pair<DIR, int> >, compare> fishes;
        queue<DIR> bfsQ;
        vii ck(N, vector<int>(N, -1));
        // 상어 현재위치 꺼내기
        DIR now = q.front();
        q.pop();
        // 현재 위치 탐색 Queue에 넣기
        bfsQ.push(now);
        ck[now.y][now.x] = 0;
        // BFS 로 탐색하며 이동할  수 있는 좌표 담기
        while(!bfsQ.empty()) {
            DIR nowXY = bfsQ.front();
            bfsQ.pop();

            for (int i = 0; i < 4; i++) {
                DIR nextXY(nowXY.y + dir[i].y, nowXY.x + dir[i].x);

                if ((nextXY.y >= 0 && nextXY.y < N) && (nextXY.x >= 0 && nextXY.x < N)) {
                    if (map[nextXY.y][nextXY.x] <= size) {
                        // 이동이 가능한 경우
                        if (ck[nextXY.y][nextXY.x] == -1) {
                            ck[nextXY.y][nextXY.x] = ck[nowXY.y][nowXY.x] + 1;
                            bfsQ.push(DIR(nextXY.y, nextXY.x));

                            // 먹을 수 있다면 . . . fishes 에 담자
                            if (map[nextXY.y][nextXY.x] < size  && map[nextXY.y][nextXY.x] > 0)  {
                                fishes.push(make_pair(DIR(nextXY.y, nextXY.x), ck[nextXY.y][nextXY.x])); // 다음좌표와 거리를 계산해서 push
                            }
                        }
                        else ck[nextXY.y][nextXY.x] = min(ck[nowXY.y][nowXY.x] + 1, ck[nextXY.y][nextXY.x]);
                    }
                }
            }
        }

        if (fishes.size() == 0) break;
        pair<DIR, int> state = fishes.top();
        // eat ====
        DIR next(state.first);
        eat += 1;
        map[next.y][next.x] = 0;

        if (eat == size) {
            eat = 0;
            size += 1;
        }
        q.push(next);
        answer += state.second;
    }

    cout << answer << endl;
}