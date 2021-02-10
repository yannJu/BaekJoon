#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Dir{
    int x;
    int y;
};
Dir D[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

vector<int> *visit;
queue<Dir> q;
int l;

void bfs(int cX, int cY){
    Dir t;

    q.push({cX, cY});
	visit[cY].at(cX) = 0;
    while(!q.empty()){
        t = q.front();
        for (int i = 0; i < 8; i++){
            if (t.x + D[i].x >= 0 && t.y + D[i].y >= 0 && t.x + D[i].x < l && t.y + D[i].y < l){
                if (visit[t.y + D[i].y].at(t.x + D[i].x) == -1){
                    q.push({t.x + D[i].x, t.y + D[i].y});
                    visit[t.y + D[i].y].at(t.x + D[i].x) = visit[t.y].at(t.x) + 1;
                }
            }
        }
        q.pop();
    }
}

int main(){
    int testCase, currentx, currenty, gox, goy;
    cin >> testCase;
    while(testCase--){
        cin >> l >> currentx >> currenty >> gox >> goy;
        visit = new vector<int>[l];
        
        for (int i = 0; i < l; i++){
            for (int j = 0; j < l; j++) visit[i].push_back(-1);
        }
        bfs(currentx, currenty);
        cout << visit[goy].at(gox) << endl;
    }
}
