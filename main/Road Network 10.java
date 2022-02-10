import java.util.*;
import java.io.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i,j,u,v;
		int[][] vill = new int[N][2];
		for(i = 0; i < N; i++) {
			vill[i][0] = nextInt();
			vill[i][1] = nextInt();
		}
		PriorityQueue<Edge> edge = new PriorityQueue<Edge>(N*N, new Comparator<Edge>() {
			public int compare(Edge a, Edge b) {
				return Double.compare(a.dist, b.dist);
			}
		});
		
		boolean[][] hasRoad = new boolean[N][N];
		for(i = 0; i < M; i++) {
			u = nextInt()-1; v = nextInt()-1;
			hasRoad[u][v] = true;
			hasRoad[v][u] = true;
		}
		
		boolean[] visited = new boolean[N];
		visited[0] = true;
		for(i = 1; i < N; i++) {
			if(hasRoad[0][i]) edge.add(new Edge(0,i,0));
			else edge.add(new Edge(0,i,Math.sqrt((long)(vill[0][0]-vill[i][0])*(vill[0][0]-vill[i][0])+(long)(vill[0][1]-vill[i][1])*(vill[0][1]-vill[i][1]))));
		}
		
		double ans = 0;
		int next = 0;
		Edge currEdge = null;
		for(i = 0; i < N-1; i++) {
			while(!edge.isEmpty()) {
				currEdge = edge.poll();
				if(visited[currEdge.u] != visited[currEdge.v]) break;
			}
			if(!visited[currEdge.u]) next = currEdge.u;
			else next = currEdge.v;
			visited[next] = true;
			
			for(j = 0; j < N; j++) {
				if(visited[j]) continue;
				if(hasRoad[next][j]) edge.add(new Edge(next,j,0));
				else edge.add(new Edge(next,j,Math.sqrt((long)(vill[next][0]-vill[j][0])*(vill[next][0]-vill[j][0])+(long)(vill[next][1]-vill[j][1])*(vill[next][1]-vill[j][1]))));
			}
			ans += currEdge.dist;
		}
		//System.out.printf("%.02f\n",(long)(ans*100)/100.0);
		System.out.printf("%.02f\n",ans);
	}
	static class Edge {
		int u,v;
		double dist;
		public Edge(int U, int V, double D) {u = U; v = V; dist = D;}
		public String toString() {
			return u + "  " + v + "  " + dist;
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