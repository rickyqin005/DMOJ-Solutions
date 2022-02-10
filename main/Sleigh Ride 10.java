import java.io.*;
import java.util.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int ans = 0;
		int N = Integer.parseInt(br.readLine());
		ArrayList<Integer>[] connections = new ArrayList[N+1];
		ArrayList<Integer>[] connectionDist = new ArrayList[N+1];
		for(int i = 0; i < N+1; i++) {
			connections[i] = new ArrayList<Integer>();
			connectionDist[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < N; i++) {
			String[] in = br.readLine().split(" ");
			int a = Integer.parseInt(in[0]), c = Integer.parseInt(in[2]);
			connections[a].add(Integer.parseInt(in[1]));
			connectionDist[a].add(c);
			ans += c*2;
		}
		
		int[] dist = new int[N+1];
		LinkedList<Integer> queue = new LinkedList<Integer>();
		queue.add(0);
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			int count = 0;
			for(int i: connections[curr]) {
				dist[i] = dist[curr]+connectionDist[curr].get(count);
				queue.add(i);
				count++;
			}
		}
		int maxPath = 0;
		for(int i = 0; i <= N; i++) {
			maxPath = Math.max(maxPath, dist[i]);
		}
		System.out.println(ans-maxPath);
	}
}