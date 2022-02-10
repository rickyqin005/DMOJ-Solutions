import java.util.*;
import java.io.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		int R = nextInt(), C = nextInt(),i,j,k,min; String str;
		boolean[][] grid = new boolean[R][C];
		for(i = 0; i < R; i++) {
			str = nextLine();
			for(j = 0; j < C; j++) grid[i][j] = str.charAt(j) == '.';
		}
		int[][] prevX = new int[R][C];
		for(i = 0; i < C; i++) {
			if(grid[R-1][i]) prevX[R-1][i] = R;
			else prevX[R-1][i] = R-1;
			for(j = R-2; j >= 0; j--) {
				if(grid[j][i]) prevX[j][i] = prevX[j+1][i];
				else prevX[j][i] = j;
			}
		}
		int ans = 0;
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				if(!grid[i][j]) continue;
				min = Integer.MAX_VALUE;
				for(k = j; k < C; k++) {
					if(!grid[i][k]) break;
					min = Math.min(min, prevX[i][k]);
					ans = Math.max(ans, (k-j+1)+(min-i));
				}
			}
		}
		ans *= 2;
		ans--;
		if(ans == -1) ans = 0;
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