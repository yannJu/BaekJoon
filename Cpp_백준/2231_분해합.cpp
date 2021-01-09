#include <iostream>
#include <string>
using namespace std;

int main(){
	string num;
	int numInt, result, i;
	int cnt = 0;
	
	cin >> numInt;
	num = to_string(numInt);
	
	for (char n : num) {
		cnt += 1;
	}
	//cout << "cnt : " << cnt << endl;
	for (i = numInt - cnt * 9; i <= numInt; i++){
		result = 0;
		for (char n : to_string(i)){
			result += n - '0';
		}

		//cout << "i : " << i  << " result : " << result << " numInt : " << numInt << endl;
		if (i + result == numInt) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}
