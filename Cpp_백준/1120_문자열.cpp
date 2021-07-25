/*
문제
길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의 차이는 X[i] ≠ Y[i]인 i의 개수이다. 예를 들어, X=”jimin”, Y=”minji”이면, 둘의 차이는 4이다.

두 문자열 A와 B가 주어진다. 이때, A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

A의 앞에 아무 알파벳이나 추가한다.
A의 뒤에 아무 알파벳이나 추가한다.
이때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. A와 B의 길이는 최대 50이고, A의 길이는 B의 길이보다 작거나 같고, 알파벳 소문자로만 이루어져 있다.

출력
A와 B의 길이가 같으면서, A와 B의 차이를 최소가 되도록 했을 때, 그 차이를 출력하시오.

예제 입력 1 
adaabc aababbc
예제 출력 1 
2
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    string A, B;
    int aLen, bLen, dif, minRes = pow(10, 9);
    int tmpRes;

  //A 와 B의 차이 구하기
    cin >> A >> B;
    aLen = A.length();
    bLen = B.length();
    dif = abs(aLen - bLen);

 //처음부터 차이 + 1만큼 가면서 ck ~> 비어있는 부분은 어차피 같은것으로 채울것이기 때문에
    for (int i = 0; i <= dif; i++){
        tmpRes = 0;
        for (int j = 0; j < aLen; j++){
                if (A[j] == B[j + i]) tmpRes += 1;
        }
        //cout << "TMP : " << tmpRes << endl;
        minRes = min(minRes, aLen - tmpRes);
    }

    cout << minRes << endl;
}