/*
최단경로
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	183544	54788	27833	25.274%
문제
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

입력
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1 ≤ K ≤ V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.

출력
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

예제 입력 1 
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
예제 출력 1 
0
2
3
7
INF
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stdio.h>
using namespace std;

struct compare {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if (a.second > b.second) return true;
        else return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    int start;

    cin >> V >> E >> start;
    vector<vector<pair<int, int>>> graph;
    vector<int> weights(V, INT_MAX);

    for (int i = 0; i < V; i++) {
        vector<pair<int, int>> tmp;
        graph.push_back(tmp);
    }
    for (int i = 0; i < E; i++) {
        int u, v, w;

        cin >> u >> v >> w;
        graph[u -1].push_back({v - 1, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> q;
    q.push({start - 1, 0});
    weights[start - 1] = 0;
    while(!q.empty()) {
        pair<int, int> node = q.top();
        q.pop();
        if (weights[node.first] < node.second) continue;

        for (int j = 0; j < graph[node.first].size(); j++) {
            if (node.second + graph[node.first][j].second < weights[graph[node.first][j].first]) {
                weights[graph[node.first][j].first] = node.second + graph[node.first][j].second;
                q.push({graph[node.first][j].first, node.second + graph[node.first][j].second});
            }
        }
    }

    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] == INT_MAX) cout << "INF" << endl;
        else cout << weights[i] << endl;
    }
}