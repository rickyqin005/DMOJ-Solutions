import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt();
		ArrayList<int[]>[] adj = new ArrayList[N];
		for(int i = 0; i < N; i++) adj[i] = new ArrayList<int[]>();
		for(int i = 0; i < M; i++) {
			int x = nextInt()-1, y = nextInt()-1, z = nextInt();
			adj[x].add(new int[] {y,z});
			adj[y].add(new int[] {x,z});
		}
		
		int[] brightBlack = new int[N];
		int[] brightWhite = new int[N];
		int[] dist = new int[N];
		boolean[] visited = new boolean[N];
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(0);
		visited[0] = true;
		
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			for(int[] next: adj[curr]) {
				int y = next[0];
				int cost = next[1];
				if(!visited[y]) {
					brightBlack[y] = brightBlack[curr]+cost;
					brightWhite[y] = brightWhite[curr]+cost;
					dist[y] = dist[curr]+1;
					queue.add(y);
					visited[y] = true;
					
				} else if(dist[curr] < dist[y]) {
					brightBlack[y] = Math.min(brightBlack[y], brightBlack[curr]+cost);
					brightWhite[y] = Math.max(brightWhite[y], brightWhite[curr]+cost);
				}
			}
		}

		int Q = nextInt();
		for(int i = 0; i < Q; i++) {
			int d = nextInt()-1;
			if(next().charAt(0) == 'B') System.out.println(dist[d] + " " + brightBlack[d]);
			else System.out.println(dist[d] + " " + brightWhite[d]);
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