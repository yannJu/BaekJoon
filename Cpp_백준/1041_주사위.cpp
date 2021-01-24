#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long N, mn_1, mn_2, mn_3; 
	long long result;
	long long diceNum[6] = {0,};
	long long mnAry[3] = {0,};
	cin >> N;

	for (int i = 0; i < 6; i++) cin >> diceNum[i];

	if (N == 1){
		result = 0;
		sort(diceNum, diceNum + 6);
		for (int i = 0; i < 5; i++) result += diceNum[i];
		cout << result << endl;
		return 0;
	}

	mnAry[0] = min(diceNum[0], diceNum[5]);
	mnAry[1] = min(diceNum[1], diceNum[4]);
	mnAry[2] = min(diceNum[2], diceNum[3]);
	sort(mnAry, mnAry + 3);

	mn_1 = (4 * (N - 1) * (N - 2)) + ((N - 2) * (N - 2)); //1개 보이는 면의 수
	mn_2 =(8 * N - 12); //2개 보이는 면의 수
	mn_3 = 4; //3개 보이는 면의 수

	mn_1 *= mnAry[0];
	mn_2 *= (mnAry[0] + mnAry[1]);//2개 보이는 면의 수
	mn_3 *= (mnAry[0] + mnAry[1] + mnAry[2]); //3개 보이는 면의 수

	cout << mn_1 + mn_2 + mn_3 << endl;
}
