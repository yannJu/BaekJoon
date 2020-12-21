#include <iostream>
using namespace std;

int main(){
    int studentNum, c;
    int maxS = 0;
    int idx = 0;
    cin >> studentNum;
    int classL[studentNum][5];

    for (int i = 0; i < studentNum; i++){
        for (int j = 0; j < 5; j++){
            cin >> c;
            classL[i][j] = c;
        }
    }

    for (int sN = 0; sN < studentNum; sN++){
        int ckStudent[studentNum] = {0,};
        int cnt = 0;
        for (int grade = 0; grade < 5; grade++){
            for (int Class = 0; Class < studentNum; Class++){
                if ((classL[sN][grade] == classL[Class][grade]) && (sN != Class)){
                    ckStudent[Class] = 1;
                }
            }
        }
        for (int i = 0; i < studentNum; i ++){
            if (ckStudent[i] == 1) cnt += 1;
        }
        if (maxS < cnt) {
            maxS = cnt;
            idx = sN;
        }
    }
    cout << idx + 1 << endl;
}