import java.util.Scanner;
import java.util.Arrays;
class APlusB7{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int result;
        String[] a = {};
        for (int i = 0; i < num; i++){
        	int b = sc.nextInt();
        	int c = sc.nextInt();
        	System.out.printf("Case #%d: %d\n", i+1, b+c);
        }
    }
}