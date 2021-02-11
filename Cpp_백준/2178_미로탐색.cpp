#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Dir{
    int x;
    int y;
};

Dir D[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
vector<int> *graph, *visit;
queue<Dir> q;
int n , m; //n : height , m : width

void bfs(int nodex, int nodey){
    Dir t;

    q.push({nodex, nodey});
    visit[nodey].at(nodex) = 1;
    while(!q.empty()){
        t = q.front();
        for (int i = 0; i < 4; i++){
            if (t.x + D[i].x >= 0 && t.x + D[i].x < m && t.y + D[i].y >= 0 && t.y + D[i].y < n){
                if (visit[t.y + D[i].y].at(t.x + D[i].x) == -1 && graph[t.y + D[i].y].at(t.x + D[i].x) == 1){
                    q.push({t.x + D[i].x, t.y + D[i].y});
                    visit[t.y + D[i].y].at(t.x + D[i].x) = visit[t.y].at(t.x) + 1;
                }
            }
        }
        q.pop();
    }
}

int main(){
    string tmp;

    cin >> n >> m;
    graph = new vector<int>[n];
    visit = new vector<int>[n];

    for (int i = 0; i < n; i++){
        cin >> tmp;
        for (int j = 0; j < m; j++){
            visit[i].push_back(-1);
            graph[i].push_back(tmp[j] - '0');
        }
    }

    bfs(0, 0);
    cout << visit[n - 1].at(m - 1) << endl;
}