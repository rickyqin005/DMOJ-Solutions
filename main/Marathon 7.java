import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int N = Integer.parseInt(in[0]), Q = Integer.parseInt(in[1]);
		String[] arr = br.readLine().split(" ");
		int[] sumArr = new int[N+1];
		for(int i = 1; i < N+1; i++) {
			sumArr[i] = sumArr[i-1] + Integer.parseInt(arr[i-1]);
		}
		for(int i = 0; i < Q; i++) {
			in = br.readLine().split(" ");
			System.out.println(sumArr[N]-sumArr[Integer.parseInt(in[1])]+sumArr[Integer.parseInt(in[0])-1]);
		}
	}
}