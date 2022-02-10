import java.io.*;
import java.util.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), K = nextInt(),i,j,k,l;
		long[][][] dp = new long[N+1][][];
		for(i = 1; i <= N; i++) {
			dp[i] = new long[i+1][];
			for(j = 1; j < dp[i].length; j++) dp[i][j] = new long[i/j+1];
			dp[i][1][i] = 1;
			dp[i][dp[i].length-1][1] = 1;
			for(j = 2; j < dp[i].length-1; j++) {
				for(k = 1; k < dp[i][j].length; k++) {
					for(l = k; l <= (i-k)/(j-1); l++) {
						dp[i][j][k] += dp[i-k][j-1][l];
					}
				}
			}
		}
		long ans = 0;
		for(i = 0; i < dp[N][K].length; i++) ans += dp[N][K][i];
		System.out.println(ans);
	}
	static long nextLong() throws IOException {return Long.parseLong(next());}
	static int nextInt() throws IOException {return Integer.parseInt(next());}
	static double nextDouble() throws IOException {return Double.parseDouble(next());}
	static String nextLine() throws IOException {return br.readLine().trim();}
	static String next() throws IOException {
		while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}