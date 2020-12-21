#include <iostream>
using namespace std;

int main(){
	int N, M;
	cin >> N >> M;
	char ary[N][M], c, c_Old, old;
	int result = 0;

	for (int n = 0; n < N; n++){
		c_Old = 'a';
		for (int m = 0; m < M; m++){
			cin >> c;
			if ((c != '-') || (c != c_Old)) result += 1; 
			ary[n][m] = c;
			c_Old = c;
		}
	}
	
	for (int m = 0; m < M; m++){
		old = 'a';
		for (int n = 0; n < N; n++){
			if ((ary[n][m] == '|') && (old == '|')) result -= 1;
			old = ary[n][m];
		}
	}
	cout << result << endl;
}
