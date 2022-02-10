import java.util.*;
import java.io.*;
public class Question5 {
	static int N, M;
	static int[][] adj;
	static int[] amt;
	static int ans = Integer.MAX_VALUE;
	public static void dfs(int curr, int sum) {
		if(adj[curr] == null) ans = Math.min(ans, sum);
		else {
			for(int i = 0; i < adj[curr].length; i++) {
				dfs(adj[curr][i],sum + amt[adj[curr][i]]);
			}
		}
	}
	public static void main(String[] args) throws IOException {
		N = nextInt(); M = nextInt(); int i,j,target,num;
		adj = new int[N][];
		amt = new int[N];
		for(i = 0; i < M; i++) {
			target = nextInt()-1;
			num = nextInt();
			adj[target] = new int[num];
			for(j = 0; j < num; j++) {
				adj[target][j] = nextInt()-1;
			}
		}
		for(i = 0; i < N; i++) amt[i] = nextInt();
		dfs(0,amt[0]);
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