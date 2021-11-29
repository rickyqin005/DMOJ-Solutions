import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i,u,v,curr;
		ArrayList<Integer>[] adj = new ArrayList[N];
		int[] inDeg = new int[N];
		for(i = 0; i < N; i++) adj[i] = new ArrayList<Integer>();
		for(i = 0; i < M; i++) {
			u = nextInt()-1; v = nextInt()-1;
			adj[u].add(v);
			inDeg[v]++;
		}
		int numRemoved = 0;
		Queue<Integer> queue = new LinkedList<Integer>();
		for(i = 0; i < N; i++) {
			if(inDeg[i] == 0) {
				queue.add(i);
				numRemoved++;
			}
		}
		while(!queue.isEmpty()) {
			curr = queue.poll();
			for(int j: adj[curr]) {
				inDeg[j]--;
				if(inDeg[j] == 0) {
					queue.add(j);
					numRemoved++;
				}
			}
		}
		if(numRemoved != N) System.out.println("N");
		else System.out.println("Y");
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