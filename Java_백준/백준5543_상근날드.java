package 백준;
import java.util.*;

public class 백준5543_상근날드 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int burger, drink_1, drink_2;
		int[] burgers = new int[3];
		for (int i = 0; i < 3; i ++) {
			burger = sc.nextInt();
			burgers[i] = burger;
		}
		drink_1 = sc.nextInt();
		drink_2 = sc.nextInt();
		int burger_min = burgers[0];
		int drink_min = Math.min(drink_1, drink_2);
		int result = 0;
		for (int i = 0; i < 3; i++) {
			if (burgers[i] < burger_min)	burger_min = burgers[i];
		}
		result = burger_min + drink_min - 50;
		System.out.println(result);
	}
}
