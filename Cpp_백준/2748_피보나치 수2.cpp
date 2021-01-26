#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	vector<long long> v;
	cin >> n;
	for (int i = 0; i < n; i++){
		if (i < 2) v.push_back(1);
		else v.push_back(v.at(i - 1) + v.at(i - 2));
	}

	cout << v.at(n - 1) << endl;
}
