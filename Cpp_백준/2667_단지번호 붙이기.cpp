/*
문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.



입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

예제 입력 1 
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
예제 출력 1 
3
7
8
9
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define vii vector<vector<int>>
using namespace std;

struct DIR {
    int x, y;
    DIR(int _y, int _x) : y(_y), x(_x) {};
};

DIR dir[4] = {
    DIR(-1, 0), // up
    DIR(1, 0), //down
    DIR(0, -1), // left
    DIR(0, 1) // right
};

int main() {
    int N, answer = 1;
    cin >> N;

    vii map(N, vector<int>(N, 0)), ck(N, vector<int>(N, 0));
    vector<int> answerVector;
    // setting Map
    for (int i = 0; i < N; i++) {
        string row;

        cin >> row;
        for (int j = 0; j < N; j++) map[i][j] = row[j] - '0'; // int 로 변경
    }

    // Queue 채우기
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && ck[i][j] == 0) {
                queue<DIR> q;
                q.push(DIR(i, j));
                ck[i][j] = answer;
                
                int cnt = 1;
                while(!q.empty()) {
                    DIR next(0, 0), now = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        next.y = now.y + dir[d].y; next.x = now.x + dir[d].x;
                        
                        if ((next.y < N && next.y >= 0) && (next.x < N && next.x >= 0)) {
                            if (map[next.y][next.x] == 1 && ck[next.y][next.x] == 0) {
                                q.push(DIR(next.y, next.x));
                                ck[next.y][next.x] = answer;
                                cnt += 1;
                            }
                        }
                    }
                }

                answer++;
                answerVector.push_back(cnt);
            }
        }
    }

    // for (int i =0; i < N; i++) {
    //     for (int j = 0; j < N; j++) cout << ck[i][j] << " " ;
    //     cout << endl;
    // }
    sort(answerVector.begin(), answerVector.end());

    cout << answer - 1 << endl;
    for (int i = 0; i < answerVector.size(); i++) cout << answerVector[i] << endl;
}