import java.util.Scanner;
public class rest {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		int r1 = (A + B) % C;
		int r2 = (A % C + B % C) % C;
		int r3 = (A * B) % C;
		int r4 = (A % C * (B % C)) % C;
		
		System.out.println(r1 + "\n" + r2 + "\n" + r3 + "\n" + r4);
	}

}
