#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> *graph;
int *visit;
queue<int> q;

void dfs(int node){
    cout << node << " ";
    visit[node] = 1;
    for (int i = 0; i < graph[node].size(); i++){
        if (!visit[graph[node].at(i)]) dfs(graph[node].at(i));
    }
}

void bfs(int node){
    int t;
    q.push(node);
    visit[node] = 1;
    while (!q.empty()){
        t = q.front();
        cout << t << " ";
        for (int i = 0; i < graph[t].size(); i++){
            if (!visit[graph[t].at(i)]){
                visit[graph[t].at(i)] = 1;
                q.push(graph[t].at(i));
            }
        }
        q.pop();
    }
}

int main(){
    int n, m, v; // n : 정점의 개수, m : 간선의 개수, v : 시작 정점
    int tmp1, tmp2;
    cin >> n >> m >> v;

    graph = new vector<int>[n + 1];
    visit = new int[n + 1];

    while(m--){
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1); //양방향이기 때문에
    }

    for (int i = 1; i <= n; i++) {
        visit[i] = 0;
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout << endl;
    for (int i = 1; i <= n; i++) visit[i] = 0;
    bfs(v);
    cout << endl;
}