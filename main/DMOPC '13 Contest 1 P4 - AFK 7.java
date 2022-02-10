import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		int[][] dir = {{-1,0},{1,0},{0,1},{0,-1}};
		test: for(int i = 0; i < t; i++) {
			String[] in = br.readLine().split(" ");
			int R = Integer.parseInt(in[1]), C = Integer.parseInt(in[0]);
			char[][] grid = new char[R][C];
			boolean[][] visited = new boolean[R][C];
			int start = 0;
			for(int j = 0; j < R; j++) {
				String row = br.readLine();
				grid[j] = row.toCharArray();
				if(row.indexOf('C') != -1) start = j*C+row.indexOf('C');
			}
			
			LinkedList<Integer> queue = new LinkedList<Integer>();
			queue.add(start); queue.add(-1);
			visited[start/C][start%C] = true;
			int numSteps = 1;
			while(!queue.isEmpty()) {
				int curr = queue.poll();
				if(curr == -1) {
					if(!queue.isEmpty()) queue.add(-1);
					numSteps++;
					if(numSteps == 60) break;
					continue;
				}
				int r = curr/C, c = curr%C;
				for(int j = 0; j < 4; j++) {
					int newR = r+dir[j][0], newC = c+dir[j][1];
					if(newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
					if(grid[newR][newC] == 'W') {System.out.println(numSteps); continue test;}
					if(grid[newR][newC] == 'X') continue;
					if(visited[newR][newC]) continue;
					queue.add(newR*C+newC);
					visited[newR][newC] = true;
				}
			}
			System.out.println("#notworth");
		}
	}
}