#include <iostream>
using namespace std;

int main(){
	int num;
	int arr[8] = {2, 1, 2, 3, 4, 5, 4, 3};

	cin >> num;
	num %= 8;

	cout << arr[num] << endl;	
}
