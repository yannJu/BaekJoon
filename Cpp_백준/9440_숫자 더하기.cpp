#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	char tmp, cntZero = 0;
	string num1, num2;
	vector<char> v;
	while(true){
		num1 = "";
		num2 = "";
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			if (tmp == '0') cntZero += 1;
			else v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n / 2; i++){
			if (cntZero > 0 && !num1.empty()) {
				num1 += '0';
				cntZero -= 1;
			}
			else {
				num1 += v.front();
				v.erase(v.begin());
			}
			if (cntZero > 0 && !num2.empty()) {
				num2 += '0';
				cntZero -= 1;
			}
			else {
				num2 += v.front();
				v.erase(v.begin());
			}
		}
		if (!v.empty()) {
			num1 += v.front();
			v.erase(v.begin());
		}
		if (cntZero > 0){
			num1 += '0';
			cntZero -= 1;
		}

		cout << stoi(num1) + stoi(num2) << endl;
	}
}
