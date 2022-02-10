import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int N = Integer.parseInt(in[0]), K = Integer.parseInt(in[1]);
		int[][] score = new int[N][3];
		for(int i = 0; i < N; i++) {
			in = br.readLine().split(" ");
			score[i][0] = i+1;
			score[i][1] = Integer.parseInt(in[0]);
			score[i][2] = Integer.parseInt(in[1]);
		}
		java.util.Arrays.sort(score, (a,b) -> Integer.compare(a[1], b[1])*-1);
		int ans = 0;
		int max = 0;
		for(int i = 0; i < K; i++) {
			if(score[i][2] > max) {
				max = score[i][2];
				ans = score[i][0];
			}
		}
		System.out.println(ans);
	}
}