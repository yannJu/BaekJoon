/*
N과 M (1)
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	512 MB	67842	42348	28087	61.640%
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

예제 입력 1 
3 1
예제 출력 1 
1
2
3
예제 입력 2 
4 2
예제 출력 2 
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
예제 입력 3 
4 4
예제 출력 3 
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1
*/

#include <iostream>
#include <vector>
using namespace std;

void findNM(int N, int **ck, int cnt, int diff, vector<int> result);
int main() {
    int N, d, *ck;

    cin >> N >> d;
    ck = new int[N];

    for (int j = 0; j < N; j++) {
        vector<int> result;
        for (int i = 0; i < N; i++) ck[i] = 0;
        result.push_back(j + 1);
        ck[j] = 1;
        findNM(N, &ck, 1, d, result);
    }
}

void findNM(int N, int **ck, int cnt, int diff, vector<int> result) {
    int *CK = *ck;

    if (cnt == diff) {
        for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (CK[i] == 0) {
            CK[i] = 1;
            result.push_back(i + 1);
            ck = &CK;
            findNM(N, ck, cnt + 1, diff, result);
            CK[i] = 0;
            result.pop_back();
        }
    }
}