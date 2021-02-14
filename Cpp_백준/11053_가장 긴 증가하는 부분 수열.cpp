#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int testCase, *ary, *dpAry, mx = 0;
    cin >> testCase;
    ary = new int[testCase];
    dpAry = new int[testCase];

    for (int i = 0; i < testCase; i++) cin >> ary[i];
    for (int i = 0; i < testCase; i++){
        dpAry[i] = 1;
        for (int j = 0; j < i; j++){
            if (ary[i] > ary[j]) dpAry[i] = max(dpAry[i], dpAry[j] + 1);
        }
        if (dpAry[i] > mx) mx = dpAry[i];
    }
    cout << mx << endl;
}