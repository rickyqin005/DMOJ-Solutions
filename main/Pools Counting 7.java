import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(), K = nextInt();
		boolean[][] isWater = new boolean[N][M];
		for(int i = 0; i < K; i++) isWater[nextInt()-1][nextInt()-1] = true;
		int ans = 0;
		int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
		boolean[][] visited = new boolean[N][M];
		Queue<Integer> queue = new LinkedList<Integer>();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(!isWater[i][j]) continue;
				if(visited[i][j]) continue;
				queue.add(i*M+j); visited[i][j] = true;
				while(!queue.isEmpty()) {
					int curr = queue.poll();
					int r = curr/M, c = curr%M;
					for(int k = 0; k < 4; k++) {
						int newR = r+dir[k][0], newC = c+dir[k][1];
						if(newR < 0 || newR >= N || newC < 0 || newC >= M) continue;
						if(visited[newR][newC]) continue; visited[newR][newC] = true;
						if(!isWater[newR][newC]) continue;
						queue.add(newR*M+newC);
					}
				}
				ans++;
			}
		}
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