import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean[][] isVisited = new boolean[8][8];
		StringTokenizer st = new StringTokenizer(br.readLine());
		int c1 = Integer.parseInt(st.nextToken())-1, r1 = Integer.parseInt(st.nextToken())-1;
		st = new StringTokenizer(br.readLine());
		int c2 = Integer.parseInt(st.nextToken())-1, r2 = Integer.parseInt(st.nextToken())-1;
		int ans = 0;
		LinkedList<Integer> queue = new LinkedList<Integer>();
		queue.add(8*c1+r1); queue.add(-1);
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			if(curr == -1) {
				if(!queue.isEmpty()) queue.add(-1);
				ans++; continue;
			}
			int c = curr/8, r = curr%8;
			if(c == c2 && r == r2) break;
			if(isVisited[7-r][c]) continue;
			for(int i = Math.min(7, r+2); i >= Math.max(0, r-2); i--) {
				for(int j = Math.max(0, c-2); j <= Math.min(7, c+2); j++) {
					if(Math.abs(i-r)+Math.abs(j-c) == 3) queue.add(8*j+i);
				}
			}
			isVisited[7-r][c] = true;
		}
		System.out.println(ans);
	}
}