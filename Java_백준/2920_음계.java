//2920
package onearray;
import java.util.Scanner;
import java.util.Arrays;

public class ascending {
	public static void main(String[]args) {
		Scanner sc = new Scanner(System.in);
		int[] ary = {1,2,3,4,5,6,7,8};
		int[] reverseary = {8,7,6,5,4,3,2,1};
		int[] elseary = new int[8];
		String answer = "";
		for(int i = 0; i < 8; i++) {
			int num = sc.nextInt();
			elseary[i] = num;
		}
		for(int i = 0; i < 7; i++) {
			if(elseary[i] + 1 == elseary[i+1] && elseary[i] == ary[i]) {
				answer = "ascending";
			}
			else if(elseary[i] - 1 == elseary[i + 1] && elseary[i] == reverseary[i]){
				answer = "descending";
			}
			else {
				answer = "mixed";
				break;
			}
		}
		System.out.println(answer);
	}
}
