/*
달팽이
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	128 MB	8669	3637	2851	48.793%
문제
홀수인 자연수 N이 주어지면, 다음과 같이 1부터 N2까지의 자연수를 달팽이 모양으로 N×N의 표에 채울 수 있다.

9	2	3
8	1	4
7	6	5
25	10	11	12	13
24	9	2	3	14
23	8	1	4	15
22	7	6	5	16
21	20	19	18	17
N이 주어졌을 때, 이러한 표를 출력하는 프로그램을 작성하시오. 또한 N2 이하의 자연수가 하나 주어졌을 때, 
그 좌표도 함께 출력하시오. 예를 들어 N=5인 경우 6의 좌표는 (4,3)이다.

입력
첫째 줄에 홀수인 자연수 N(3 ≤ N ≤ 999)이 주어진다. 둘째 줄에는 위치를 찾고자 하는 N2 이하의 자연수가 하나 주어진다.

출력
N개의 줄에 걸쳐 표를 출력한다. 각 줄에 N개의 자연수를 한 칸씩 띄어서 출력하면 되며, 자릿수를 맞출 필요가 없다. 
N+1번째 줄에는 입력받은 자연수의 좌표를 나타내는 두 정수를 한 칸 띄어서 출력한다.

예제 입력 1 
7
35
예제 출력 1 
49 26 27 28 29 30 31
48 25 10 11 12 13 32
47 24 9 2 3 14 33
46 23 8 1 4 15 34
45 22 7 6 5 16 35
44 21 20 19 18 17 36
43 42 41 40 39 38 37
5 7
*/

#include <iostream>
#include <vector>
using namespace std;

int ansX, ansY;
void snail(int***, int***, vector<pair<int, int>>*, int, int);

int main(){
    vector<pair<int, int>> dir;
    int N, ans;
    int **ary, **ck;
    
    cin >> N >> ans;

    dir.push_back(make_pair(1, 0));
    dir.push_back(make_pair(0, 1));
    dir.push_back(make_pair(-1, 0));
    dir.push_back(make_pair(0, -1));

    ary = new int*[N];
    ck = new int*[N];
    for (int i = 0; i < N; i++){
        int *tmp = new int[N];
        int *ckTmp = new int[N];
        for (int j = 0; j < N; j++){
            tmp[j] = 0;
            ckTmp[j] = 0;
        }
        ary[i] = tmp;
        ck[i] = ckTmp;
    }
    snail(&ary, &ck, &dir, N, ans);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << ary[i][j] << " ";
        }
        cout << endl;
    }
    cout << ansY << " " << ansX << endl;
}

void snail(int***ary, int***ck, vector<pair<int, int>>* dir, int N, int ans){
    int tmpY = 0, tmpX = 0, cnt = 0;
    int **A = *ary, **CK = *ck;
    vector<pair<int, int>> DIR = *dir;

    for (int n = N*N; n > 0; n--){
        if (n == ans) {
            ansX = tmpX + 1;
            ansY = tmpY + 1;
        }
        A[tmpY][tmpX] = n;
        CK[tmpY][tmpX] = 1;
        if(tmpY + DIR[cnt % 4].first < 0 || tmpY + DIR[cnt % 4].first > N - 1 || tmpX + DIR[cnt % 4].second < 0 || tmpX + DIR[cnt % 4].second > N - 1) cnt += 1;
        else if (CK[tmpY + DIR[cnt % 4].first][tmpX + DIR[cnt % 4].second] == 1) cnt += 1;
        tmpY = tmpY + DIR[cnt % 4].first; tmpX = tmpX + DIR[cnt % 4].second;
    }
}