#include <iostream>
#include <string>
using namespace std;

int main(){
	int num; //n번째 영화
	int r = 0;  //1부터 n까지 돌 변수
	int cnt = 666; //666, 1666, ..., n666, ....
	string str_cnt = to_string(cnt);

	cin >> num;

	while (1){
		if (str_cnt.find("666") != string::npos) r+= 1;

		if (r == num) {
			cout << cnt << endl;
			break;
		}
		cnt += 1;
		str_cnt = to_string(cnt);
	}
}
