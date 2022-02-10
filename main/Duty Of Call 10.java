import java.util.*;
import java.io.*;
public class Question4 {
	static ArrayList<Integer>[] adj;
	static boolean[] isShot, visited;
	public static void main(String[] args) throws IOException {
		int N = nextInt(), R = nextInt(),i,j,M,mj;
		adj = new ArrayList[N+1];
		for(i = 1; i <= N; i++) adj[i] = new ArrayList<Integer>();
		isShot = new boolean[N+1];
		visited = new boolean[N+1];
		for(i = 1; i <= N; i++) {
			M = nextInt();
			for(j = 0; j < M; j++) {
				mj = nextInt();
				isShot[mj] = true;
				adj[i].add(mj);
				adj[mj].add(i);
			}
		}
		int numSoupyBoy = 0;
		int numBruce = 0;
		Queue<Integer> queue = new LinkedList<Integer>();
		int dist = 1;
		queue.add(R); queue.add(-1);
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			if(curr == -1) {
				if(!queue.isEmpty()) queue.add(-1);
				dist++; continue;
			}
			for(int k: adj[curr]) {
				if(visited[k]) continue;
				visited[k] = true;
				if(!isShot[k]) {
					if(dist % 2 == 0) numSoupyBoy++;
					else numBruce++;
				}
				queue.add(k);
			}
		}
		System.out.println(numSoupyBoy+" "+numBruce);
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