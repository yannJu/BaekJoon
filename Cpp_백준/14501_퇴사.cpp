#include <iostream>
#include <algorithm>
using namespace std;

struct SCHEDULE{
    int t;
    int p;
};

int main(){
    int day, *dp, tmp1, tmp2, mx;
    SCHEDULE *arr;

    cin >> day;
    arr = new SCHEDULE[day];
    dp  = new int[day];

    for (int i  = 0; i < day; i++){
        cin >> tmp1 >> tmp2;
        arr[i] = {tmp1, tmp2};
        dp[i] = arr[i].p;
    }

    dp[0] = arr[0].p;
    mx = dp[0];
    for (int i = 1; i < day; i++){
        for (int j = 0; j < i; j++){
            if (j + arr[j].t <= i) dp[i] = max(dp[j] + arr[j + arr[j].t].p, dp[i]);
        }
    }

    for (int i = 0; i < day; i++) cout << "dp : " <<  dp[i] << endl;

    delete arr;
    delete dp;
}