import java.util.*;
import java.io.*;
public class Question2 {
	static int ans = 0;
	static int[] card = new int[4];
	public static void permute(int pos) {
		if(pos == 4) {
			//System.out.println(Arrays.toString(card));
			recurse(card[0],card[1],1);
		} else {
			int temp = card[pos];
			for(int i = pos; i < 4; i++) {
				card[pos] = card[i];
				card[i] = temp;
				permute(pos+1);
				card[i] = card[pos];
				card[pos] = temp;
			}
		}
	}
	public static void recurse(int curr, int next, int pos) {
		if(pos == 3) {
			if(curr+next <= 24) ans = Math.max(ans, curr+next);
			if(curr-next <= 24) ans = Math.max(ans, curr-next);
			if(curr*next <= 24) ans = Math.max(ans, curr*next);
			if(next != 0) {
				if(curr % next == 0 && curr/next <= 24) ans = Math.max(ans, curr/next);
			}
		} else {
			recurse(curr+next,card[pos+1],pos+1);
			recurse(curr-next,card[pos+1],pos+1);
			recurse(curr*next,card[pos+1],pos+1);
			if(next != 0) {
				if(curr % next == 0) recurse(curr/next,card[pos+1],pos+1);
			}
			recurse(curr,next+card[pos+1],pos+1);
			recurse(curr,next-card[pos+1],pos+1);
			recurse(curr,next*card[pos+1],pos+1);
			if(card[pos+1] != 0) {
				if(next % card[pos+1] == 0) recurse(curr,next/card[pos+1],pos+1);
			}
		}
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i,j;
		for(i = 0; i < N; i++) {
			ans = 0;
			for(j = 0; j < 4; j++) card[j] = nextInt();
			permute(0);
			System.out.println(ans);
		}
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