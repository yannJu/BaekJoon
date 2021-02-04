#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int *visit, cnt = 0;
vector<int> *graph, one_graph;

void dfs(int node, vector<int>* g){
	for (int n : g[node]){
		if (!visit[n]){
			visit[n] = 1;
			dfs(n, g);
			cnt += 1;
		}
	}
}

int main(){
	int v, e; //바이러스 수, 연결된 수
	int n1, n2; 	
	
	cin >> v >> e;
	graph = new vector<int>[v + 1];
	visit = new int[v + 1];

	one_graph.push_back(1);
	while(e--){
		cin >> n1 >> n2;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
		if (n2 == 1) one_graph.push_back(n1);
	}
	
	for (int i = 1; i <= v; i++) {
		visit[i] = 0;
		sort(graph[i].begin(), graph[i].end());
	}
	visit[1] = 1;
	for (int i = 0; i < one_graph.size(); i++) dfs(one_graph.at(i), graph);
	cout << cnt << endl;
}
