import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(); nextInt();
		String[] arr = new String[N];
		for(int i = 0; i < N; i++) {
			arr[i] = nextLine();
		}
		Arrays.sort(arr);
		for(int i = N-1; i >= 0; i--) {
			System.out.print(arr[i]);
		}
		System.out.println();
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