/*
그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.

최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.

입력
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.

그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int u;
	int v;
	int c;
};

bool compare(Edge a, Edge b) {
	if (a.c < b.c) return true;
	else return false;
}

int get_parent(vector<int>& parent, int node);
void union_node(vector<int>& parent, int node_a, int node_b);
int main() {
	int V, E;
	long long answer = 0;

	cin >> V >> E;
	vector<int> parent(V + 1, 0);
	Edge* edges = new Edge[E];

	for (int i = 0; i <= V; i++) parent[i] = i;
	for (int i = 0; i < E; i++) {
		Edge tmp;
		cin >> tmp.u >> tmp.v >> tmp.c;
		edges[i] = tmp;
	}
	sort(edges, edges + E, compare);

	for (int e = 0; e < E; e++) {
		if (get_parent(parent, edges[e].u) != get_parent(parent, edges[e].v)) {
			answer += edges[e].c;
			union_node(parent, edges[e].u, edges[e].v);
		}
	}

	cout << answer << endl;
}

int get_parent(vector<int> &parent, int node) {
	if (parent[node] == node) return node;
	parent[node] = get_parent(parent, parent[node]);

	return parent[node];
}

void union_node(vector<int> &parent, int node_a, int node_b) {
	int a_parent = get_parent(parent, node_a);
	int b_parent = get_parent(parent, node_b);

	if (a_parent < b_parent) parent[b_parent] = a_parent;
	else parent[a_parent] = b_parent;
}