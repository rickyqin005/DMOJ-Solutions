import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()), H = Integer.parseInt(st.nextToken());
		boolean[][] isVisited = new boolean[N][N];
		short[][] field = new short[N][N];
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				field[i][j] = Short.parseShort(st.nextToken());
			}
		}
		if(N == 1) {System.out.println("yes"); return;}
		int[][] dir = {{0,1},{1,0},{0,-1},{-1,0}};
		LinkedList<Integer> queue = new LinkedList<Integer>();
		queue.add(0);
		isVisited[0][0] = true;
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			int r = curr/N, c = curr % N;
			for(int i = 0; i < 4; i++) {
				int newR = r+dir[i][0], newC = c+dir[i][1];
				if(newR < 0 || newR >= N || newC < 0 || newC >= N) continue;
				if(Math.abs(field[r][c] - field[newR][newC]) > H) continue;
				if(isVisited[newR][newC]) continue;
				if(newR == N-1 && newC == N-1) {System.out.println("yes"); return;}
				queue.add(N*(newR)+newC);
				isVisited[newR][newC] = true;
			}
		}
		System.out.println("no");
	}
}