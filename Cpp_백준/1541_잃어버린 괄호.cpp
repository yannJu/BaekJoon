#include<iostream>
#include<string>
using namespace std;

int main(){
	string allstr, tmp = "";
	int result = 0, isMinus = 0;

	cin >> allstr;

	for (char c : allstr){
		if (c == '-' || c == '+'){
			if (isMinus) result -= stoi(tmp);
			else result += stoi(tmp);

			if (c == '-') isMinus = 1;
			tmp = "";
		}
		else tmp += c;
	}

	if (isMinus) result -= stoi(tmp);
	else result += stoi(tmp);
	cout << result << endl;
}
