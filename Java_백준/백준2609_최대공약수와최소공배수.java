/*문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

예제 입력 1 
24 18
예제 출력 1 
6
72*/
import java.util.*;
public class 백준2609_최대공약수와최소공배수 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int upper, lower, M, mod, tmp; //a,b중 큰수와 작은수/ M = mod를 취할 값/ mod = M % 나머지의 값
		int a_M, b_M; //a, b를 M으로 나눈 몫
		
		if (a >= b) {
			upper = a; lower = b;
		}
		else {
			upper = b; lower = a;
		}
		
		M = lower;
		mod = upper % lower;
		
		while (mod != 0) {
			tmp = M;
			M = mod;
			mod = tmp % M;
		}
		
		a_M = a / M;
		b_M = b / M;

		System.out.println(M);
		System.out.println(M * a_M * b_M);
	}
}
