import java.util.*;
import java.io.*;
public class Question5 {
	static int N,ans = 0;
	static boolean[][] adj;
	static int[] powersOf2, children;
	public static int dfs(int curr) {
		if(children[curr] == 0) return 2;
		int total = 1;
		for(int i = 0; i < N; i++) {
			if(adj[curr][i]) total *= dfs(i);
		}
		if(curr != N-1) total++;
		return total;
	}
	public static void main(String[] args) throws IOException {
		N = nextInt(); int i,num = 1;
		powersOf2 = new int[N];
		for(i = 0; i < N; i++) {
			powersOf2[i] = num;
			num *= 2;
		}
		children = new int[N];
		adj = new boolean[N][N];
		for(i = 0; i < N-1; i++) {
			num = nextInt()-1;
			adj[num][i] = true;
			children[num]++;
		}
		System.out.println(dfs(N-1));
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