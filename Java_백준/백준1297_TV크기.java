package 백준;
import java.util.*;

public class 백준1297_TV크기 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double real_c = sc.nextInt();
		double h = sc.nextInt();
		double w = sc.nextInt();
		double c = Math.sqrt(Math.pow(h, 2) + Math.pow(w, 2));
		double X = real_c / c;
		
		int real_h, real_w;
		real_h = (int)(h * X);
		real_w = (int)(w *X);
		
		System.out.println(real_h + " " + real_w);
	}
}
