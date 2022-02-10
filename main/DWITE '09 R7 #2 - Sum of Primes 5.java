import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int n = 100000, i,j,N,ans;
		boolean[] arr = new boolean[n+1];
		int sqrtN = (int)Math.sqrt(n);
		for(i = 4; i <= n; i+=2) arr[i] = true;
		for(i = 3; i <= sqrtN; i+=2) {
			if(arr[i]) continue;
			for(j = i*i; j <= n; j+=i) arr[j] = true;
		}
		for(i = 0; i < 5; i++) {
			N = nextInt();
			ans = 0;
			if(N >= 2) ans += 2;
			for(j = 3; j <= N; j++) if(!arr[j]) ans += j;
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