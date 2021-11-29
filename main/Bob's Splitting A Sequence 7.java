import java.io.*;
import java.util.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i,j;
		long[] arr = new long[N+1];
		for(i = 1; i <= N; i++) arr[i] = arr[i-1] + nextInt();
		int low,high,mid;
		long sub1,sub2,sub3;
		long ans = Long.MAX_VALUE;
		for(i = 1; i < N-1; i++) {
			sub1 = arr[i];
			low = i; high = N;
			while(low < high) {
				mid = (low+high)/2;
				sub2 = arr[mid]-arr[i];
				sub3 = arr[N]-arr[mid];
				ans = Math.min(ans,Math.max(sub1,Math.max(sub2,sub3))-Math.min(sub1,Math.min(sub2,sub3)));
				if(sub2 < sub3) {
					low = mid+1;
				} else {
					high = mid;
				}
			}
		}
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