#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int allNum, candy, box, *boxArr, ri, ci, cnt;
    cin >> allNum;
    while(allNum--){
        cnt = 0;
        cin >> candy >> box;
        boxArr = new int[box];
        for (int i = 0; i < box; i++){
            cin >> ri >> ci;
            boxArr[i] = ri * ci;
        }
        sort(boxArr, boxArr + box);
        for (int i = 0; i < box; i++){
            if (candy <= 0) break;
            candy -= boxArr[i];
            cnt += 1;
        }
        cout << cnt << endl;
    }
}