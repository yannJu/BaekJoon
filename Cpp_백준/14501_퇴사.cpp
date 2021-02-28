#include<iostream>
#include<algorithm>
using namespace std;

struct SCHEDULE{
    int t;
    int p;
};

int main(){
    int day, *dp, tmp1, tmp2;
    SCHEDULE *arr;
    cin >> day;

    arr = new SCHEDULE[day];
    dp = new int[day];

    for (int i = 0; i < day; i++) {
        cin >> tmp1 >> tmp2;
        arr[i] = {tmp1, tmp2};
    } 

    for (int i = 0; i < day; i++){
        if (i == 0) dp[i] = arr[i].p;
        else if (i == 1){
            if (arr[i - 1].t == 1) dp[i] = max(dp[i - 1] + arr[i].t, arr[i].t);
            else dp[i] = arr[i].t;
        }
        else{
            for (int j = 0; j < i; j++){
                
            }
        }
    }

    cout << mx << endl;
    delete arr;
    delete dp;
}