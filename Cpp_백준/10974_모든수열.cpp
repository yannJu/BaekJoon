/*
모든 순열
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	18975	11466	8528	61.291%
문제
N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다. 

출력
첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.

예제 입력 1 
3
예제 출력 1 
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/

#include <iostream>
#include <vector>
using namespace std;

void tracking(int**, vector<int>*, int);
int main(){
    int t_case, *ckAry;
    vector<int> v;

    cin >> t_case;
    ckAry = new int[t_case];
    for (int i = 0; i < t_case; i++) ckAry[i] = 0;

    for (int j = 0; j < t_case; j++){
        ckAry[j] = 1;
        v.push_back(j + 1);
        tracking(&ckAry, &v, t_case);
        ckAry[j] = 0;
        v.pop_back();
    }
}

void tracking(int** ck, vector<int>* v, int t_case){
    int *ckAry = *ck;
    vector<int> V = *v;

    if (V.size() == t_case){
        for (int j = 0; j < t_case; j++) cout << V[j] << " ";
        cout << "\n";
    }
    for (int i = 0; i < t_case; i++){
        if (ckAry[i] == 0){
            ckAry[i] = 1;
            V.push_back(i + 1);
            tracking(&ckAry, &V, t_case);
            ckAry[i] = 0;
            V.pop_back();
        }
    }
}