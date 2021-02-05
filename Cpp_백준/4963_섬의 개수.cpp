#include <iostream>
#include <vector>
using namespace std;

vector<int> *graph, *visit;
int w, h, cnt, isVisit = 0;

struct dir
{
	int x;
	int y;
};

dir D[] = {{-1, -1}, {0, -1}, {1, -1}, {1,  0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};

void dfs(int x, int y){
	int tmpx, tmpy;
	//cout << x << " " << y << endl;
	if (!visit[y].at(x)){
		visit[y].at(x) = 1;
		if (graph[y].at(x)){
			if (!isVisit) {
				cnt += 1;
				//cout << "cnt : " << cnt << " x : " << x << " y : " << y << endl;
			}
			isVisit += 1;
			for (int i = 0; i < 8; i++){
				//cout << " I : " << i << endl;
				tmpx = x + D[i].x;
				tmpy = y + D[i].y;
				//cout << "tmpx : " << tmpx << " tmpy : " << tmpy << " x size : " << w << " y size : " << h<< endl;
				if ((tmpx > -1) && (tmpx < w) && (tmpy > -1) && (tmpy < h)) {
					dfs(tmpx, tmpy);
				}
			}
			isVisit -= 1;
		}
	}
}

int main(){
	int tmp; //width, height
	while(true){
		cin >> w >> h;
		if (w == 0 && h == 0) return 0;
		
		cnt = 0;

		//make arry
		graph = new vector<int>[h];
		visit = new vector<int>[h];

		//fill arry	
		for (int i = 0; i < h; i++){ 
			for (int j = 0; j < w; j++) {
				cin >> tmp;
				visit[i].push_back(0);
				graph[i].push_back(tmp);
			}
		}

		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++) {
				//cout << " i : " << i << " j : " << j << endl;
				dfs(j, i);
}
		}
		cout << cnt << endl;
	}
}
