#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> s;
vector<int> *graph;
int *visit, *depth, cnt;

void dfs(int node){
	visit[node] = 1;

	for (int i = 0; i < graph[node].size(); i++){
		if (!visit[graph[node].at(i)]) {
			cnt += 1;
			dfs(graph[node].at(i));
		}	
	}
}	

int main(){
	int n, m; //n : computers, m : connects
	int tmp1, tmp2, mx = -1;
	
	cin >> n >> m;
	graph = new vector<int>[n + 1];
	visit = new int[n + 1];
	depth = new int[n + 1];

	for (int i = 0; i <= n; i++) depth[i] = 0;
	while(m--){
		cin >> tmp1 >> tmp2;
		graph[tmp2].push_back(tmp1);
		visit[tmp2] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) visit[j] = 0;
			if (graph[i].size()) {
				cnt = 0;
				dfs(i);
				depth[i] = cnt;
				if (cnt > mx) mx = cnt;
			}
	}
	 
	for (int i = 1; i <= n; i++) {
		if (depth[i] == mx) cout << i << " ";
	}
	cout << endl;
}
