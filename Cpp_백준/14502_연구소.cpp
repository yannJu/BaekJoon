/*
문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 

일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

2 1 0 0 1 1 2
1 0 1 0 1 2 2
0 1 1 0 1 2 2
0 1 0 0 0 1 2
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.

연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct DIR {
    int y;
    int x;
};
DIR *dir = new DIR[4]{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int* answer, vector<vector<int>> &map, vector<vector<int>> &visit, int col, int row, int cnt);
int main() {
    int N, M;

    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0)), visit(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> map[i][j];
    }

    int answer = 0;
    dfs(&answer, map, visit, 0, 0, 0); // 결과값, map, visit, col, row, 벽이 설치된 수

    cout << answer << endl;
    return 0;
}

void dfs(int* answer, vector<vector<int>> &map, vector<vector<int>> &visit, int col, int row, int cnt) {
    if (cnt == 3) {
        int safe_cnt = 0;
        //bfs 돌려야됌
        vector<vector<int>> cp_map(map.size(), vector<int>(map[0].size(), 0));

        // init cp_map(map copy)
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); j++) cp_map[i][j] = map[i][j];
        }

        // bfs _  set safe zone
        queue<pair<int,int>> q;
        for (int i = 0; i < cp_map.size(); i++) {
            for (int j = 0; j < cp_map[0].size(); j++) {
                if (cp_map[i][j] == 2) { // 바이러스 존재
                    q.push({i, j});
                    while(!q.empty()) {
                        pair<int, int> now = q.front();
                        q.pop();

                        int next_y, next_x;
                        for (int i = 0; i < 4; i++) {
                            next_y = now.first + dir[i].y; next_x = now.second + dir[i].x;
                            if ((next_y >= 0 && next_y < cp_map.size()) && (next_x >= 0 && next_x < cp_map[0].size())) {
                                if (cp_map[next_y][next_x] == 0) {
                                    cp_map[next_y][next_x] = 2;
                                    q.push({next_y, next_x});
                                }
                            }
                        }
                    }
                }
            }
        }

        // count safe zone
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[i].size(); j++) {
                if (cp_map[i][j] == 0) safe_cnt += 1;
            }
        }

        answer[0] = max(answer[0], safe_cnt);
        return;
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (visit[i][j] == 0  && map[i][j] == 0) {
                map[i][j] = 1;
                visit[i][j] == 1;
                dfs(answer, map, visit, i, j, cnt + 1);
                map[i][j] = 0;
                visit[i][j] == 0;
            } 
        }
    }
}