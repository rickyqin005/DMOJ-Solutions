import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i,a,b,c;
		int[] startArr = new int[10000001];
		int[] endArr = new int[1000001];
		for(i = 1; i <= N; i++) {
			c = nextInt();
			if(startArr[c] == 0) startArr[c] = i;
			endArr[c] = i;
		}
		int ans = 0;
		for(i = 0; i < M; i++) {
			a = nextInt(); b = nextInt();
			if(startArr[a] == 0 || endArr[b] == 0) continue;
			ans = Math.max(ans, endArr[b]-startArr[a]+1);
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