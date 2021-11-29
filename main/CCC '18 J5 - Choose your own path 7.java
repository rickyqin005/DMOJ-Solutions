import java.io.*;
import java.util.LinkedList;
public class Question3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String[][] book = new String[N+1][];
		boolean[] visited = new boolean[N+1];
		for(int i = 1; i <= N; i++) {
			book[i] = br.readLine().split(" ");
		}
		
		LinkedList<Integer> queue = new LinkedList<Integer>();
		boolean foundMinPath = false;
		int minPath = 1;
		queue.add(1);
		queue.add(-1);
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			if(curr < 0) {
				if(!foundMinPath) {queue.add(-1); minPath++;}
				continue;
			}
			visited[curr] = true;
			if(book[curr][0].equals("0")) foundMinPath = true;
			for(int i = 1; i < book[curr].length; i++) {
				int num = Integer.parseInt(book[curr][i]);
				if(!visited[num]) queue.add(num);
			}
		}
		boolean isReachable = true;
		for(int i = 1; i <= N; i++) {
			if(!visited[i]) {isReachable = false; break;}
		}
		if(isReachable) System.out.println("Y");
		else System.out.println("N");
		System.out.println(minPath);
	}
}