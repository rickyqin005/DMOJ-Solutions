import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i,curr;
		PriorityQueue<Integer> spaces = new PriorityQueue<Integer>(N);
		Queue<Integer> line = new LinkedList<Integer>();
		for(i = 1; i <= N; i++) spaces.add(i);
		int[] rate = new int[N+1];
		for(i = 1; i <= N; i++) rate[i] = nextInt();
		int[] weight = new int[M+1];
		for(i = 1; i <= M; i++) weight[i] = nextInt();
		int[] carLoc = new int[M+1];
		M *= 2;
		long ans = 0;
		for(i = 0; i < M; i++) {
			curr = nextInt();
			if(curr > 0) {
				if(spaces.isEmpty()) line.add(curr);
				else {
					carLoc[curr] = spaces.poll();
					ans += weight[curr]*rate[carLoc[curr]];
				}
			} else {
				curr *= -1;
				if(!line.isEmpty()) {
					carLoc[line.peek()] = carLoc[curr];
					ans += weight[line.peek()]*rate[carLoc[line.poll()]];
				} else spaces.add(carLoc[curr]);
				carLoc[curr] = 0;
			}
		}
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