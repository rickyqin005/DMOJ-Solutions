import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), K = nextInt(),i,j,full,amt;
		Integer[] berries = new Integer[N];
		int max = 0;
		for(i = 0; i < N; i++) {
			berries[i] = nextInt();
			max = Math.max(max, berries[i]);
		}
		int ans = 0;
		for(i = 1; i <= max; i++) {
			full = 0;
			for(j = 0; j < N; j++) {
				full += berries[j]/i;
				if(full >= K) break;
			}
			if(full < K/2) break;
			if(full >= K) ans = Math.max(ans, i*(K/2));
			else {
				final int I = i;
				Arrays.sort(berries,new Comparator<Integer>() {
					public int compare(Integer a, Integer b) {
						return Integer.compare(a%I,b%I)*-1;
					}
				});
				amt = i*(full-K/2);
				for(j = 0; j+full < K && j < N; j++) {
					amt += berries[j]%i;
				}
				ans = Math.max(ans, amt);
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