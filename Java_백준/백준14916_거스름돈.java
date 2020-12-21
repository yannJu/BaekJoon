package 백준;
import java.util.*;

public class 백준14916_거스름돈 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int result[] = new int[num + 1];
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		
		for (int i = 0; i <= num; i++) {
			if (i < 6) {
				if (i % 2 == 0) result[i] = i/2;
				else if (i == 5) result[i] = 1;
				else result[i] = -1;
			}
			else {
				if (result[i - 5] != -1) pq.add(result[i - 5] + 1);
				if (result[i - 2] != -1) pq.add(result[i - 2] + 1);
				if (pq.isEmpty()) result[i] = -1;
				else {
					result[i] = pq.peek();
					pq.clear();
				}
			}
		}
		System.out.println(result[num]);
	}
}
