import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		while(true) {
			int N = nextInt();
			int N2 = N*N;
			int ans = 0;
			if(N == 0) break;
			for(int i = N-1; i > 0; i--) 
				ans += (int)Math.sqrt(N2-i*i);
			ans *= 4;
			ans += 4*N+1;
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