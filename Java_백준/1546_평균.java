//1546
package onearray;
import java.util.Scanner;
import java.util.Arrays;

public class average {
	public static void main(String[] args) {
		float num = 0;
		float max = -1;
		float result = 0;
		
		Scanner sc = new Scanner(System.in);
		int length = sc.nextInt();
		float[] ary = new float[length];
		for(int i = 0; i < length; i++) {
			num = sc.nextInt();
			if (num > max) {
				max = num;
			}
			ary[i] = num;
		}
		for(float a : ary) {
			result += (a / max * 100);
		}
		System.out.println(result / length);
	}
}
