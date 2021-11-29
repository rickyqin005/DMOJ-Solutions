import java.util.*;
import java.io.*;
public class Question4 {
	public static int sum(int L, int R, int[][] tree) {//arguments are indexed 1 to N, inclusive
		int ans = 0,i;
		for(i = 0; i < tree.length; i++) {
			if((R & 1) == 1) ans += tree[i][R-1];
			R >>= 1;
		}
		for(i = 0; i < tree.length; i++) {
			if((L & 1) == 1) ans -= tree[i][L-1];
			L >>= 1;
		}
		return ans;
	}
	public static void update(int P, int V, int[][] tree) {
		int i;
		tree[0][P] += V;
		P >>= 1;
		for(i = 1; i < tree.length && P < tree[i].length; i++) {
			tree[i][P] += V;
			P >>= 1;
		}
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i,j;
		int[][] mass = new int[N][2];
		for(i = 0; i < N; i++) {
			mass[i][0] = nextInt();
			mass[i][1] = i;
		}
		Arrays.sort(mass, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -Integer.compare(a[0], b[0]);
			}
		});
		int[][] tree = new int[(int)(Math.log(N)/Math.log(2))+1][];
		int len = N;
		for(i = 0; i < tree.length; i++) {
			tree[i] = new int[len];
			len >>= 1;
		}
		int Q = nextInt(),P,V;
		int[][] query = new int[Q][4];
		for(i = 0; i < Q; i++) {
			query[i][0] = nextInt()+1;
			query[i][1] = nextInt()+1;
			query[i][2] = nextInt();
			query[i][3] = i;
		}
		Arrays.sort(query, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -Integer.compare(a[2], b[2]);
			}
		});
		int currQ = 0;
		int[] ans = new int[Q];
		for(i = 0; i < N; i++) {
			for(; currQ < Q; currQ++) {
				if(query[currQ][2] > mass[i][0]) {
					ans[query[currQ][3]] = sum(query[currQ][0]-1,query[currQ][1],tree);
				} else break;
			}
			update(mass[i][1],mass[i][0],tree);
		}
		for(; currQ < Q; currQ++) {
			ans[query[currQ][3]] = sum(query[currQ][0]-1,query[currQ][1],tree);
		}
		for(int curr: ans) System.out.println(curr);
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