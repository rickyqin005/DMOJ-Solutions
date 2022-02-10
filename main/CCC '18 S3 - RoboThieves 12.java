import java.io.*;
import java.util.*;
public class CCC_18_S3_RoboThieves {
	static int R, C;
	static char[][] grid;
	static int[][] dist;
	static int[][][] conveyor;
	static boolean[][] visited, watched;
	static int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
	public static int search() {
		int i,j;
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(grid[i][j] == 'S') return i*C+j;
			}
		}
		return 0;
	}
	public static void scanLine(int r, int c) {
		int currR,currC,i;
		for(i = 0; i < 4; i++) {
			currR = r; currC = c;
			while(grid[currR][currC] != 'W') {
				if(currR < 0 || currR >= R || currC < 0 || currC >= C) break;
				watched[currR][currC] = true;
				currR += dir[i][0];
				currC += dir[i][1];
			}
		}
	}
	public static void checkConveyor(int r, int c, boolean[][] tempVisited) {
		int newR, newC,direction=0;
		ArrayList<int[]> path = new ArrayList<int[]>();
		Queue<Integer> queueR = new LinkedList<Integer>();
		Queue<Integer> queueC = new LinkedList<Integer>();
		int[] destination = new int[2];
		queueR.add(r); queueC.add(c);
		path.add(new int[] {r,c});
		tempVisited[r][c] = true;
		while(!queueR.isEmpty()) {
			r = queueR.poll(); c = queueC.poll();
			if(grid[r][c] == 'L') direction = 3;
			else if(grid[r][c] == 'U') direction = 1;
			else if(grid[r][c] == 'R') direction = 2;
			else if(grid[r][c] == 'D') direction = 0;
			newR = r+dir[direction][0];
			newC = c+dir[direction][1];
			if(tempVisited[newR][newC]) {
				if(conveyor[newR][newC] == null) destination[0] = -1;
				else {
					destination[0] = conveyor[newR][newC][0];
					destination[1] = conveyor[newR][newC][1];
				}
				break;
			}
			if(grid[newR][newC] == '.') {
				if(watched[newR][newC]) {destination[0] = -1; break;}
				destination[0] = newR;
				destination[1] = newC;
				break;
			} else {
				if(grid[newR][newC] == 'C' || grid[newR][newC] == 'S' || grid[newR][newC] == 'W') {
					destination[0] = -1; break;
				}
				path.add(new int[] {newR,newC});
				queueR.add(newR);
				queueC.add(newC);
				tempVisited[newR][newC] = true;
			}
		}
		for(int[] i: path) {
			conveyor[i[0]][i[1]] = new int[] {destination[0],destination[1]};
		}
	}
	public static void main(String[] args) throws IOException {
		R = nextInt(); C = nextInt(); int i,j;
		grid = new char[R][];
		for(i = 0; i < R; i++) grid[i] = nextLine().toCharArray();
		dist = new int[R][C];
		conveyor = new int[R][C][];
		visited = new boolean[R][C];
		watched = new boolean[R][C];
		int startR = search();
		int startC = startR%C;
		startR /= C;
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(grid[i][j] == 'C') scanLine(i,j);
			}
		}
		boolean[][] tempVisited = new boolean[R][C];
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				switch(grid[i][j]) {
				case 'L': case 'R': case 'U': case 'D':
					if(conveyor[i][j] == null) checkConveyor(i,j,tempVisited);
				}
			}
		}
		Queue<Integer> queueR = new LinkedList<Integer>();
		Queue<Integer> queueC = new LinkedList<Integer>();
		if(!watched[startR][startC]) {
			queueR.add(startR);
			queueC.add(startC);
		}
		visited[startR][startC] = true;
		int r,c,newR,newC;
		while(!queueR.isEmpty()) {
			r = queueR.poll();
			c = queueC.poll();
			for(i = 0; i < 4; i++) {
				newR = r+dir[i][0]; newC = c+dir[i][1];
				if(grid[newR][newC] == '.' || grid[newR][newC] == 'S') {
					if(visited[newR][newC]) continue;
					if(watched[newR][newC] && grid[newR][newC] == '.') continue;
					if(grid[newR][newC] == 'W') continue;
					queueR.add(newR);
					queueC.add(newC);
					dist[newR][newC] = dist[r][c]+1;
					visited[newR][newC] = true;
				} else {
					if(conveyor[newR][newC] == null) continue;
					if(conveyor[newR][newC][0] == -1) continue;
					int temp = newR;
					newR = conveyor[newR][newC][0];
					newC = conveyor[temp][newC][1];
					if(visited[newR][newC]) continue;
					queueR.add(newR);
					queueC.add(newC);
					dist[newR][newC] = dist[r][c]+1;
					visited[newR][newC] = true;
				}
			}
		}
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(grid[i][j] == '.') {
					if(dist[i][j] == 0) System.out.println(-1);
					else System.out.println(dist[i][j]);
				}
			}
		}
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