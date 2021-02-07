#include <iostream>
#include <vector>
using namespace std;

struct Count{
	int cnt;
	int visit;
};

vector<int> *graph;
Count *COUNT;
int c, *v;

void dfs(int node){
	//cout << "node : " << node << " == " << graph[node].size() << endl;
	v[node] = 1;
	for (int i = 0; i < graph[node].size(); i++){
		if (!v[graph[node].at(i)]) {
			c += 1;
			dfs(graph[node].at(i));
			COUNT[graph[node].at(i)].visit += 1;
		}
	}
}

int main(){
	int n, m; // n: 구슬의 수 , m : 저울에 올려본 쌍의 수
	int tmp1, tmp2, answer = 0;
	cin >> n >> m;

	graph = new vector<int>[n + 1];
	COUNT = new Count[n + 1];
	v = new int[n + 1];

	for (int i = 1; i <= n; i++) COUNT[i] = {0, 0};
	while(m--){
		cin >> tmp1 >> tmp2;
		graph[tmp2].push_back(tmp1);
	}

	for (int i = 1; i <= n; i++) {
		c = 0;
		for (int j = 1; j <= n; j++) v[j] = 0;
		dfs(i);
		COUNT[i].cnt = c;
	}

	for (int i = 1; i <= n; i++){
		if (COUNT[i].cnt > n / 2 || COUNT[i].visit > n / 2) answer += 1;
	}

	cout << answer << endl;
}
