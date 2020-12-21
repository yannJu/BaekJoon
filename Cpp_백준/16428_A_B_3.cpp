#include <iostream>
using namespace std;

int a, b;

int cal(int y){
	return (a - y) % b;
}

int main(){
	int x, y = 0;
	
	cin >> a >> b;
	while (cal(y) != 0){
		y += 1;
	}
	x = (a - y) / b;
	cout << x << endl << y << endl;
}
