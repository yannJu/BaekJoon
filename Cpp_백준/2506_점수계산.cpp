#include <iostream>
using namespace std;

int main(){
    int num, result = 0, a, cnt = 0;
    cin >> num;
    
    for (int i = 0; i < num; i ++){
        cin >> a;
        if (a == 1){
            cnt += 1;
            result += cnt;
        }
        else {
            cnt = 0;
        }
    }
    
    cout << result << endl;
}