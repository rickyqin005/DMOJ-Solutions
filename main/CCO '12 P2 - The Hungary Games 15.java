import java.util.*;
import java.io.*;
public class Question2 {
	public static void insert(Node node, int val) {
		if(val == node.dist1 || val == node.dist2) return;
		if(val <= node.dist1) {
			node.dist2 = node.dist1;
			node.dist1 = val;
		} else if(val <= node.dist2) {
			node.dist2 = val;
		}
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt();
		if(N > M+1) {System.out.println(-1); return;}
		ArrayList<int[]>[] adj = new ArrayList[N+1];
		for(int i = 1; i <= N; i++) adj[i] = new ArrayList<int[]>();
		for(int i = 0; i < M; i++) {
			int a = nextInt(), b = nextInt(), l = nextInt();
			if(a == b) continue;
			adj[a].add(new int[] {b,l});
		}
		Node[] nodes = new Node[N+1];
		for(int i = 1; i <= N; i++) nodes[i] = new Node(i);
		nodes[1].dist1 = 0;
		
		PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {
			public int compare(Node n1, Node n2) {
				if(n1.dist1 == n2.dist1) return Integer.compare(n1.dist2, n2.dist2);
				else return Integer.compare(n1.dist1, n2.dist1);
			}
		});
		pq.add(nodes[1]);
		/*for(int[] j: adj[1]) {
			Node next = nodes[j[0]];
			insert(next, nodes[1].dist1+j[1]);
			pq.add(next);
		}*/
		System.out.print("");
		
		while(!pq.isEmpty()) {
			Node curr = pq.poll();
			for(int[] j: adj[curr.x]) {
				Node next = nodes[j[0]];
				boolean added = false;
				if(curr.dist1 == Integer.MAX_VALUE || curr.dist1+j[1] == next.dist1 || curr.dist1+j[1] == next.dist2);
				else if(curr.dist1+j[1] < next.dist1) {
					next.dist2 = next.dist1;
					next.dist1 = curr.dist1+j[1];
					added = true;
				} else if(curr.dist1+j[1] < next.dist2) {
					next.dist2 = curr.dist1+j[1];
					added = true;
				}
				if(curr.dist2 == Integer.MAX_VALUE || curr.dist2+j[1] == next.dist1 || curr.dist2+j[1] == next.dist2);
				else if(curr.dist2+j[1] < next.dist1) {
					next.dist2 = next.dist1;
					next.dist1 = curr.dist2+j[1];
					added = true;
				} else if(curr.dist2+j[1] < next.dist2) {
					next.dist2 = curr.dist2+j[1];
					added = true;
				}
				if(added) pq.add(next);
			}
		}
		if(nodes[N].dist2 == Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(nodes[N].dist2);
	}
	static class Node {
		public int x, dist1 = Integer.MAX_VALUE, dist2 = dist1;
		public Node(int X) {
			x = X;
		}
		public String toString() {
			return "["+x+" "+dist1+" "+dist2+"]";
		}
	}
	static long nextLong() throws IOException {return Long.parseLong(next());}
	static int nextInt() throws IOException {return Integer.parseInt(next());}
	static double nextDouble() throws IOException {return Double.parseDouble(next());}
	static String nextLine() throws IOException {return br.readLine().trim();}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}