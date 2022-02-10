import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), T = nextInt(), M = nextInt(),i;
		int[] score = new int[N];
		for(i = 0; i < M; i++) score[nextInt()-1]++;
		int ans = 0;
		for(i = 0; i < N; i++) {
			if(T-M+score[i] > 0) ans++;
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