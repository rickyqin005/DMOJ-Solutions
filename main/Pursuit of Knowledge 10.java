import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int N = Integer.parseInt(in[0]), M = Integer.parseInt(in[1]), T = Integer.parseInt(in[2]);
		ArrayList<Integer>[] connections = new ArrayList[N];
		int[][] dist = new int[N][N];
		for(int i = 0; i < N; i++) {
			connections[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < M; i++) {
			in = br.readLine().split(" ");
			connections[Integer.parseInt(in[0])-1].add(Integer.parseInt(in[1])-1);
		}
		
		for(int i = 0; i < N; i++) {
			boolean[] visited = new boolean[N];
			LinkedList<Integer> queue = new LinkedList<Integer>();
			int currDist = 1;
			queue.add(i); queue.add(-1);
			visited[i] = true;
			while(!queue.isEmpty()) {
				int curr = queue.poll();
				if(curr == -1) {
					if(!queue.isEmpty()) queue.add(-1);
					currDist++; continue;
				}
				for(int j: connections[curr]) {
					if(!visited[j]) {
						dist[i][j] = currDist;
						visited[j] = true;
						queue.add(j);
					}
				}
			}
		}
		
		int Q = Integer.parseInt(br.readLine());
		for(int i = 0; i < Q; i++) {
			in = br.readLine().split(" ");
			int ans = dist[Integer.parseInt(in[0])-1][Integer.parseInt(in[1])-1]*T;
			if(ans == 0) System.out.println("Not enough hallways!");
			else System.out.println(ans);
		}
	}
}