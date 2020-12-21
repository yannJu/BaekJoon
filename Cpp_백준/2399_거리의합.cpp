#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int num, x;
    long long result = 0;
    int ary[num] = {};

    cin >> num;
    for (int i = 0; i < num; i++){
        cin >> x;
        ary[i] = x;
    }
    
    for (int j = 0; j < num; j++){
        for (int k = 0; k < num; k++){
            result += abs(ary[j] - ary[k]);
        }
    }

    cout << result << endl;
}