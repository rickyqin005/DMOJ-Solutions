import java.util.*;
import java.io.*;
public class Question {
	public static long[][] createSparseTable(long[] arr) {
		int N = arr.length,i;
		long[][] table = new long[(int)(Math.log(N)/Math.log(2))+1][];
		table[0] = new long[N];
		for(i = 0; i < N; i++) table[0][i] = arr[i];
		int pow = 1, row = 1, end = N-pow;
		while(end > 0) {
			table[row] = new long[end];
			for(i = 0; i < end; i++) {
				table[row][i] = Math.max(table[row-1][i], table[row-1][i+pow]);
			}
			row++;
			pow *= 2;
			end -= pow;
		}
		return table;
	}
	public static long max(int L, int R, long[][] table) {
		long ans = 0;
		int pow = 1;
		long range = R-L;
		int row = 0;
		while(range > 0) {
			if((range & 1) == 1) {
				R -= pow;
				ans = Math.max(ans, table[row][R]);
			}
			range >>= 1;
			row++;
			pow <<= 1;
		}
		return ans;
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(), i;
		long[][] arr = new long[N][2];
		for(i = 0; i < N; i++) {
			arr[i][0] = nextLong();
			arr[i][1] = i;
		}
		Arrays.sort(arr, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return Long.compare(a[0], b[0]);
			}
		});
		long[] diffArr = new long[N-1];
		for(i = 0; i < N-1; i++) {
			diffArr[i] = arr[i+1][0]-arr[i][0];
		}
		long[][] table = createSparseTable(diffArr);
		long ans = 0;
		for(i = 0; i < N; i++) {
			if(arr[i][1] != i) {
				ans = Math.max(ans, max((int)Math.min(i, arr[i][1]),(int)Math.max(i, arr[i][1]),table));
			}
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