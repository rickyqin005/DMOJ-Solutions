import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
public class Graph {
	HashMap<Integer,HashSet<Integer>> map = new HashMap<>();
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Graph graph = new Graph();
		int N = in.nextInt(), M = in.nextInt(), A = in.nextInt(), B = in.nextInt();
		for(int i = 1; i <= N; i++) {
			graph.map.put(i,new HashSet<Integer>());
		}
		for(int i = 0; i < M; i++) {
			int i1 = in.nextInt(), i2 = in.nextInt();
			graph.map.get(i1).add(i2);
			graph.map.get(i2).add(i1);
		}
		
		LinkedList<Integer> queue = new LinkedList<Integer>();
		boolean[] isVisited = new boolean[N+1];
		queue.add(A);
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			if(isVisited[curr]) continue;
			if(curr == B) {System.out.println("GO SHAHIR!"); System.exit(0);}
			for(int i: graph.map.get(curr)) {
				queue.add(i);
			}
			isVisited[curr] = true;
		}
		System.out.println("NO SHAHIR!");
	}
}