import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
public class fastAplusB {
	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int a = Integer.parseInt(bf.readLine());
		for (int i = 0; i < a; i++) {
			int result = 0;
			String num = bf.readLine();
			String array[] = num.split(" ");
			bw.write(1);
			for (String a1 : array) {
				bw.write(2);
				result += Integer.parseInt(a1);
			}
			bw.write(result);
			bw.flush();
			bw.close();
		}
	}
}
