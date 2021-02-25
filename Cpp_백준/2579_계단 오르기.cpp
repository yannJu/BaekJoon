#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int cNum, *arr, *result; //계단수, 계단 점수, 결과 ary
    cin >> cNum;

    arr = new int[cNum];
    result = new int[cNum];

    for (int i = 0; i < cNum; i++) cin >> arr[i];
    result[0] = arr[0];
    result[1] = max(arr[0] + arr[1], arr[1]);
    result[2] = max(arr[0] + arr[2], arr[1] + arr[2]); //arr[0]~[2]까지의 값

    for (int i = 3; i < cNum; i++){
        result[i] = max((arr[i] + result[i - 2]), (arr[i] + arr[i - 1] + result[i - 3]));
    }
  
    cout << result[cNum - 1] << endl;
}