import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		long N = nextLong(), K = nextLong(), M = nextLong();
		long low = 1, high = N+1,mid,sum,count,curr;
		long ans = 0;
		while(low < high) {
			mid = (low+high)/2;
			sum = N;
			count = 0;
			while(sum/mid > M && count < K) {
				curr = (sum-mid*(sum/mid))/(sum/mid)+1;
				count += curr;
				sum -= curr*(sum/mid);
			}
			if((K-count)*M >= sum) {
				low = mid+1;
				ans = Math.max(ans,mid);
			} else high = mid;
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