import java.util.*;
import java.io.*;
public class Question {
	static ArrayList<Integer>[] branches, weight;
	static int[] numCherries;
	static int ans = 0, N, C, K;
	public static int[] dfs(int curr) {
		if(branches[curr].size() == 0) return new int[] {0,numCherries[curr]};
		int[] currBranch = new int[2];
		int count = 0;
		for(int num: branches[curr]) {
			int[] subBranch = dfs(num);
			subBranch[0] += weight[curr].get(count);
			if(subBranch[0] <= K && subBranch[1] >= C) ans++;
			currBranch[0] += subBranch[0];
			currBranch[1] += subBranch[1];
			count++;
		}
		currBranch[1] += numCherries[curr];
		return currBranch;
	}
	public static void main(String[] args) throws IOException {
		N = nextInt(); C = nextInt(); K = nextInt(); int i,j,a,b,k;
		numCherries = new int[N];
		for(i = 0; i < N; i++) numCherries[i] = nextInt();
		branches = new ArrayList[N];
		weight = new ArrayList[N];
		for(i = 0; i < N; i++) {
			branches[i] = new ArrayList<Integer>();
			weight[i] = new ArrayList<Integer>();
		}
		for(i = 0; i < N-1; i++) {
			a = nextInt()-1; b = nextInt()-1; k = nextInt();
			branches[a].add(b); weight[a].add(k);
		}
		dfs(0);
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