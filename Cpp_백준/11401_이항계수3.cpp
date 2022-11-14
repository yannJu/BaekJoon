/*
이항 계수 3
 
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	256 MB	20353	7498	5479	41.007%
문제
자연수 \(N\)과 정수 \(K\)가 주어졌을 때 이항 계수 
\(\binom{N}{K}\)를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 \(N\)과 \(K\)가 주어진다. (1 ≤ \(N\) ≤ 4,000,000, 0 ≤ \(K\) ≤ \(N\))

출력
 
\(\binom{N}{K}\)를 1,000,000,007로 나눈 나머지를 출력한다.

예제 입력 1 
5 2
예제 출력 1 
10
*/

#include <iostream>
using namespace std;

long long mod = 1000000007;
long long factorial(long long a);
long long pow(long long a, long long powN);
int main() {
    long long n, k, resultN, resultK, resultNK;

    cin >> n >> k;

    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }
    
    resultN = factorial(n);
    resultK = factorial(k);
    resultNK = factorial(n - k);

    cout << resultN * pow((resultK * resultNK) % mod, mod - 2) % mod << endl;
}

long long factorial(long long a)  {
    long long result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
        result %= mod;
    }

    return result;
}

long long pow(long long a, long long powN) {
    if (powN == 1) return  a % mod;
    if (powN % 2 == 0) {
        long long tmp = pow(a, powN / 2) % mod;
        return tmp * tmp % mod;
    }
    else {
        long long tmp = pow(a, powN - 1) % mod;
        return tmp * a % mod;
    }
}