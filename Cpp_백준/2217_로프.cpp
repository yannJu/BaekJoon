#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//2217

int main(){
	int n, tmp;
	vector<int> v;
	int mx = -1;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int j = 1; j <= n; j++){
		if (j * v.at(n - j) > mx) mx = j * v.at(n - j);
	}

	cout << mx << endl;
}
