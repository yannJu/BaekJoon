/*
 문제
어떤 시골의 중학교에는 부근의 3개 초등학교를 졸업한 남녀 학생들이 입학한다. 
1학년 1반을 맡게 된 김갑동 선생님은 자기 반에 배정된 학생들을 대상으로 하여 짝을 정하려고 한다. 
1학년 1반에 배정 된 학생들은 남자와 여자가 각각 N 명씩이다. 
김갑동 선생님은 서로 모르는 학생끼리 짝이 되도록 하기 위해 같은 초등학교 출신이 아닌 남학생과 여학생을 짝으로 정하기로 원칙을 세웠다. 
예를 들어, 다음 표와 같이 1학년 1반에 학생들이 왔다고 하자.


위의 경우에는 다음과 같이 짝을 하면 서로 다른 초등학교 출신의 남녀 학생들로 짝을 정할 수 있다.

A초등 남학생 3명과 B초등 여학생 3명

A초등 남학생 1명과 C초등 여학생 1명

B초등 남학생 1명과 A초등 여학생 1명

C초등 남학생 1명과 A초등 여학생 1명

김갑동 선생님의 문제를 해결하는 프로그램을 작성하시오.

입력
첫 줄에는 남학생 (또는, 여학생) 수를 나타내는 정수 N (3≤N≤100,000)이 주어진다. 
둘째 줄에는 A초등학교 출신의 남학생 수와 여학생 수가 주어진다. 
셋째 줄에는 B초등학교 출신의 남학생 수와 여학생 수가 주어진다. 
넷째 줄에는 C초등학교 출신의 남 학생 수와 여학생 수가 주어진다. 모든 학생수는 0 이상이다.

출력
김갑동 선생님의 원칙대로 모든 학생들의 짝을 정할 수 있으면 첫 줄에 1을 출력하고, 그렇지 않으면 0을 출력한다.

첫 줄에 1을 출력한 경우는, 

둘째 줄에 A초등 남학생과 B초등 여학생의 짝 수와 A초등 남학생과 C초등 여학생의 짝 수를, 

셋째 줄에 B초등 남학생과 A초등 여학생의 짝 수와 B초등 남학생과 C초등 여학생의 짝 수를, 

넷째 줄에 C초등 남학생과 A초등 여학생의 짝 수와 C초등 남학생과 B초등 여학생의 짝 수를 출력한다. 

숫자와 숫자 사이에는 빈칸을 하나 둔다.

짝 정하는 방법이 여럿인 경우에는 아무거나 한 방법을 출력한다.

예제 입력 1 
6
4 2
1 3
1 1
예제 출력 1 
1
3 1
1 0
1 0
 */
import java.util.*;

public class 백준2599_짝정하기 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int student = sc.nextInt();
		int Student[][] = new int[2][3];
		int boy, girl, B, G, re_b = 0, re_g = 0;
		String answer = "";
		
		for (int i = 0; i < 3; i++) {
			boy = sc.nextInt();
			girl = sc.nextInt();
			Student[0][i] = boy;
			Student[1][i] = girl;
		}
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				System.out.print(Student[i][j] + " ");
			}
			System.out.println();
		}
		
		for (int b = 0; b < 3; b++) {
			B = Student[0][b];
			for (int g = 0; g < 3; g++) {
				G = Student[1][g];
				System.out.println("B : " + B + " G : " + G);
				if ((b != g) && (B >= 0) && (G >= 0)) {
					if (B == 0 && G == 0) {
						answer += 0;
						break;
					}
					if (B >= G) {
						answer += G + " ";
						re_g += G;
						B -= G;
						Student[1][g] = 0;
					}
					else {
						answer += B + " ";
						re_b += B;
						B = 0;
						Student[1][g] -= B;
					}
				}
			}
			answer += "\n";
			if (B > 0 || re_g != re_b) {
				System.out.println(0);
				return;
			}
			else {
				Student[0][b] = 0;
			}
		}
		System.out.println(1);
		System.out.print(answer);
	}
}
