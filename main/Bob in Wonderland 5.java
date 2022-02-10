import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i;
		int[] height = new int[N];
		for(i = 0; i < N; i++) height[i] = nextInt();
		Arrays.sort(height);
		int low,high,mid,ans,t;
		for(i = 0; i < M; i++) {
			t = nextInt();
			low = 0; high = N; mid = 0;
			ans = N;
			while(low < high) {
				mid = (low+high)/2;
				if(height[mid] >= t) {
					ans = Math.min(ans, mid);
					high = mid;
				} else low = mid+1;
			}
			System.out.println(N-ans);
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