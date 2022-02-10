import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0; i < 5; i++) {
			char[][] grid = new char[10][10];
			int start = -1;
			for(int j = 0; j < 10; j++) {
				grid[j] = br.readLine().toCharArray();
				if(start == -1) {
					for(int k = 0; k < 10; k++) {
						if(grid[j][k] == 'X') {
							start = 10*j+k; break;
						}
					}
				}
			}
			int dist = 1;
			boolean[][] visited = new boolean[10][10];
			Queue<Integer> queue = new LinkedList<Integer>();
			queue.add(start); queue.add(-1);
			visited[start/10][start%10] = true;
			bfs:while(!queue.isEmpty()) {
				int curr = queue.poll();
				if(curr == -1) {
					if(!queue.isEmpty()) queue.add(-1);
					dist++; continue;
				}
				int r = curr/10, c = curr%10;
				for(int j = Math.max(r-1, 0); j <= Math.min(r+1, 9); j++) {
					for(int k = Math.max(c-1, 0); k <= Math.min(c+1, 9); k++) {
						if(j == r && k == c) continue;
						if(grid[j][k] == '#') continue;
						if(visited[j][k]) continue;
						visited[j][k] = true;
						if(grid[j][k] == 'X') {System.out.println(dist); break bfs;}
						queue.add(10*j+k);
					}
				}
			}
			if(i != 4) br.readLine();
		}
	}
}