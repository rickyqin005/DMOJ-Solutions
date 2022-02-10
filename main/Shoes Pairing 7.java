import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i;
		int[][] left = new int[N+1][2];
		int[] ans = new int[N+1];
		int[] right = new int[N];
		for(i = 0; i <= N; i++) {
			left[i][0] = nextInt(); left[i][1] = i;
		}
		for(i = 0; i < N; i++) right[i] = nextInt();
		Arrays.sort(left, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[0], b[0]);
			}
		});
		Arrays.sort(right);
		
		int[] maxDiff2 = new int[N];
		maxDiff2[N-1] = Math.max(left[N][0]-right[N-1],0);
		for(i = N-2; i >= 0; i--) maxDiff2[i] = Math.max(maxDiff2[i+1], Math.max(left[i+1][0]-right[i],0));
		
		int prevMaxDiff1 = Math.max(left[0][0]-right[0], 0);
		
		for(i = 0; i < N; i++) {
			ans[left[i][1]] = Math.max(prevMaxDiff1,Math.max(prevMaxDiff1, maxDiff2[i]));
			prevMaxDiff1 = Math.max(prevMaxDiff1, Math.max(left[i][0]-right[i], 0));
		}
		ans[left[N][1]] = prevMaxDiff1;
		
		for(i = 0; i <= N; i++) System.out.print(ans[i]+" ");
		System.out.println();
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