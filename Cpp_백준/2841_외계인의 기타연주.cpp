//2841
#include <iostream>
#include <stack>
using namespace std;

struct Line{
	stack<int> s;
};

int main(){
	int n, p, lineNum, pNum; //음의수, 프렛수, 줄번호, 프렛번호
	int cnt = 0;
	Line line[6]; 

	cin >> n >> p;

	while (n--){
		cin >> lineNum >> pNum;
		if (line[lineNum - 1].s.empty()) {
			cnt += 1;
			line[lineNum - 1].s.push(pNum);
		}
		else if (pNum == line[lineNum - 1].s.top()) continue;
		else if (pNum > line[lineNum - 1].s.top()) {
			cnt += 1;
			line[lineNum - 1].s.push(pNum);
		}
		else {
			while (line[lineNum - 1].s.top() > pNum){
				cnt += 1;
				line[lineNum - 1].s.pop();
				if (line[lineNum - 1].s.empty()) break;
			}
	
			if (line[lineNum - 1].s.empty()){
				cnt += 1;
				line[lineNum - 1].s.push(pNum);
				continue;
			}
			if (line[lineNum - 1].s.top() != pNum){
				cnt += 1;
				line[lineNum - 1].s.push(pNum);
			}
		}
	}
	cout << cnt << endl;
}
