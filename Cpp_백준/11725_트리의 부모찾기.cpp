#include <stdio.h>
#include <vector>
using namespace std;

vector<int> *graph;
int *visit,  *parent;

void dfs(int node){
	if (!visit[node]){
		visit[node] = 1;
		for (int i =0; i < graph[node].size(); i++){
			if (!visit[graph[node].at(i)]){			
				parent[graph[node].at(i)] = node;
				dfs(graph[node].at(i));
			}
		}
	}
}

int main(){
	int n, tmp1, tmp2;
	scanf("%d", &n);
	
	graph = new vector<int>[n + 1];
	visit = new int[n + 1];
	parent = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
		parent[i] = 0;
	}

	for (int i = 0; i < n - 1; i++){
		scanf("%d %d", &tmp1, &tmp2);
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	dfs(1);
	for (int i = 2; i <= n; i++) printf("%d\n", parent[i]);
}
