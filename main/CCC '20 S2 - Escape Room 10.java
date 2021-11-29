import java.io.*;
import java.util.HashSet;
import java.util.LinkedList;
public class Cell {
	int row, col;
	public Cell(int r, int c) {
		row = r; col = c;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int M = Integer.parseInt(br.readLine()), N = Integer.parseInt(br.readLine());
		String[][] grid = new String[M][N];
		HashSet<Integer> visited = new HashSet<Integer>();
		int maxMN = Math.max(M,N);
		for(int i = 0; i < M; i++) {
			grid[i] = br.readLine().split(" ");
		}
		
		LinkedList<Cell> queue = new LinkedList<Cell>();
		queue.add(new Cell(0,0));
		while(!queue.isEmpty()) {
			Cell curr = queue.poll(); 
			int r = curr.row, c = curr.col;
			int val = Integer.parseInt(grid[r][c]);
			int sqrt = (int)Math.sqrt(val);
			
			if(r == M-1 && c == N-1) {System.out.println("yes"); System.exit(0);}
			if(visited.contains(val)) continue;
			visited.add(val);
			
			for(int i = Math.max(val/maxMN,1); i <= sqrt; i++) {
				if(val % i == 0) {
					if(i <= M && val/i <= N) queue.add(new Cell(i-1,val/i-1));
					if(i <= N && val/i <= M) queue.add(new Cell(val/i-1,i-1));
				}
			}
		}
		System.out.println("no");
	}
}