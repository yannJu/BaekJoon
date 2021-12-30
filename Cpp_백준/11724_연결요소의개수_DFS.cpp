/*
연결 요소의 개수
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
3 초	512 MB	55635	26149	17066	43.841%
문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 
둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.

예제 입력 1 
6 5
1 2
2 5
5 1
3 4
4 6
예제 출력 1 
2
예제 입력 2 
6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3
예제 출력 2 
1
*/

#include <iostream>
using namespace std;

void DFS(int ***, int **, int, int, int);

int main(){
    int node, edge, u, v, result = 0;
    int **graph, *ckAry;

    cin >> node >> edge;
    graph = new int*[node];
    ckAry = new int[node];
    //Create Graph & CkAry
    for (int i = 0; i < node; i++){
        int *tmp = new int[node];
        for (int j = 0; j < node; j++){
            if (i == 0) ckAry[j] = 0;
            tmp[j] = 0;
        }
        graph[i] = tmp;
    }
    for (int i = 0; i < edge; i++){
        cin >> u >> v;
        graph[u - 1][v - 1] = 1; graph[v - 1][u - 1] = 1;
    }

    for (int i = 0; i < node; i++) {
        if (ckAry[i] == 0) {
            result += 1;
            ckAry[i] = 1;
            DFS(&graph, &ckAry, i, 0, node);
        }
    }
    cout << result << endl;
}

void DFS(int ***graph, int **ckAry, int u, int v, int node){
    int **G = *graph, *CK = *ckAry;

    for (int i = 0; i < node; i++){
        if (G[u][i] == 1 && CK[i] == 0){
            CK[i] = 1;
            DFS(graph, ckAry, i, 0, node);
        }
    }
}