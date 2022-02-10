import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(), R = nextInt(),i,j;
		int[][] itv = new int[M][3];
		int[] dp = new int[N+1];
		for(i = 0; i < M; i++) {
			itv[i][0] = nextInt();
			itv[i][1] = nextInt();
			itv[i][2] = nextInt();
		}
		Arrays.sort(itv, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[1], b[1]);
			}
		});
		for(i = 0; i < M; i++) {
			for(j = 0; j < i; j++) {
				if(itv[j][1]+R <= itv[i][0]) {
					dp[itv[i][1]] = Math.max(dp[itv[i][1]], dp[itv[j][1]]+itv[i][2]);
				}
			}
			if(dp[itv[i][1]] == 0) dp[itv[i][1]] = itv[i][2];
			
		}
		int ans = 0;
		for(i = 0; i <= N; i++) ans = Math.max(ans, dp[i]);
		System.out.println(ans);
	}
	static int nextInt() throws IOException {return Integer.parseInt(next());}
	static String nextLine() throws IOException {return br.readLine().trim();}
	static String next() throws IOException {
		while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}