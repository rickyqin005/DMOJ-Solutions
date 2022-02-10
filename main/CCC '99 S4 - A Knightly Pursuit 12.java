import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		test: for(int i = 0; i < n; i++) {
			int R = Integer.parseInt(br.readLine()), C = Integer.parseInt(br.readLine());
			int pr = R-Integer.parseInt(br.readLine()), pc = Integer.parseInt(br.readLine())-1;
			int kr = Integer.parseInt(br.readLine()), kc = Integer.parseInt(br.readLine());
			int[][] kVisited = new int[R][C];
			Queue<Integer> queue = new LinkedList<Integer>();
			queue.add((R-kr)*C+kc-1);
			while(!queue.isEmpty()) {
				int curr = queue.poll();
				int r = curr/C, c = curr%C;
				int numMoves = kVisited[r][c];
				if(pr-numMoves == 0) break;
				if(c == pc) {
					if(r == pr-numMoves) {System.out.println("Win in "+numMoves+" knight move(s)."); continue test;}
					if(r == pr-numMoves-1) {System.out.println("Stalemate in "+numMoves+" knight move(s)."); continue test;}
				}
				
				for(int j = Math.max(r-2,0); j <= Math.min(r+2, R-1); j++) {
					for(int k = Math.max(c-2,0); k <= Math.min(c+2, C-1); k++) {
						if(Math.abs(r-j) + Math.abs(c-k) == 3) {
							if(numMoves+1 == kVisited[j][k]) continue;
							kVisited[j][k] = numMoves+1;
							queue.add(j*C+k);
						}
					}
				}
			}
			System.out.println("Loss in "+Math.max((pr-1),0)+" knight move(s).");
		}
	}
}