import java.util.*;
import java.io.*;
public class Question {
	public static long pow10(int pow) {
		long ans = 1;
		for(int i = 0; i < pow; i++) {
			ans *= 10;
		}
		return ans;
	}
	public static void main(String[] args) throws IOException {
		long N = nextLong(), ans = 0;
		int lengthN = (int)Math.log10(N);
		if(lengthN > 0) ans += 9;
		for(int i = 2; i < lengthN; i+=2) {
			ans += 9*pow10(i);
		}
		if(lengthN % 2 == 0) {
			ans += N-pow10(lengthN)+1;
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