/*
정수 삼각형 다국어
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	128 MB	68999	39098	29407	58.855%
문제
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 
이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 
아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

예제 입력 1 
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
예제 출력 1 
30
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<vector<int> > v, ckV;

    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> tmp, ckTmp;
        for (int j = 0; j <= i; j++) {
            int tmpI;
            cin >> tmpI;
            tmp.push_back(tmpI);
            ckTmp.push_back(0);
        }
        v.push_back(tmp);
        ckV.push_back(ckTmp);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0) ckV[i][j] = v[i][j];
            else if (j == 0) ckV[i][j] = v[i][j] + ckV[i - 1][j];
            else if (j == i) ckV[i][j] = v[i][j] + ckV[i - 1][j - 1];
            else ckV[i][j] = max(ckV[i - 1][j], ckV[i - 1][j -1]) + v[i][j];
        }
    }

    int result = -1;
    for (int i = 0; i < n; i++) result = max(result, ckV[n - 1][i]);

    cout << result << endl;
}