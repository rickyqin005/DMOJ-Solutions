import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String[] num = new String[N];
		for(int i = 0; i < N; i++) {
			num[i] = br.readLine();
		}
		Arrays.sort(num, (a,b) -> (a+b).compareTo(b+a)*-1);
		for(int i = 0; i < N; i++) {
			System.out.print(num[i]);
		}
		System.out.println();
	}
}