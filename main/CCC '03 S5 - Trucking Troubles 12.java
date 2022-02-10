import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int c = nextInt(), r = nextInt(), d = nextInt(),i,x,y,w,newVal;
		ArrayList<Integer>[] roads = new ArrayList[c];
		ArrayList<Integer>[] weight = new ArrayList[c];
		for(i = 0; i < c; i++) {
			roads[i] = new ArrayList<Integer>();
			weight[i] = new ArrayList<Integer>();
		}
		for(i = 0; i < r; i++) {
			x = nextInt()-1; y = nextInt()-1; w = nextInt();
			roads[x].add(y); weight[x].add(w);
			roads[y].add(x); weight[y].add(w);
		}
		int[] visited = new int[c];
		visited[0] = Integer.MAX_VALUE;
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(0);
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			i = 0;
			for(int j: roads[curr]) {
				newVal = Math.max(visited[j], Math.min(visited[curr], weight[curr].get(i)));
				if(newVal > visited[j]) {
					queue.add(j);
					visited[j] = newVal;
				}
				i++;
			}
		}
		int ans = Integer.MAX_VALUE;
		for(i = 0; i < d; i++) ans = Math.min(ans, visited[nextInt()-1]);
		System.out.println(ans);
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