//10818
package onearray;
import java.util.Scanner;
import java.util.Arrays;

public class minmax {

	public static void main(String[] args) {
		int max = -1000000;
		int min = 1000000;
		Scanner sc = new Scanner(System.in);
		String length = sc.nextLine();
		String[] ary = sc.nextLine().split(" ");
		for(String w : ary) {
			if(Integer.parseInt(w) > max) {
				max = Integer.parseInt(w);
			}
			if(Integer.parseInt(w) < min) {
				min = Integer.parseInt(w);
			}
		}
		System.out.println(min + " " + max);
	}

}
