//2577
package onearray;
import java.util.Scanner;
import java.util.Arrays;

public class hownum {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] numary = {0,1,2,3,4,5,6,7,8,9};
		String strnum = "";
		String answer = "";
		int cnt;
		int num = 1;
		for(int i = 0; i < 3; i++) {
			num *= sc.nextInt();
		}
		strnum += num;
		for(int a : numary) {
			cnt = 0;
			for(int j = 0; j < strnum.length(); j++) {
				if(a == strnum.charAt(j) - '0') {
					cnt += 1;
				}
			}
			answer += cnt + "\n";
		}
		System.out.println(answer.substring(0,19));
	}
}
