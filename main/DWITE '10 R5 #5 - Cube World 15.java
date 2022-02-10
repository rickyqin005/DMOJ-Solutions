import java.util.*;
import java.io.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
		for(int i = 0; i < 5; i++) {
			int R = nextInt(), C = nextInt(),j,k,l;
			int[][] height = new int[R][C];
			for(j = 0; j < R; j++) {
				for(k = 0; k < C; k++) height[j][k] = nextInt();
			}
			if(R < 3 || C < 3) {System.out.println(0); continue;}
			boolean[][] hasWater = new boolean[R][C];
			for(j = 1; j < R-1; j++) Arrays.fill(hasWater[j], 1, C-1, true);
			
			Queue<Integer> queueR,queueC;
			boolean[][] visited;
			int r,c,newR,newC;
			boolean flag;
			for(j = 1; j < R-1; j++) {
				for(k = 1; k < C-1; k++) {
					queueR = new LinkedList<Integer>();
					queueC = new LinkedList<Integer>();
					visited = new boolean[R][C];
					queueR.add(j); queueC.add(k);
					visited[j][k] = true;
					flag = false;
					while(!queueR.isEmpty()) {
						r = queueR.poll(); c = queueC.poll();
						for(l = 0; l < 4; l++) {
							newR = r+dir[l][0]; newC = c+dir[l][1];
							if(visited[newR][newC]) continue;
							if(height[newR][newC] <= height[j][k]) {
								if(!hasWater[newR][newC]) {
									flag = true; break;
								} else {
									queueR.add(newR);
									queueC.add(newC);
								}
							}
							visited[newR][newC] = true;
						}
						if(flag) {
							hasWater[j][k] = false; break;
						}
					}
				}
			}
			int ans = 0;
			int min;
			visited = new boolean[R][C];
			Queue<Integer> queue,water;
			for(j = 1; j < R-1; j++) {
				for(k = 1; k < C-1; k++) {
					if(hasWater[j][k] && !visited[j][k]) {
						queue = new LinkedList<Integer>();
						water = new LinkedList<Integer>();
						queue.add(C*j+k);
						water.add(C*j+k);
						visited[j][k] = true;
						min = Integer.MAX_VALUE;
						while(!queue.isEmpty()) {
							r = queue.peek()/C;
							c = queue.poll()%C;
							for(l = 0; l < 4; l++) {
								newR = r+dir[l][0]; newC = c+dir[l][1];
								if(hasWater[newR][newC]) {
									if(!visited[newR][newC]) {
										queue.add(newR*C+newC);
										water.add(newR*C+newC);
									}
								} else {
									min = Math.min(min, height[newR][newC]);
								}
								visited[newR][newC] = true;
							}
						}
						while(!water.isEmpty()) ans += min-height[water.peek()/C][water.poll()%C];
					}
				}
			}
			System.out.println(ans);
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