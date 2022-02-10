import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int m = Integer.parseInt(in[0]), n = Integer.parseInt(in[1]);
		ArrayList<Integer>[] graph = new ArrayList[26];
		for(int i = 0; i < 26; i++) {
			graph[i] = new ArrayList<Integer>(25);
		}
		for(int i = 0; i < m; i++) {
			in = br.readLine().split(" ");
			graph[in[0].charAt(0)-65].add(in[1].charAt(0)-65);
			graph[in[1].charAt(0)-65].add(in[0].charAt(0)-65);
		}
		for(int i = 0; i < n; i++) {
			in = br.readLine().split(" ");
			int A = in[0].charAt(0)-65;
			int B = in[1].charAt(0)-65;
			Queue<Integer> queue = new LinkedList<Integer>();
			boolean[] visited = new boolean[26];
			int[] previous = new int[26];
			queue.add(A);
			visited[A] = true;
			queue: while(!queue.isEmpty()) {
				int curr = queue.poll();
				for(int j: graph[curr]) {
					if(visited[j]) continue;
					visited[j] = true;
					previous[j] = curr;
					if(j == B) break queue;
					queue.add(j);
				}
			}
			LinkedList<Character> path = new LinkedList<Character>();
			while(true) {
				path.addFirst((char)(B+65));
				if(previous[B] == A) break;
				B = previous[B];
			}
			System.out.print((char)(A+65));
			for(char j: path) System.out.print(j);
			System.out.println();
		}
	}
}