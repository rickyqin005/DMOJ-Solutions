import java.io.*;
import java.util.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		for(int i = 0; i < N; i++) {
			String str = br.readLine();
			int num = 0;
			if(str.indexOf('M') != -1) num++;
			if(str.indexOf('C') != -1) num++;
			if(num == 0) System.out.println("PASS");
			else if(num == 1) System.out.println("FAIL");
			else System.out.println("NEGATIVE MARKS");
		}
	}
}