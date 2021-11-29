import java.util.*;
import java.io.*;
public class Question4 {
	static boolean[] visited;
	static boolean[][] adj;
	static int N;
	static int[] cycle;
	public static void dfs(int start, int curr, int len) {
		if(len > N) return;
		for(int i = 0; i < N; i++) {
			if(adj[curr][i]) {
				if(i == start) cycle[len]++;
				else {
					if(visited[i]) continue;
					visited[i] = true;
					dfs(start,i,len+1);
					visited[i] = false;
				}
			}
		}
	}
	public static void main(String[] args) throws IOException {
		N = nextInt(); int i,j;
		visited = new boolean[N];
		adj = new boolean[N][N];
		cycle = new int[N+1];
		for(i = 0; i < N; i++) {
			for(j = 0; j < N; j++) {
				adj[i][j] = next().equals("1");
			}
		}
		for(i = 0; i < N; i++) {
			for(j = 0; j < N; j++) {
				if(i == j) continue;
				if(adj[i][j]) {
					visited[j] = true;
					dfs(i,j,2);
					visited[j] = false;
				}
			}
		}
		for(i = 0; i < N; i++) {
			if(adj[i][i]) cycle[1]++;
		}
		int ans = 0;
		for(i = 1; i <= N; i++) ans += cycle[i]/i;
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