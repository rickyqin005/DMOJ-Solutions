import java.io.*;
import java.util.*;
public class Question5 {
	static int[][] dir = {{1,0},{-1,0},{0,1},{0,-1}};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        int R = Integer.parseInt(in[0]), C = Integer.parseInt(in[1]);
        char[][] grid = new char[R][C];
        in = br.readLine().split(" ");
        int start = Integer.parseInt(in[0])*C + Integer.parseInt(in[1]);
        in = br.readLine().split(" ");
        int end = Integer.parseInt(in[0])*C + Integer.parseInt(in[1]);
        for(int i = 0; i < R; i++) {
        	grid[i] = br.readLine().toCharArray();
        }
        int T = Integer.parseInt(br.readLine());
        HashSet<Integer> devices = new HashSet<Integer>();
        for(int i = 0; i < T; i++) {
        	in = br.readLine().split(" ");
        	devices.add(Integer.parseInt(in[0])*C + Integer.parseInt(in[1]));
        }
        if(start == end) {System.out.println(0); return;}
        if(T == 0) {System.out.println(0); return;}
        Queue<Integer> queue1 = new LinkedList<Integer>();
        boolean[][] visited1 = new boolean[R][C];
        int dist1 = 1;
        queue1.add(start); visited1[start/C][start%C] = true;
        queue1.add(-1);
        queue: while(!queue1.isEmpty()) {
        	int curr = queue1.poll();
        	if(curr == -1) {
        		if(!queue1.isEmpty()) queue1.add(-1);
        		dist1++; continue;
        	}
        	int r = curr/C, c = curr%C;
        	for(int i = 0; i < 4; i++) {
        		int newR = r+dir[i][0], newC = c+dir[i][1];
        		if(newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
        		if(grid[newR][newC] == 'X') continue;
        		if(visited1[newR][newC]) continue;
        		if(newR == end/C && newC == end%C) break queue;
        		queue1.add(newR*C+newC);
        		visited1[newR][newC] = true;
        	}
        }
        //System.out.println(dist1);
        Queue<Integer> queue2 = new LinkedList<Integer>();
        boolean[][] visited2 = new boolean[R][C];
        int dist2 = 1;
        if(devices.contains(start)) {System.out.println(dist1); return;}
        queue2.add(start); visited2[start/C][start%C] = true;
        queue2.add(-1);
        queue: while(!queue2.isEmpty()) {
        	int curr = queue2.poll();
        	if(curr == -1) {
        		if(!queue2.isEmpty()) queue2.add(-1);
        		dist2++; continue;
        	}
        	int r = curr/C, c = curr%C;
        	for(int i = 0; i < 4; i++) {
        		int newR = r+dir[i][0], newC = c+dir[i][1];
        		if(newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
        		if(grid[newR][newC] == 'X') continue;
        		if(visited2[newR][newC]) continue;
        		if(devices.contains(newR*C+newC)) break queue;
        		queue2.add(newR*C+newC);
        		visited2[newR][newC] = true;
        	}
        }
        System.out.println(Math.max(0, dist1-dist2));
    }
}