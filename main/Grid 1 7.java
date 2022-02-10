import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int H = nextInt(), W = nextInt(), i, j;
		char[][] grid = new char[H][W];
		int[][] numPath = new int[H][W];
		for(i = 0; i < H; i++) grid[i] = nextLine().toCharArray();
		for(i = 0; i < W; i++) {
			if(grid[0][i] == '#') break;
			numPath[0][i] = 1;
		}
		for(i = 0; i < H; i++) {
			if(grid[i][0] == '#') break;
			numPath[i][0] = 1;
		}
		for(i = 1; i < H; i++) {
			for(j = 1; j < W; j++) {
				if(grid[i][j] == '#') continue;
				numPath[i][j] = (numPath[i-1][j]+numPath[i][j-1])%1000000007;
			}
		}
		System.out.println(numPath[H-1][W-1]);
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