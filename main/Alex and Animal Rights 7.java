import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int R = Integer.parseInt(st.nextToken()), C = Integer.parseInt(st.nextToken());
		char[][] room = new char[R][C];
		for(int i = 0; i < R; i++) {
			room[i] = br.readLine().toCharArray();
		}
		
		int ans = 0;
		int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
		boolean[][] visited = new boolean[R][C];
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(visited[i][j]) continue;
				visited[i][j] = true;
				if(room[i][j] == '#') continue;
				Queue<Integer> queue = new LinkedList<Integer>();
				boolean hasMonkey = false;
				queue.add(i*C+j);
				while(!queue.isEmpty()) {
					int curr = queue.poll();
					int r = curr/C, c = curr%C;
					if(room[r][c] == 'M') hasMonkey = true;
					for(int k = 0; k < 4; k++) {
						int newR = r+dir[k][0], newC = c+dir[k][1];
						if(newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
						if(visited[newR][newC]) continue;
						visited[newR][newC] = true;
						if(room[newR][newC] == '#') continue;
						queue.add(newR*C+newC);
					}
				}
				if(hasMonkey) ans++;
			}
		}
		System.out.println(ans);
	}
}