//3052
package onearray;
import java.util.Scanner;
import java.util.Arrays;

class differenthow{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] ary = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
		int num = 0;
		int result = 0;
		int cnt = 0;
		boolean tmp;
		for(int i = 0; i < 10; i++) {
			tmp = false;
			num = sc.nextInt();
			result = num % 42;
			for(int a : ary) {
				if(a == result) {
					tmp = true;
					break;
				}
			}
			if(tmp == false) {
				ary[i] = result;
			}
		}
		for(int b : ary) {
			if(b != -1) {
				cnt += 1;
			}
		}
		System.out.println(cnt);
	}
}