import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int R = nextInt(), C = nextInt(), i, j;
		char[][] grid = new char[R][C];
		int start = -1, present = -1;
		for(i = 0; i < R; i++) grid[i] = nextLine().toCharArray();
		searchStart:for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(grid[i][j] == 'O') {
					start = i*C+j; break searchStart;
				}
			}
		}
		searchPresent:for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(grid[i][j] == 'P') {
					present = i*C+j; break searchPresent;
				}
			}
		}
		int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
		int dist = 1;
		boolean isReachable = false;
		boolean[][] visited1 = new boolean[R][C];
		Queue<Integer> queue1 = new LinkedList<Integer>();
		queue1.add(start); visited1[start/C][start%C] = true;
		queue1.add(-1);
		bfs1:while(!queue1.isEmpty()) {
			int curr = queue1.poll();
			if(curr == -1) {
				if(!queue1.isEmpty()) queue1.add(-1);
				dist++; continue;
			}
			for(i = 0; i < 4; i++) {
				int newR = curr/C+dir[i][0], newC = curr%C+dir[i][1];
				if(visited1[newR][newC]) continue; visited1[newR][newC] = true;
				if(grid[newR][newC] == '#') continue;
				if(grid[newR][newC] == 'P') {
					isReachable = true; break bfs1;
				}
				queue1.add(newR*C+newC);
			}
		}
		if(!isReachable) {System.out.println(-1); return;}
		isReachable = false;
		dist++;
		boolean[][] visited2 = new boolean[R][C];
		Queue<Integer> queue2 = new LinkedList<Integer>();
		queue2.add(present); visited2[present/C][present%C] = true;
		queue2.add(-1);
		bfs2:while(!queue2.isEmpty()) {
			int curr = queue2.poll();
			if(curr == -1) {
				if(!queue2.isEmpty()) queue2.add(-1);
				dist++; continue;
			}
			for(i = 0; i < 4; i++) {
				int newR = curr/C+dir[i][0], newC = curr%C+dir[i][1];
				if(visited2[newR][newC]) continue; visited2[newR][newC] = true;
				if(grid[newR][newC] == '#') continue;
				if(grid[newR][newC] == 'X') {
					isReachable = true; break bfs2;
				}
				queue2.add(newR*C+newC);
			}
		}
		if(!isReachable) {System.out.println(-1); return;}
		System.out.println(dist);
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