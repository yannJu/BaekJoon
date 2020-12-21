//2562
package onearray;
import java.util.Scanner;

public class maxnum {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int max = 0;
		int maxidx = 0;
		for(int i = 1; i < 10; i++) {
			int num = sc.nextInt();
			if(num > max) {
				max = num;
				maxidx = i;
			}
		}
		System.out.println(max + "\n" + maxidx);
	}
}
