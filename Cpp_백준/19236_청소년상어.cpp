#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DIR {
    int y;
    int x;
};
DIR *dirs = new DIR[8]{{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

bool compare(pair<int, DIR> a, pair<int, DIR> b) {
    if (a.first < b.first) return true;
    else return false;
}

void dfs(int *answer, vector<vector<pair<int, int>>> &map, vector<pair<int, DIR> > &fishes, int shark_y, int shark_x, int cost);
int main() {
    vector<vector<pair<int, int>>> map;
    vector<pair<int, DIR> > fishes; // 물고기 번호, 위치
    int answer = -1;
    pair<DIR, int> shark = {{0, 0}, -1}; // 현재 장소, 방향번호
    
    // init Map
    for (int i = 0; i < 4; i++) {
        vector<pair<int, int>> tmp;
        for (int j = 0; j < 4; j++) {
            int n, d;

            cin >> n >> d;
            tmp.push_back(make_pair(n - 1, d - 1));
            fishes.push_back({n - 1, {i, j}});
        }
        map.push_back(tmp);
    }
    sort(fishes.begin(), fishes.end(), compare);
 
    dfs(&answer, map, fishes, 0, 0, 0);
    cout << answer << endl;

    return 0;
}

void dfs(int *answer, vector<vector<pair<int, int>>> &map, vector<pair<int, DIR> > &fishes, int shark_y, int shark_x, int cost) {
    vector<vector<pair<int, int>>> cp_map(4, vector<pair<int, int>>(4, make_pair(-1, -1)));
    vector<pair<int, DIR>> cp_fishes(16, {-1, {-1, -1}});

    // init cp_map
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) cp_map[i][j] = map[i][j];
    }
    // init cp_fishes
    for (int i = 0; i < 16; i++) cp_fishes[i] = fishes[i];

    // catch fish
    int now_cost = (cost + cp_map[shark_y][shark_x].first) + 1;
    answer[0] = max(answer[0], now_cost);
    cp_fishes[cp_map[shark_y][shark_x].first].first = -1; // 물고기 잡아먹힘

    // move fishes
    for (int i = 0; i < 16; i++) {
        int alive = cp_fishes[i].first; // 현재의 물고기가 살아있는지 (살아있지 않다면 -1)
        if (alive == - 1) continue; // 물고기가 살아있지 않다면

        DIR fish_xy = cp_fishes[i].second; // 현재 물고기 좌표
        int fish_dir = cp_map[fish_xy.y][fish_xy.x].second; // 현재 물고기의 방향 인덱스

        // 물고기가 살아있다면
        for (int j = 0; j < 8; j++) {
            int next_y = fish_xy.y + dirs[(fish_dir + j) % 8].y, next_x = fish_xy.x + dirs[(fish_dir + j) % 8].x; // 현재 물고기가 이동할 좌표

            if ((next_y >= 0 && next_y < 4) && (next_x >= 0 && next_x < 4)) {
                if ((next_y != shark_y) || (next_x != shark_x)) {
                    int change_fish_num = cp_map[next_y][next_x].first; // 바꿀 좌표의 물고기 번호
                    int change_fish_dir = cp_map[next_y][next_x].second; // 바꿀 좌표의 물고기 방향
                    
                    cp_fishes[i].second = {next_y, next_x}; cp_fishes[change_fish_num].second = fish_xy; // 물고기 좌표 할당
                    cp_map[next_y][next_x] = make_pair(i, ((fish_dir + j) % 8)); // 바꿀 물고기의 좌표에 현재 물고기 번호와 바뀐 방향 할당
                    cp_map[fish_xy.y][fish_xy.x] = make_pair(change_fish_num, change_fish_dir); // 현재 물고기의 좌표에 바꿀 물고기의 번호와 방향 할당
                    break;  
                }
            }
        }
    }

    // move shark
    for (int i = 1; i < 4; i++) {
        int next_y = shark_y + (dirs[cp_map[shark_y][shark_x].second].y * i);
        int next_x = shark_x + (dirs[cp_map[shark_y][shark_x].second].x * i);

        if ((next_y < 4 && next_y >= 0) && (next_x < 4 && next_x >= 0)) {
            if (cp_fishes[cp_map[next_y][next_x].first].first >= 0) dfs(answer, cp_map, cp_fishes, next_y, next_x, now_cost);
        }
        else break;
    } 
}