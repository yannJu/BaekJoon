#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> *graph;
int *visitDepth;
queue<int> q;

void bfs(int node){
	int t;

	q.push(node);
	visitDepth[node] = 0;
	while (!q.empty()) {//queue가 빌때까지
		t = q.front();
		q.pop();
		for (int i = 0; i < graph[t].size(); i++){
			if (visitDepth[graph[t].at(i)] == -1) {
				visitDepth[graph[t].at(i)] = visitDepth[t] + 1;
				q.push(graph[t].at(i));
			}
		}
	}
}

int main(){
	int n, m, k, x; //n : 도시의 개수, m : 도로의 개수, k : 최단거리, x : 시작도시
	int tmp1, tmp2, answer = 0;
	cin >> n >> m >> k >> x;

	graph = new vector<int>[n + 1];
	visitDepth = new int[n + 1];

	for (int i = 0; i <= n; i++) visitDepth[i] = -1;
	while (m--) {
		cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
	}

	bfs(x);
	for (int i = 1; i <= n; i++){
		if (visitDepth[i] == k) {
			answer += 1;
			cout << i << endl;
		}
	} 
	if (answer == 0) cout << -1 << endl;
}
