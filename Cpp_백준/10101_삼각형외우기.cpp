#include <iostream>
#include <set>
using namespace std;

int main(){
	int i;
	int angle;
	int result = 0;
	int size;
	set<int> s;

	for (i = 0; i < 3; i++){
		cin >> angle;
		s.insert(angle);		
		result += angle;
	}

	size = s.size();
	if (result == 180){
		if (size < 3){
			if (size == 1) cout << "Equilateral" << endl;
			else cout << "Isosceles" << endl;
		}
		else cout << "Scalene" << endl;
	}
	else cout << "Error" << endl;
}
