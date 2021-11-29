import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i,j;
		double[] prob = new double[N];
		for(i = 0; i < N; i++) prob[i] = nextDouble();
		double[][] dp = new double[N+1][N+1];
		dp[0][0] = 1.0;
		for(i = 0; i < N; i++) {
			for(j = 0; j <= i; j++) {
				dp[i+1][j] += dp[i][j]*prob[i];
				dp[i+1][j+1] += dp[i][j]*(1-prob[i]);
			}
		}
		double ans = 0;
		for(i = 0; i <= N/2; i++) ans += dp[N][i];
		System.out.printf("%.010f\n",ans);
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