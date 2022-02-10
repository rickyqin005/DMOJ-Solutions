import java.io.*;
import java.util.StringTokenizer;
public class Question4 {
	public static int[][] buildTree(int[] arr) {
		int[][] tree = new int[(int)(Math.log(arr.length)/Math.log(2))+1][];
		tree[0] = arr;
		int len = arr.length >> 1,i,j;
		for(i = 1; i < tree.length; i++) {
			tree[i] = new int[len];
			for(j = 0; j < len; j++) tree[i][j] = Math.max(tree[i-1][2*j],tree[i-1][2*j+1]);
			len >>= 1;
		}
		return tree;
	}
	public static void update(int P, int V, int[][] tree) {
		tree[0][P] = V;
		P >>= 1;
		for(int i = 1; i < tree.length && P < tree[i].length; i++) {
			tree[i][P] = Math.max(tree[i-1][2*P],tree[i-1][2*P+1]);
			P >>= 1;
		}
	}
	public static int findWinner(int[][] tree) {
		int pos = 0, val = tree[tree.length-1][0];
		for(int i = tree.length-2; i >= 0; i--) {
			pos <<= 1;
			if(tree[i][pos+1] == val) pos++;
		}
		return pos+1;
	}
	public static int findWins(int P, int[][] tree) {
		int ans = 0;
		int V = tree[0][P];
		P >>= 1;
		for(int i = 1; i < tree.length; i++) {
			if(tree[i][P] == V) ans++;
			else break;
			P >>= 1;
		}
		return ans;
	}
	public static void main(String[] args) throws IOException {
		int N = 1 << nextInt(), M = nextInt(),i,j;
		int[] skill = new int[N];
		for(i = 0; i < N; i++) skill[i] = nextInt();
		int[][] tree = buildTree(skill);
		for(i = 0; i < M; i++) {
			String type = next();
			if(type.equals("R")) {
				update(nextInt()-1,nextInt(),tree);
			} else if(type.equals("W")) {
				System.out.println(findWinner(tree));
			} else {
				System.out.println(findWins(nextInt()-1,tree));
			}
		}
	}
	static int nextInt() throws IOException {return Integer.parseInt(next());}
	static String nextLine() throws IOException {return br.readLine().trim();}
	static String next() throws IOException {
		while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}