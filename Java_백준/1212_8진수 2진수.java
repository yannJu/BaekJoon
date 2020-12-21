//1212
import java.util.*;
public class bj1212 {
	public static void main(String[] args) {
		int flag = 0;
		Scanner sc = new Scanner(System.in);
		String num = sc.next();
		String result = "";
		String[] eight = {"000", "001", "010", "011", "100", "101", "110", "111"};
		
		for (int i = 0; i < num.length(); i++) {
			int n = num.charAt(i) - '0';
			result += eight[n];
			if (i == 0 && n < 4) {
				flag = result.indexOf('1');
			}
		}
		result = result.substring(flag);
		System.out.println(result);
	}
}