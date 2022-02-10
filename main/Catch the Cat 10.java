import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int X = nextInt(), Y = nextInt(),curr;
		if(X == Y) {System.out.println(0); return;}
		int[] dist = new int[2*Math.max(X, Y)+1];
		boolean[] visited = new boolean[dist.length];
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(X);
		visited[X] = true;
		while(!queue.isEmpty()) {
			curr = queue.poll();
			if(curr > 0) {
				if(!visited[curr-1]) {
					if(curr-1 == Y) {System.out.println(dist[curr]+1); return;}
					queue.add(curr-1); dist[curr-1] = dist[curr]+1;
					visited[curr-1] = true;
				}
			}
			if(curr != dist.length-1) {
				if(!visited[curr+1]) {
					if(curr+1 == Y) {System.out.println(dist[curr]+1); return;}
					queue.add(curr+1); dist[curr+1] = dist[curr]+1;
					visited[curr+1] = true;
				}
			}
			if(curr*2 < dist.length) {
				if(!visited[curr*2]) {
					if(curr*2 == Y) {System.out.println(dist[curr]+1); return;}
					queue.add(curr*2); dist[curr*2] = dist[curr]+1;
					visited[curr*2] = true;
				}
			}
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