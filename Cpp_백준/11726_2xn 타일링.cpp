#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	vector<int> v;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		if (i < 2) v.push_back((i + 1) % 10007);
		else {
			v.push_back((v.at(i - 1) + v.at(i - 2)) % 10007);
		}
	}

	cout << v.at(n - 1) << endl;
}
