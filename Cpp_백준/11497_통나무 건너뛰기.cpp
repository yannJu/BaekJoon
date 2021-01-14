#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int cNum, n, h, d, mx; //테스트케이스, 통나무수, 높이, 차이, 최대값
	vector<int> v, resultV;
	cin >> cNum; //cNum개의 테스트 케이스
	while(cNum--){
		mx = -1; //mx초기화
		cin >> n; //통나무의 개수
		for (int i = 0; i < n; i++){
			cin >> h; //통나무 높이
			v.push_back(h); //vector에 높이 넣기
		}

		sort(v.begin(), v.end());
		for (int i = 2; i < n; i++){
			d = v.at(i) - v.at(i - 2);
			if (d > mx) mx = d;
		}
		cout << mx << endl;
		v.clear();
	}
}
