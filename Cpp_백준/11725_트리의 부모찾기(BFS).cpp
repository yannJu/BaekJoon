#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> *graph;
int *visit, *parent;
queue<int> q;

void bfs(int node){
	int t;
	
	visit[node] = 0;
	q.push(node);
	while(!q.empty()){
		t = q.front();
		for (int i = 0; i < graph[t].size(); i++){
			if (visit[graph[t].at(i)] == -1){
				q.push(graph[t].at(i));
				visit[graph[t].at(i)]= visit[t] + 1;
				parent[graph[t].at(i)] = t;
			}
		}
		q.pop();
	}
}

int main(){
	int nodeNum, tmp1, tmp2;
	scanf("%d", &nodeNum);
	
	graph = new vector<int>[nodeNum + 1];
	visit = new int[nodeNum + 1];
	parent = new int [nodeNum + 1];

	for (int i = 0; i < nodeNum - 1; i++){
		scanf("%d %d", &tmp1, &tmp2);
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}
	for (int i = 1; i <= nodeNum; i++){
		visit[i] = -1;
		parent[i] = 0;
	}

	bfs(1);
	for (int i =2 ; i <= nodeNum; i++) printf("%d\n", parent[i]);
}
