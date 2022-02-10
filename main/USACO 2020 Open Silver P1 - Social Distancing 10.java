import java.util.*;
import java.io.*;
public class Question4 {
	
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),j;
		int[][] interval = new int[M][2];
		for(j = 0; j < M; j++) {
			interval[j][0] = nextInt();
			interval[j][1] = nextInt();
		}
		Arrays.sort(interval,new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[0], b[0]);
			}
		});
		long low = 1, high = interval[M-1][1]-interval[0][0], mid = 0,i;
		int curr,count;
		long ans = 1;
		while(low < high) {
			mid = (low+high)/2;
			curr = 0;
			count = 0;
			for(i = interval[0][0]; i <= interval[M-1][1]; i += mid) {
				if(i > interval[curr][1]) {
					while(i > interval[curr][1]) {
						if(curr+1 == M) break;
						curr++;
					}
					i = Math.max(i, interval[curr][0]);
				}
				count++;
			}
			if(count < N) high = mid;
			else {
				low = mid+1;
				ans = Math.max(ans, mid);
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