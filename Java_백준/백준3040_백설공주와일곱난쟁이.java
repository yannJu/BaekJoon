package 백준;
import java.util.*;

public class 백준3040_백설공주와일곱난쟁이 {
	public static void main(String[] args) {
		int ary[] = new int[9];
		int all = 0;
		Scanner sc = new Scanner(System.in);
		
		for (int i = 0; i < 9; i++) {
			ary[i] = sc.nextInt();
			all += ary[i];
		}
		all -= 100;
		
		for (int j = 0; j < 9; j++) {
			for (int k = j + 1; k <9; k++) {
				if (ary[j] + ary[k] == all) {
					ary[j] = -1;
					ary[k] = -1;
				}
			}
		}
		
		for (int r = 0; r < 9; r++) {
			if (ary[r] > 0) System.out.println(ary[r]);
		}
	}
}
