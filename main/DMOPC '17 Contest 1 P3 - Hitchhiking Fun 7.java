import java.util.*;
import java.io.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt();
		ArrayList<Integer>[] adj = new ArrayList[N+1];
		for(int i = 1; i <= N; i++) adj[i] = new ArrayList<Integer>();
		for(int i = 0; i < M; i++) {
			int a = nextInt(), b = nextInt(), t = nextInt();
			if(a == b) continue;
			adj[a].add(b*(t==0?1:-1));
			adj[b].add(a*(t==0?1:-1));
		}
		Node[] nodes = new Node[N+1];
		for(int i = 1; i <= N; i++) nodes[i] = new Node(i, Integer.MAX_VALUE);
		nodes[1].dangerous = 0;
		
		PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {
			public int compare(Node n1, Node n2) {
				if(n1.dangerous == n2.dangerous) return Integer.compare(n1.dist, n2.dist);
				else return Integer.compare(n1.dangerous, n2.dangerous);
			}
		});
		pq.add(nodes[1]);
		
		while(!pq.isEmpty()) {
			Node curr = pq.poll();
			if(curr.checked) continue;
			curr.checked = true;
			for(int j: adj[curr.x]) {
				int safe = 0;
				if(j < 0) {
					safe = 1;
					j = -j;
				}
				Node next = nodes[j];
				if(next.checked) continue;
				if(curr.dangerous+safe < next.dangerous) {
					next.dangerous = curr.dangerous+safe;
					next.dist = curr.dist+1;
					pq.add(next);
				} else if(curr.dangerous+safe == next.dangerous) {
					if(curr.dist+1 < next.dist) {
						next.dist = curr.dist+1;
						pq.add(next);
					}
					
				}
			}
		}
		if(nodes[N].dangerous == Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(nodes[N].dangerous + " " + nodes[N].dist);
	}
	static class Node {
		public int x, dangerous, dist = 0;
		public boolean checked = false;
		public Node(int X, int d) {
			x = X;
			dangerous = d;
		}
		public String toString() {
			return "["+x+" "+dangerous+" "+dist+" "+(checked?"T":"F")+"]";
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