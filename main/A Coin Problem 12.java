import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), V = nextInt(),i,j,L,val;
		int[] coins = new int[N];
		for(i = 0; i < N; i++) coins[i] = nextInt();
		int[][] stores = new int[V][3];
		for(i = 0; i < V; i++) {
			stores[i][0] = nextInt();
			stores[i][1] = nextInt();
			stores[i][2] = i;
		}
		int[] ans = new int[V];
		Arrays.sort(stores, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[1], b[1]);
			}
		});
		int pos = 0;
		int curr = 0;
		int[] dp = new int[10001];
		while(pos < V) {
			L = stores[pos][1];
			for(;curr < L; curr++) {
				val = coins[curr];
				if(dp[val] == 0) dp[val]++;
				else dp[val] = Math.min(dp[val], 1);
				for(i = 1; i < 10001-val; i++) {
					if(dp[i] != 0) {
						if(dp[i+val] == 0) dp[i+val] = dp[i]+1;
						else dp[i+val] = Math.min(dp[i+val], dp[i]+1);
					}
				}
			}
			while(stores[pos][1] == L) {
				if(dp[stores[pos][0]] == 0) ans[stores[pos][2]] = -1;
				else ans[stores[pos][2]] = dp[stores[pos][0]];
				pos++;
				if(pos == V) break;
			}
		}
		for(i = 0; i < V; i++) System.out.println(ans[i]);
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
