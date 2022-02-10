import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt();
		int[] height = new int[N];
		int maxHeight = -1, maxIndex = 0;
		for(int i = 0; i < N; i++) {
			height[i] = nextInt();
			if(height[i] > maxHeight) {
				maxIndex = i; maxHeight = height[i];
			}
		}
		long ans = 0;
		int maxVisited = height[0];
		for(int i = 1; i < maxIndex; i++) {
			if(height[i] < maxVisited) ans += maxVisited-height[i];
			else maxVisited = height[i];
		}
		maxVisited = height[N-1];
		for(int i = N-2; i > maxIndex; i--) {
			if(height[i] < maxVisited) ans += maxVisited-height[i];
			else maxVisited = height[i];
		}
		System.out.println(ans);
	}
	
	static long nextLong() throws IOException { return Long.parseLong(next()); }
	static int nextInt() throws IOException { return Integer.parseInt(next()); }
	static double nextDouble() throws IOException { return Double.parseDouble(next()); }
	static String nextLine() throws IOException { return br.readLine().trim(); }
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}