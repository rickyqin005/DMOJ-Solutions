import java.util.*;
import java.io.*;
public class Question4 {
	static ArrayList<Integer>[] adj;
	static boolean[] visited;
	static Stack<Integer> path = new Stack<Integer>();
	public static void dfs(int n, int depth) {
		if(depth == 6) return;
		for(int i: adj[n]) {
			if(visited[i]) {
				if(path.firstElement() == i && depth == 5) {System.out.println("YES"); System.exit(0);}
				continue;
			}
			visited[i] = true;
			path.add(i);
			dfs(i,depth+1);
			path.pop();
			visited[i] = false;
		}
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i,u,v;
		adj = new ArrayList[N];
		visited = new boolean[N];
		for(i = 0; i < N; i++) adj[i] = new ArrayList<Integer>();
		for(i = 0; i < M; i++) {
			u = nextInt()-1; v = nextInt()-1;
			adj[u].add(v);
			adj[v].add(u);
		}
		for(i = 0; i < N; i++) {
			visited[i] = true;
			path.add(i);
			dfs(i,0);
			path.pop();
			visited[i] = false;
		}
		System.out.println("NO");
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