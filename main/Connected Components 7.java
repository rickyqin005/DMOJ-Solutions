import java.io.*;
import java.util.*;
public class Question5 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<Integer,HashSet<Integer>> graph = new HashMap<Integer,HashSet<Integer>>();
		int N = Integer.parseInt(br.readLine());
		for(int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			graph.put(i, new HashSet<Integer>());
			for(int j = 1; j <= N; j++) {
				if(st.nextToken().equals("1")) graph.get(i).add(j);
			}
		}
		HashSet<Integer> vertices = new HashSet<Integer>();
		LinkedList<Integer> queue = new LinkedList<Integer>();
		for(int i = 1; i <= N; i++) {
			if(!graph.containsKey(i)) continue;
			vertices.add(i);
			queue.addAll(graph.get(i));
			vertices.addAll(graph.get(i));
			while(!queue.isEmpty()) {
				int curr = queue.poll();
				graph.get(curr).removeAll(vertices);
				queue.addAll(graph.get(curr));
				vertices.addAll(graph.get(curr));
				graph.remove(curr);
			}
			LinkedList<Integer> list = new LinkedList<Integer>(vertices);
			Collections.sort(list);
			for(int j: list) {
				System.out.print(j+" ");
			}
			System.out.println();
			vertices.clear();
		}
	}
}