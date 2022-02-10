import java.util.*;
import java.io.*;
public class Question4 {
	static ArrayList<Integer>[] paths;
	static boolean[] needed;
	static int[] dist, prev;
	public static boolean dfs(int curr,int prev) {
		if(paths[curr].size() == 1) return needed[curr];
		for(int i: paths[curr]) {
			if(i == prev) continue;
			if(dfs(i,curr)) needed[curr] = true;
		}
		return needed[curr];
	}
	public static int bfs(int start) {
		Queue<Integer> queue = new LinkedList<Integer>();
		int curr = 0;
		queue.add(start);
		dist[start] = 0; prev[start] = -1;
		while(!queue.isEmpty()) {
			curr = queue.poll();
			for(int i: paths[curr]) {
				if(i == prev[curr]) continue;
				if(!needed[i]) continue;
				queue.add(i);
				dist[i] = dist[curr]+1;
				prev[i] = curr;
			}
		}
		return curr;
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i,a,b;
		needed = new boolean[N]; paths = new ArrayList[N];
		dist = new int[N]; prev = new int[N];
		int root = nextInt(); needed[root] = true;
		for(i = 1; i < M; i++) needed[nextInt()] = true;
		for(i = 0; i < N; i++) paths[i] = new ArrayList<Integer>();
		for(i = 1; i < N; i++) {
			a = nextInt(); b = nextInt();
			paths[a].add(b);
			paths[b].add(a);
		}
		for(int j: paths[root]) {
			if(dfs(j,root)) needed[root] = true;
		}
		int ans = -1;
		for(i = 0; i < N; i++) {
			if(needed[i]) ans++;
		}
		ans *= 2;
		ans -= dist[bfs(bfs(root))];
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