/*
문제
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

예제 입력 1 
3
26 40 83
49 60 57
13 89 99
예제 출력 1 
96
예제 입력 2 
3
1 100 100
100 1 100
100 100 1
예제 출력 2 
3
예제 입력 3 
3
1 100 100
100 100 100
1 100 100
예제 출력 3 
102
예제 입력 4 
6
30 19 5
64 77 64
15 19 97
4 71 57
90 86 84
93 32 91
예제 출력 4 
208
예제 입력 5 
8
71 39 44
32 83 55
51 37 63 
89 29 100
83 58 11
65 13 15
47 25 29
60 66 19
예제 출력 5 
253
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int N;
    vector<int> *map, *ck;

    cin >> N;
    map = new vector<int>[N];
    ck = new vector<int>[N];
    //create map & ckMap
    for (int i = 0; i < N; i++) {
        vector<int> vTmp, ckVTmp;
        for (int j = 0; j < 3; j++) {
            int tmp;
            cin >> tmp;
            vTmp.push_back(tmp);
            ckVTmp.push_back(0);
        }
        map[i] = vTmp;
        ck[i] = ckVTmp;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 0) ck[i][j] = map[i][j];
            else {
                if (j == 0) ck[i][j] = min(ck[i - 1][j + 1] + map[i][j], ck[i - 1][j + 2] + map[i][j]);
                else if (j == 1) ck[i][j] = min(ck[i - 1][j + 1] + map[i][j], ck[i - 1][j - 1] + map[i][j]);
                else ck[i][j] = min(ck[i - 1][j - 1] + map[i][j], ck[i - 1][j - 2] + map[i][j]);
            }
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < 3; i++) result = min(result, ck[N - 1][i]);

    cout << result << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < 3; j++) cout << ck[i][j] << " ";
    //     cout << endl;
    // }
}
