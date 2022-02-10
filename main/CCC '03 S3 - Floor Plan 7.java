import java.io.*;
import java.util.*;
public class Question5 {
	static int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
	static int ans = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Integer> roomSizes = new ArrayList<Integer>();
        int flooring = Integer.parseInt(br.readLine());
        int R = Integer.parseInt(br.readLine());
        int C = Integer.parseInt(br.readLine());
        char[][] grid = new char[R][C];
        for(int i = 0; i < R; i++) {
        	grid[i] = br.readLine().toCharArray();
        }
        boolean[][] checked = new boolean[R][C];
        for(int i = 0; i < R; i++) {
        	for(int j = 0; j < C; j++) {
        		if(checked[i][j]) continue;
        		checked[i][j] = true;
        		if(grid[i][j] == 'I') continue;
        		
        		int size = 1;
        		LinkedList<Integer> queue = new LinkedList<Integer>();
        		queue.add(i*C+j);
        		while(!queue.isEmpty()) {
        			int curr = queue.poll();
        			int r = curr/C, c = curr%C;
        			for(int k = 0; k < 4; k++) {
        				int newR = r+dir[k][0], newC = c+dir[k][1];
        				if(newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
        				if(checked[newR][newC]) continue;
        				checked[newR][newC] = true;
        				if(grid[newR][newC] == 'I') continue;
        				queue.add(newR*C+newC);
        				size++;
        			}
        		}
        		roomSizes.add(size);
        		//System.out.println(size);
        	}
        }
        Collections.sort(roomSizes,Collections.reverseOrder());
        for(int i: roomSizes) {
        	if(flooring-i < 0) break;
        	flooring -= i;
        	ans++;
        }
        System.out.println(ans + " room" + (ans==1?"":"s") + ", " + flooring + " square metre(s) left over");
    }
}