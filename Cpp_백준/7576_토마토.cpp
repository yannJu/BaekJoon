#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Dir{
	int x;
	int y;
};

Dir D[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
vector<int> *graph, *visit;
queue<Dir> q;
int m, n, cntZero = 0;

int bfs(){
	Dir t;
	int mx = -100;

	while(!q.empty()){
		t = q.front();
		for (int i = 0 ; i < 4; i++){
			if (t.x + D[i].x >= 0 && t.x + D[i].x < m && t.y + D[i].y >= 0 && t.y + D[i].y < n){
				if (!graph[t.y + D[i].y].at(t.x + D[i].x) && visit[t.y + D[i].y].at(t.x + D[i].x) == -1) {
					cntZero -= 1;
					q.push({t.x + D[i].x, t.y + D[i].y});
					visit[t.y + D[i].y].at(t.x + D[i].x) = visit[t.y].at(t.x) + 1;
					if (	visit[t.y + D[i].y].at(t.x + D[i].x) > mx) mx = visit[t.y + D[i].y].at(t.x + D[i].x);
				}
			}//dir range
		}
		q.pop();
	}

	return mx;
}

int main(){
	int tmp;
	int startx, starty, mx;
	scanf("%d %d", &m, &n);

	graph = new vector<int>[n];
	visit = new vector<int>[n];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d", &tmp);
			if (tmp == 1) {
				q.push({j, i});
				visit[i].push_back(0);
			}
			else {
				if (tmp == 0) cntZero += 1;
				visit[i].push_back(-1);
			}
			graph[i].push_back(tmp);
		}
	}
	if (!cntZero) {
		if (q.empty()) printf("%d\n", -1);
		else printf("%d\n", 0);
		return 0;
	}
	mx = bfs();
	if (!cntZero) printf("%d\n", mx);
	else printf("%d\n", -1);
}
