import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i,j;
		int[] arr = new int[N];
		for(i = 0; i < N; i++) arr[i] = nextInt();
		long low = 1, high = 1, mid = 0;
		long ans = Long.MAX_VALUE;
		for(i = 0; i < N; i++) high += arr[i];
		while(low < high) {
			mid = (low+high)/2;
			int sum = 0;
			int count = 1;
			boolean valid = true;
			for(i = 0; i < N; i++) {
				if(arr[i] > mid) {valid = false; break;}
				sum += arr[i];
				if(sum > mid) {
					count++;
					sum = arr[i];
				}
				if(count > M) {valid = false; break;}
			}
			if(valid) {
				ans = Math.min(ans, mid);
				high = mid;
			} else low = mid+1;
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