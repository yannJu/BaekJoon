/*
문제
N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다. 각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다. 인접한 나라 사이에는 국경선이 존재한다. 모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.

오늘부터 인구 이동이 시작되는 날이다.

인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.

국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
연합을 해체하고, 모든 국경선을 닫는다.
각 나라의 인구수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, L, R이 주어진다. (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)

둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 ≤ A[r][c] ≤ 100)

인구 이동이 발생하는 일수가 2,000번 보다 작거나 같은 입력만 주어진다.

출력
인구 이동이 며칠 동안 발생하는지 첫째 줄에 출력한다.

예제 입력 1 
2 20 50
50 30
20 40
예제 출력 1 
1
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

int main() {
    int N, L, R;

    cin >> N >> L >> R;
    vector<vector<int>> map(N, vector<int>(N, 0));

    // setting map
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> map[i][j];
    }

    int answer = 0;
    while(true) {
        vector<vector<int>> visit(N, vector<int>(N, 0));
        vector<pair<int, int>> memo(1, {-1, -1}); // cnt, num_sum

        int turn = 0;
        // 마을 탐색(turn)
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                queue<pair<int, int>> q;
                if (visit[i][j] == 0) {
                    turn += 1;
                    q.push({i, j});
                    memo.push_back({0, 0});
                }

                while(!q.empty()) {
                    pair<int, int> now = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int next_y = now.first + dir[d].y, next_x = now.second + dir[d].x;

                        if ((next_y >= 0 && next_y < N) && (next_x >= 0 && next_x < N)) {
                            if ((abs(map[now.first][now.second] - map[next_y][next_x]) >= L) && (abs(map[now.first][now.second] - map[next_y][next_x]) <= R)) {
                                if (visit[now.first][now.second] == 0) {
                                    visit[now.first][now.second] = turn;
                                    memo[turn].first += 1;
                                    memo[turn].second += map[now.first][now.second];
                                }  // 현재 좌표가 여태까지 좌우에 인접한 마을이 없었을 경우]
                                if (visit[next_y][next_x] == 0) {
                                    visit[next_y][next_x] = turn;
                                    memo[turn].first += 1;
                                    memo[turn].second += map[next_y][next_x];
                                    q.push({next_y, next_x});
                                } // 인접한 좌표가 여태까지 좌우에 인접한 마을이 없었을 경우
                            }
                        }
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 1; i < memo.size(); i++) {
            cnt += memo[i].first;
            if (memo[i].first > 0) {
                int avg = memo[i].second / memo[i].first;

                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        if (visit[j][k] == i) map[j][k] = avg;
                    }
                }
            }
        }
        if (cnt == 0) break;
        else answer += 1;
    }

    cout << answer << endl;
    return 0;
}