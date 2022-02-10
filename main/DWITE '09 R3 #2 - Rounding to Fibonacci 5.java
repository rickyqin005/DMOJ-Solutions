import java.util.*;
import java.io.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		for(int i = 0; i < 5; i++) {
			int N = nextInt();
			if(N == 0) {System.out.println(0); continue;}
			if(N == 1) {System.out.println(1); continue;}
			int ans = 0;
			int prev1 = 1;
			int prev2 = 0;
			int curr = 1;
			while(curr <= N) {
				ans = curr;
				prev2 = prev1;
				prev1 = curr;
				curr = prev2+prev1;
			}
			if(curr-N <= N-ans) ans = curr;
			System.out.println(ans);
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