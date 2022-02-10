import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int N = Integer.parseInt(in[0]), M = Integer.parseInt(in[1]);
		ArrayList<Integer>[] graph = new ArrayList[N+1];
		for(int i = 0; i < N+1; i++) {
			graph[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < M; i++) {
			in = br.readLine().split(" ");
			graph[Integer.parseInt(in[0])].add(Integer.parseInt(in[1]));
		}
		in = br.readLine().split(" ");
		int p = Integer.parseInt(in[0]), q = Integer.parseInt(in[1]);
		if(graph[p].size() == 0 && graph[q].size() == 0) {System.out.println("unknown"); return;}
		
		boolean[] visited = new boolean[N+1];
		Queue<Integer> queue = new LinkedList<Integer>();
		for(int i: graph[p]) {
			if(i == q) {System.out.println("yes"); return;}
			queue.add(i);
			visited[i] = true;
		}
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			for(int i: graph[curr]) {
				if(i == q) {System.out.println("yes"); return;}
				if(visited[i]) continue;
				queue.add(i);
				visited[i] = true;
			}
		}
		
		for(int i: graph[q]) {
			if(i == p) {System.out.println("no"); return;}
			queue.add(i);
			visited[i] = true;
		}
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			for(int i: graph[curr]) {
				if(i == p) {System.out.println("no"); return;}
				if(visited[i]) continue;
				queue.add(i);
				visited[i] = true;
			}
		}
		System.out.println("unknown");
	}
}