import java.util.*;
import java.io.*;
public class Question5 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), Q = nextInt(),i,x,y,curr,parentX,parentY;
		int[] parent = new int[N];
		int[] rank = new int[N];
		for(i = 0; i < N; i++) parent[i] = i;
		for(i = 0; i < Q; i++) {
			if(next().equals("A")) {
				x = nextInt()-1; y = nextInt()-1;
				parentX = parent[x];
				parentY = parent[y];
				curr = x;
				while(parentX != curr) {
					curr = parentX;
					parentX = parent[curr];
				}
				curr = y;
				while(parentY != curr) {
					curr = parentY;
					parentY = parent[curr];
				}
				if(parentX != parentY) {
					if(rank[parentX] > rank[parentY]) {
						parent[parentY] = parentX;
					}
					else {
						parent[parentX] = parentY;
						if(rank[parentX] == rank[parentY]) rank[parentY]++;
					}
				}
			} else {
				x = nextInt()-1; y = nextInt()-1;
				parentX = parent[x];
				parentY = parent[y];
				curr = x;
				while(parentX != curr) {
					curr = parentX;
					parentX = parent[curr];
				}
				curr = y;
				while(parentY != curr) {
					curr = parentY;
					parentY = parent[curr];
				}
				if(parentX == parentY) System.out.println("Y");
				else System.out.println("N");
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