import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int T = nextInt(),i,ans;
		long X;
		for(i = 0; i < T; i++) {
			X = nextLong();
			ans = 0;
			while(X != 0) {
				if(X == 3) {ans += 3; break;}
				if((X & 1) == 1) {
					if((X & 3) == 3) X++;
					else X--;
				} else X >>= 1;
				ans++;
			}
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