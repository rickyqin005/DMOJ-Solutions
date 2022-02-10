import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i,j;
		int[][] num = new int[N][N];
		int[][] dp = new int[N][N];
		for(i = 0; i < N; i++) {
			for(j = 0; j <= i; j++) num[i][j] = nextInt();
		}
		dp[0][0] = num[0][0];
		for(i = 0; i < N-1; i++) {
			for(j = 0; j <= i; j++) {
				dp[i+1][j] = Math.max(dp[i+1][j], dp[i][j]+num[i+1][j]);
				dp[i+1][j+1] = Math.max(dp[i+1][j+1], dp[i][j]+num[i+1][j+1]);
			}
		}
		int ans = 0;
		for(i = 0; i < N; i++) ans = Math.max(ans, dp[N-1][i]);
		System.out.println(ans);
	}
	static long nextLong() throws IOException {return Long.parseLong(next());}
	static int nextInt() throws IOException {return Integer.parseInt(next());}
	static double nextDouble() throws IOException {return Double.parseDouble(next());}
	static String nextLine() throws IOException {return br.readLine().trim();}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}