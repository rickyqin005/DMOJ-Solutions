import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i,j;
		char[] arr = nextLine().toCharArray();
		int[] level = new int[N];
		int curr = 0;
		int min = 100000;
		int max = -100000;
		for(i = 0; i < N; i++) {
			if(arr[i] == 'v') curr--;
			level[i] = curr;
			min = Math.min(min, curr);
			max = Math.max(max, curr);
			
			if(arr[i] == '^') curr++;
		}
		for(i = max; i >= min; i--) {
			for(j = 0; j < N; j++) {
				if(level[j] == i) {
					if(arr[j] == 'v') System.out.print('\\');
					else if(arr[j] == '>') System.out.print('_');
					else System.out.print('/');
				} else System.out.print('.');
			}
			System.out.println();
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