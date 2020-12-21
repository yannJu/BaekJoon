package whileLoop;
import java.util.Scanner;

class plusCycle{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt(); //String으로 받음
		String newnum = "-1"; //새로운 수를 만들기 위한 변수
		int sum; //newnum의 각 자릿수의 합
		int cnt = 0; //몇번 돌았는가???
		while(num != Integer.parseInt(newnum)){
			sum = 0; //sum을 초기화
			if(cnt == 0) {
				newnum = "" + num;
			}
			cnt += 1;
			if (newnum.length() < 2) {
				newnum = "0" + newnum;
			}
			for(int i = 0; i < newnum.length(); i++) {
				sum += newnum.charAt(i) - '0';
			}
			if (sum >= 10) {
				sum = sum % 10;
			}
			newnum = "" + newnum.charAt(1) + sum;
			}
		System.out.println(cnt);
		}
}