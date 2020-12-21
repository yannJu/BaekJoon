package 백준;
import java.util.*;

public class 백준10101_삼각형외우기 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int angle_a = sc.nextInt();
		int angle_b = sc.nextInt();
		int angle_c = sc.nextInt();
		int result = angle_a + angle_b + angle_c;
		String answer = "";
		
		HashSet<Integer> hs = new HashSet<>();
		hs.add(angle_a);
		hs.add(angle_b);
		hs.add(angle_c);
		
		int size = hs.size();
		
		if (result != 180) {
			answer = "Error";
		}
		else {
			if (size < 3) {
				answer = (size == 1)? "Equilateral":"Isosceles";
			}
			else answer = "Scalene";
		}
		
		System.out.println(answer);
	}

}
