import java.util.*;
import java.io.*;
public class Question4 {
	static Integer[][] ansArr = new Integer[10][9];
	static ArrayList<Integer>[][] dependencies = new ArrayList[10][9];
	static boolean[][] visited;
	public static int dfs(int r, int c) {
		if(ansArr[r][c] != null) return ansArr[r][c];
		if(visited[r][c]) return -1;
		visited[r][c] = true;
		int totalSum = 0;
		for(int i: dependencies[r][c]) {
			int currSum = dfs(i/9,i%9);
			if(currSum == -1) return -1;
			totalSum += currSum;
		}
		ansArr[r][c] = totalSum;
		return totalSum;
	}
	public static void main(String[] args) throws IOException {
		int i,j,k; String[] sum;
		for(i = 0; i < 10; i++) {
			for(j = 0; j < 9; j++) {
				sum = next().split("\\+");
				if(sum[0].charAt(0) < 65) ansArr[i][j] = Integer.parseInt(sum[0]);
				else {
					dependencies[i][j] = new ArrayList<Integer>();
					for(k = 0; k < sum.length; k++) {
						dependencies[i][j].add((sum[k].charAt(0)-65)*9+sum[k].charAt(1)-48-1);
					}
				}
			}
		}
		for(i = 0; i < 10; i++) {
			for(j = 0; j < 9; j++) {
				if(ansArr[i][j] == null) {
					visited = new boolean[10][9];
					int currAns = dfs(i,j);
					if(currAns == -1) System.out.print("* ");
					else System.out.print(currAns+" ");
				}
				else System.out.print(ansArr[i][j]+" ");
			}
			System.out.println();
		}
		System.out.print("");
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