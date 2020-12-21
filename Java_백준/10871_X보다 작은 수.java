import java.util.Scanner;
import java.util.Arrays;
public class underX {

	public static void main(String[] args) {
		String answer = "";
		Scanner sc = new Scanner(System.in);
		int all = sc.nextInt();
		int how = sc.nextInt();
		for(int i = 0; i < all; i++) {
			int num = sc.nextInt();
			if (num < how) {
				answer += num;
				answer += " ";
			}
		}
		System.out.println(answer);
	}

}
