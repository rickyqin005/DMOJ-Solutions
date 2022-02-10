import java.util.*;
import java.io.*;
public class Question2 {
	public static int find(int a, int[] parent) {
		if(parent[a] != a) parent[a] = find(parent[a], parent);
		return parent[a];
	}
	public static void union(int a, int b, int[] parent, int[] size) {
		if(size[a] > size[b]) {
			parent[b] = a;
			size[a] += size[b]+1;
		} else {
			parent[a] = b;
			size[b] += size[a]+1;
		}
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i,j,a,b;
		int[] parent = new int[N];
		for(i = 0; i < N; i++) parent[i] = i;
		int[] size = new int[N];
		int count = 0;
		for(i = 0; i < M; i++) {
			a = find(nextInt()-1,parent);
			b = find(nextInt()-1,parent);
			if(a != b) {
				union(a,b,parent,size);
			} else {
				count++;
				if(count > 1) {System.out.println("NO"); return;}
			}
		}
		System.out.println("YES");
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