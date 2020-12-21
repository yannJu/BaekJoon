import java.util.*;
public class 백준1284_집주소 {
	public static void main(String []args) {
		int result = 2;
		String num;
		int l[] = {4, 2, 3};
		Scanner sc = new Scanner(System.in);
		
		while(true) {
			num = sc.next();
			result = 2;
			if (num.charAt(0) == '0') break;
			
			for (int i = 0; i < num.length(); i++) {
				int n = num.charAt(i) - '0';
				if (n > 1) {
					result += l[2];
				}
				else result += l[n];
			}
			result += num.length() - 1;
			
			System.out.println(result);
		}
	}
}
