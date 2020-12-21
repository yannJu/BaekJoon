/*문제
지민이는 길이가 64cm인 막대를 가지고 있다. 어느 날, 그는 길이가 Xcm인 막대가 가지고 싶어졌다. 
지민이는 원래 가지고 있던 막대를 더 작은 막대로 자른다음에, 풀로 붙여서 길이가 Xcm인 막대를 만들려고 한다.

막대를 자르는 가장 쉬운 방법은 절반으로 자르는 것이다. 지민이는 아래와 같은 과정을 거쳐서 막대를 자르려고 한다.

지민이가 가지고 있는 막대의 길이를 모두 더한다. 처음에는 64cm 막대 하나만 가지고 있다. 이때, 합이 X보다 크다면, 아래와 같은 과정을 반복한다.
	1.가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자른다.
	2.만약, 위에서 자른 막대의 절반 중 하나를 버리고 남아있는 막대의 길이의 합이 X보다 크거나 같다면, 위에서 자른 막대의 절반 중 하나를 버린다.
이제, 남아있는 모든 막대를 풀로 붙여서 Xcm를 만든다.
X가 주어졌을 때, 위의 과정을 거친다면, 몇 개의 막대를 풀로 붙여서 Xcm를 만들 수 있는지 구하는 프로그램을 작성하시오. 

입력
첫째 줄에 X가 주어진다. X는 64보다 작거나 같은 자연수이다.

출력
문제의 과정을 거친다면, 몇 개의 막대를 풀로 붙여서 Xcm를 만들 수 있는지 출력한다.

예제 입력 1 
23
예제 출력 1 
4
예제 입력 2 
32
예제 출력 2 
1
예제 입력 3 
64
예제 출력 3 
1
예제 입력 4 
48
예제 출력 4 
2
*/
import java.util.*;

public class 백준1094_막대기 {
	static int sum(Vector<Integer> v) {
		int result = 0;
		for (int i = 0; i < v.size(); i++) {
			result += v.get(i);
		}
		return result;
	}
	static int min(Vector<Integer> v) {
		int m = 100;
		int idx = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v.get(i) < m) {
				m = v.get(i);
				idx = i;
			}
		}
		return idx;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int all = 0;
		int m, n = 0;
		Vector<Integer> v = new Vector<Integer>();
		
		v.add(64);
		all = sum(v);
		while (all != num) {
			if (all >= num) {
				m = min(v);
				n = v.get(m) / 2;
				v.remove(m);
				v.add(n);
			}
			else v.add(n);
			all = sum(v);
		}
		System.out.println(v.size());
	}
}
