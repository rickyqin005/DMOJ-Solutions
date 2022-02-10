import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt()-1,i,j;
		int[] arr = new int[N];
		for(i = 0; i < N; i++) arr[i] = nextInt();
		Arrays.sort(arr);
		int low = 1, high = 0, mid = 0;
		for(i = 0; i < N-1; i++) {
			arr[i] = arr[i+1]-arr[i];
			high += arr[i];
		}
		arr[N-1] = 0;
		high /= M;
		high++;
		int ans = 0;
		while(low < high) {
			mid = (low+high)/2;
			int sum = 0;
			int count = 1;
			for(i = 0; i < N; i++) {
				if(count > M) break;
				if(sum >= mid) {
					count++;
					sum = 0;
				}
				sum += arr[i];
			}
			if(count > M) {
				ans = Math.max(ans, mid);
				low = mid+1;
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