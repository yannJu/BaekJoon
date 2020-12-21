//4344
package onearray;
import java.util.Scanner;
import java.util.Arrays;

public class averageupper {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tn = sc.nextInt();
		int avg = 0;
		int cnt;
		while(tn > 0) {
			cnt = 0;
			int sNum = sc.nextInt();
			int[] ary = new int[sNum];
			for (int i = 0; i < sNum; i++) {
				int score = sc.nextInt();
				avg += score;
				ary[i] = score;
			}
			avg = avg / sNum;
			for(int a : ary) {
				if(a > avg) {
					cnt += 1;
				}
			}
			double answer = ((double)cnt / (double)sNum) * 100;
			System.out.print(String.format("%.3f", answer));
			System.out.println("%");
			tn -= 1;
			avg = 0;
			System.out.println(answer);
		}
	}
}