import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] sumArr = new int[N+1];
		for(int i = 1; i <= N; i++) {
			sumArr[i] = sumArr[i-1] + Integer.parseInt(br.readLine());
		}
		int Q = Integer.parseInt(br.readLine());
		for(int i = 0; i < Q; i++) {
			String[] in = br.readLine().split(" ");
			System.out.println(sumArr[Integer.parseInt(in[1])+1] - sumArr[Integer.parseInt(in[0])]);
		}
	}
}