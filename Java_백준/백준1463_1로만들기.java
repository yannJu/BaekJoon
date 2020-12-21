import java.util.*;
public class 백준1463_1로만들기 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int temp;
		int ary[] = new int[num + 1];
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		
		for (int i = 0; i <= num; i++) {
			if (i < 2) ary[i] = 0;
			else if (i < 4) ary[i] = 1;
			else {
				if (i % 3 == 0) {
					temp = i / 3;
					pq.add(ary[temp] + 1);
				}
				if (i % 2 == 0) {
					temp = i / 2;
					pq.add(ary[temp] + 1);
				}
				pq.add(ary[i - 1] + 1);
				ary[i] = pq.peek();
				pq.clear();
			}
		}
		System.out.println(ary[num]);
	}

}
