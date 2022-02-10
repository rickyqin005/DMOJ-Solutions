import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), i;
		int[] arr = new int[N];
		for(i = 0; i < N; i++) arr[i] = nextInt();
		Arrays.sort(arr);
		for(i = 0; i < N; i++) {
			if(arr[i] > 100) break;
		}
		if(i == 0) System.out.println(0);
		else if(i == 1) System.out.println(arr[0]);
		else System.out.println(arr[i-1]+arr[i-2]);
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