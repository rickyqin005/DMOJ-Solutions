import java.io.*;
import java.util.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i,j;
		int[] B = new int[N-1];
		for(i = 0; i < N-1; i++) B[i] = nextInt();
		long ans = 0;
		for(i = 1; i < N-1; i++) {
			ans += Math.min(B[i], B[i-1]);
		}
		ans += B[0] + B[N-2];
		System.out.println(ans);
	}
	static int nextInt() throws IOException {return Integer.parseInt(next());}
	static String nextLine() throws IOException {return br.readLine().trim();}
	static String next() throws IOException {
		while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}