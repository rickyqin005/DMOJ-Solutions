import java.util.*;
import java.io.*;
public class Question5 {
	static boolean[] hasGym, needed,maxPath;
	static ArrayList<Integer>[] adj;
	static int count = 0, maxDepth = 0,F;
	public static boolean prune(int curr, int prev) {
		boolean bool = hasGym[curr];
		for(int i: adj[curr]) {
			if(i == prev) continue;
			if(prune(i,curr)) bool = true;
		}
		if(bool) {
			needed[curr] = true;
			count++;
		}
		return bool;
	}
	public static void dfs1(int curr, int prev, int depth) {
		for(int i: adj[curr]) {
			if(i != prev && needed[i]) dfs1(i,curr,depth+1);
		}
		maxDepth = Math.max(maxDepth, depth);
	}
	public static void dfs2(int curr, int prev, int depth) {
		if(curr == F) {System.out.println(Math.min(count+depth,count*2-maxDepth)); System.exit(0);}
		for(int i: adj[curr]) {
			if(i == prev) continue;
			if(needed[i]) dfs2(i,curr,0);
			else dfs2(i,curr,depth+1);
		}
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(), K = nextInt(),i,a,b; F = nextInt()-1;
		hasGym = new boolean[N];
		needed = new boolean[N];
		maxPath = new boolean[N];
		for(i = 0; i < K; i++) hasGym[nextInt()-1] = true;
		adj = new ArrayList[N];
		for(i = 0; i < N; i++) adj[i] = new ArrayList<Integer>();
		for(i = 1; i < N; i++) {
			a = nextInt()-1; b = nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		
		for(int j: adj[0]) {
			prune(j,0);
		}
		needed[0] = true;
		
		if(needed[F]) System.out.println(count);
		else {
			for(int j: adj[0]) {
				if(needed[j]) dfs1(j,0,1);
			}
			
			for(int j: adj[0]) {
				if(needed[j]) dfs2(j,0,0);
				else dfs2(j,0,1);
			}
		}
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