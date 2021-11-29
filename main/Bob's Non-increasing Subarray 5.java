import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i;
		int[] arr = new int[N];
		for(i = 0; i < N; i++) arr[i] = nextInt();
		int maxLen = 1;
		int currLen = 1;
		for(i = 1; i < N; i++) {
			if(arr[i-1] >= arr[i]) currLen++;
			else {
				maxLen = Math.max(maxLen, currLen);
				currLen = 1;
			}
		}
		System.out.println(Math.max(maxLen, currLen));
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