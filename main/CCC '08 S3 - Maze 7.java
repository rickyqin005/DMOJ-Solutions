import java.io.*;
import java.util.*;
public class Question5 {
	static char[][] city;
	boolean[][] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int t = Integer.parseInt(br.readLine());
        test: for(int i = 0; i < t; i++) {
        	int R = Integer.parseInt(br.readLine()),C = Integer.parseInt(br.readLine());
        	char[][] city = new char[R][C];
        	boolean[][] visited = new boolean[R][C];
        	for(int j = 0; j < R; j++) {
        		city[j] = br.readLine().toCharArray();
        	}
        	if(R == 1 && C == 1) {System.out.println(1); continue test;}
        	LinkedList<Integer> queue = new LinkedList<Integer>();
        	int ans = 2;
        	queue.add(0); visited[0][0] = true;
        	queue.add(-1);
        	while(!queue.isEmpty()) {
        		int curr = queue.poll();
        		if(curr == -1) {
        			if(!queue.isEmpty()) queue.add(-1);
        			ans++; continue;
        		}
        		int r = curr/C, c = curr%C;
        		boolean[] allowedDir = new boolean[4];// false = allowed, true = not allowed
        		if(city[r][c] == '-') {
        			allowedDir[2] = true; allowedDir[3] = true;
        		} else if(city[r][c] == '|') {
        			allowedDir[0] = true; allowedDir[1] = true;
        		}
        		for(int j = 0; j < 4; j++) {
        			if(allowedDir[j]) continue;
        			int newR = r+dir[j][0], newC = c+dir[j][1];
        			if(newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
        			if(city[newR][newC] == '*') continue;
        			if(visited[newR][newC]) continue;
        			if(newR == R-1 && newC == C-1) {System.out.println(ans); continue test;}
        			queue.add(newR*C+newC);
        			visited[newR][newC] = true;
        		}
        	}
        	System.out.println(-1);
        }
    }
}