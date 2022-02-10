import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(), K = nextInt(),i;
		int[] cow = new int[N];
		int[][] moves = new int[M][2];
		for(i = 0; i < M; i++) {
			moves[i][0] = nextInt()-1;
			moves[i][1] = nextInt()-1;
		}
		for(i = 0; i < N; i++) cow[i] = i;
		int l,r,temp;
		for(i = 0; i < M; i++) {
			l = moves[i][0];
			r = moves[i][1];
			while(l < r) {
				temp = cow[l];
				cow[l] = cow[r];
				cow[r] = temp;
				l++; r--;
			}
		}
		//System.out.println(Arrays.toString(cow));
		int[] ans = new int[N];
		ArrayList<Integer> cycle;
		boolean[] visited = new boolean[N];
		int next,count;
		for(i = 0; i < N; i++) {
			if(visited[i]) continue;
			cycle = new ArrayList<Integer>();
			cycle.add(i);
			visited[i] = true;
			next = cow[i];
			while(next != i) {
				cycle.add(next);
				visited[next] = true;
				next = cow[next];
			}
			count = 0;
			for(int j: cycle) {
				ans[j] = cycle.get((count+K)%cycle.size());
				count++;
			}
		}
		for(i = 0; i < N; i++) System.out.println(ans[i]+1);
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