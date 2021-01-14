#include <iostream>
#include<queue>
using namespace std;
//11399

int main(){
	int n, cnt = 0, result = 0;
	int tmp;
	priority_queue<int, vector<int>, greater<int> > pq;
	cin >> n;

	while(n--){
		cin >> tmp;
		pq.push(tmp);
	}

	while (!pq.empty()){
		cnt += pq.top();
		result += cnt;
		pq.pop();
	}

	cout << result << endl;
}
