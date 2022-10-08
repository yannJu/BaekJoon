/*
문제
두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 
합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.

예를 들어, < 그림 1 >과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄, 
A의 3번 위치와 B의 9번 위치를 잇는 전깃줄, A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다.



< 그림 1 >

전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 
남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100 이하의 자연수이다. 
둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다. 
위치의 번호는 500 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다.

출력
첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 출력한다.

예제 입력 1 
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6
예제 출력 1 
3
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct AB {
    int A;
    int B;
};

bool compareAB(AB a, AB b) {
    if (a.A < b.A) return true;
    else return false;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) return true;
    else return false;
}

int main() {
    int N, maxLine = -1; 
    vector<AB> memo;
    vector<pair<int, int> > check;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmpA, tmpB;
        AB tmp;

        cin >> tmpA >> tmpB;
        tmp.A = tmpA;
        tmp.B = tmpB;
        memo.push_back(tmp);
        maxLine = max({maxLine, tmpA, tmpB});
    }

    // 건물 A를 기준으로 오름차순 정렬
    sort(memo.begin(), memo.end(), compareAB);

    // 꼬인 건물 수를 체킹
    for (int i = 0; i < maxLine; i++) check.push_back(make_pair(i, 0));

    for (int i = 0; i < N; i++) {
        // Left Check
        for (int j = 0; j < i; j++) {
            if (memo[i].B < memo[j].B) check[i].second += 1;
        }
        
        // Right Check
        for (int k = i + 1; k < N; k++) {
            if (memo[i].B > memo[k].B) check[i].second += 1;
        }
    }

    sort(check.begin(), check.end(), compare);

    // 많이 꼬인 전깃줄 순서대로 제거
    int cnt = 0;
    for (int i = 0; i < check.size(); i++) {
        int isCnt = 0;
        for (int j = 0; j < check.size(); j++) {
            if ((check[i].first < check[j].first && memo[check[i]] > check[j].second) || (check[i].first > check[j].first && check[i].second < check[j].second)) {
                check[j].second -= 1;
                check[i].second -= 1;
                if (isCnt == 0) {
                    isCnt = 1;
                    cnt += 1;
                }
            } 
        }
    }

    cout << cnt << endl;
}