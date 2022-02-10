import java.util.*;
import java.io.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), K = nextInt(),i;
		int N2 = 2*N;
		long[][] arr = new long[(int)(Math.log(N2+1)/Math.log(2))+1][];
		arr[0] = new long[N2+1];
		for(i = 1; i <= N; i++) arr[0][i] = arr[0][N+i] = nextInt();
		for(i = 1; i <= N2; i++) arr[0][i] += arr[0][i-1];
		int pow = 1, row = 1, end = 2*N+1-pow;
		while(end > 0) {
			arr[row] = new long[end];
			for(i = 0; i < end; i++) {
				arr[row][i] = Math.min(arr[row-1][i], arr[row-1][i+pow]);
			}
			row++;
			pow *= 2;
			end -= pow;
		}
		int R,range;
		long ans = Long.MIN_VALUE,min;
		for(i = K; i <= N2; i++) {
			R = i;
			pow = 1;
			range = K;
			row = 0;
			min = Long.MAX_VALUE;
			while(range > 0) {
				if((range & 1) == 1) {
					R -= pow;
					min = Math.min(min, arr[row][R]);
				}
				range >>= 1;
				row++;
				pow <<= 1;
			}
			ans = Math.max(ans, arr[0][i]-min);
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