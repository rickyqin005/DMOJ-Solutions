import java.util.*;
import java.io.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		int K = nextInt(), N = nextInt(), M = nextInt(),i,j,a,b,t,h;
		ArrayList<int[]>[] adj = new ArrayList[N];
		for(i = 0; i < N; i++) adj[i] = new ArrayList<int[]>();
		for(i = 0; i < M; i++) {
			a = nextInt()-1; b = nextInt()-1;
			t = nextInt(); h = nextInt();
			adj[a].add(new int[] {b,t,h});
			adj[b].add(new int[] {a,t,h});
		}
		int A = nextInt()-1, B = nextInt()-1;
		boolean[] inQueue = new boolean[N];
		Queue<Integer> queue = new LinkedList<Integer>();
		int[][] dist = new int[N][K];
		for(i = 0; i < N; i++) Arrays.fill(dist[i], 1000000000);
		inQueue[A] = true;
		Arrays.fill(dist[A], 0);
		queue.add(A);
		int curr;
		while(!queue.isEmpty()) {
			curr = queue.poll();
			inQueue[curr] = false;
			for(int[] edge: adj[curr]) {
				for(i = 0; i < K-edge[2]; i++) {
					if(dist[curr][i]+edge[1] < dist[edge[0]][i+edge[2]]) {
						dist[edge[0]][i+edge[2]] = dist[curr][i]+edge[1];
						if(!inQueue[edge[0]]) {
							queue.add(edge[0]);
							inQueue[edge[0]] = true;
						}
					}
				}
			}
		}
		int ans = 1000000000;
		for(i = 0; i < K; i++) {
			ans = Math.min(ans, dist[B][i]);
		}
		if(ans == 1000000000) System.out.println(-1);
		else System.out.println(ans);
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