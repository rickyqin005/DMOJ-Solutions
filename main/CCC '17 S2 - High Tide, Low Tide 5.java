import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] num = new int[N];
		String[] in = br.readLine().split(" ");
		for(int i = 0; i < N; i++) {
			num[i] = Integer.parseInt(in[i]);
		}
		java.util.Arrays.sort(num);
		if(N % 2 == 1) {
			for(int i = N/2; i >= 1; i--) {
				System.out.print(num[i] + " ");
				System.out.print(num[N-i] + " ");
			}
			System.out.println(num[0]);
		} else {
			for(int i = N/2-1; i >= 1; i--) {
				System.out.print(num[i] + " ");
				System.out.print(num[N-i-1] + " ");
			}
			System.out.println(num[0] + " " + num[N-1]);
		}
	}
}