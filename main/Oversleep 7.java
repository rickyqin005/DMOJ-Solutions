import java.io.*;
import java.util.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		int R = nextInt(), C = nextInt(),i,j;
		char[][] grid = new char[R][C];
		for(i = 0; i < R; i++) grid[i] = nextLine().toCharArray();
		int start = 0, end = 0;
		search1:for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(grid[i][j] == 's') {
					start = i*C+j; break search1;
				}
			}
		}
		search2:for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(grid[i][j] == 'e') {
					end = i*C+j; break search2;
				}
			}
		}
		int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
		boolean[][] visited = new boolean[R][C];
		int ans = 0;
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(start); queue.add(-1);
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			if(curr == -1) {
				if(!queue.isEmpty()) queue.add(-1);
				ans++; continue;
			}
			for(i = 0; i < 4; i++) {
				int newR = curr/C+dir[i][0], newC = curr%C+dir[i][1];
				if(newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
				if(visited[newR][newC]) continue; visited[newR][newC] = true;
				if(grid[newR][newC] == 'X') continue;
				if(grid[newR][newC] == 'e') {System.out.println(ans); return;}
				queue.add(newR*C+newC);
			}
		}
		System.out.println(-1);
	}
	static long nextLong() throws IOException {return Long.parseLong(next());}
	static int nextInt() throws IOException {return Integer.parseInt(next());}
	static double nextDouble() throws IOException {return Double.parseDouble(next());}
	static String nextLine() throws IOException {return br.readLine().trim();}
	static String next() throws IOException {
		while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}