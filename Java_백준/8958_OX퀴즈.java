//8958

package onearray;
import java.util.Scanner;

public class OXQuiz {
	public static void main(String[] args) {
		int cNum = 0;
		int cnt;
		int result = 0;
		Scanner sc = new Scanner(System.in);
		cnt = sc.nextInt();
		
		while(cnt > 0) {
			String chk = sc.next();
			for(int i = 0; i < chk.length(); i++) {
				if(chk.charAt(i) == 'O') {
					cNum += 1;
					result += cNum;
				}
				else {
					cNum = 0;
				}
			}
			System.out.println(result);
			cNum = 0;
			result = 0;
			cnt -= 1;
		}
	}
}
