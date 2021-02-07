#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct dir{
	int x;
	int y;
};

dir D[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
vector<int> *graph;
vector<string> result;
vector<int> v;
int cnt;

void dfs(int nodex, int nodey){
	int tmpNum, tmpVisit;

	tmpNum = graph[nodey].at(nodex);

	cnt += 1;
	v.push_back(tmpNum);

	if (cnt == 6) {
		//cout << v.size() << endl;
		string answer = "";
		for (int n = 0; n < v.size(); n++) answer += to_string(v.at(n));
		result.push_back(answer);
		//cout << "x ; " << nodex << " y ; " << nodey << " answer : " << answer << " cnt ; " << cnt << endl;
	}
	else{
		for (int d = 0; d < 4; d++){
			if (nodex + D[d].x >= 0 && nodex + D[d].x < 5 && nodey + D[d].y >= 0 && nodey + D[d].y < 5) {
				//cout << "x ; " << nodex << " y ; " << nodey << " size : " << v.size() << " cnt : " << cnt << endl;
				dfs(nodex + D[d].x, nodey + D[d].y);
				v.pop_back();
				cnt -= 1;
			}
		}
	}
}

int main(){
	int tmp;
	
	graph = new vector<int>[5];
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			cin >> tmp;
			graph[i].push_back(tmp);
		}
	}
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			v.clear();
			cnt = 0;
			dfs(i, j);
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	cout << result.size() << endl;
}
