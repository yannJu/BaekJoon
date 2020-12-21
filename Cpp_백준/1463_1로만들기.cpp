#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int ary[] = {0, 0, 1, 1};
    vector<int> v(ary, ary+4);
    priority_queue< int, vector<int>, greater<int> > q;
    int num, temp;
    vector<int>::iterator iter;

    cin >> num;

    for (int i = 4; i <= num; i++){
        if (i % 3 == 0){
            temp = i / 3;
            q.push(v[temp] + 1);
        }
        if (i % 2 == 0){
            temp = i / 2;
            q.push(v[temp] + 1);
        }
        q.push(v[i - 1] + 1);
        v.push_back(q.top());
        while(!q.empty()){
            q.pop();
        }
    }
    
    if (num > 1){
    iter = v.end() - 1;
    cout << *iter << endl;
    }
    else cout << 0 << endl;
}