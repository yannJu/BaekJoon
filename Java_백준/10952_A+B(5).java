package whileLoop;
import java.util.Scanner;

public class APlusB_5 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int numA = sc.nextInt();
			int numB = sc.nextInt();
			if(numA == 0 && numB == 0) {
				break;
			}
			System.out.println(numA + numB);
		}
	}
}
