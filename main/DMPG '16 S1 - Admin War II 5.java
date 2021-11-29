import java.util.*;
import java.io.*;
public class Question5 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i;
		int[] card1 = new int[N];
		int[] card2 = new int[N];
		for(i = 0; i < N; i++) card1[i] = nextInt();
		for(i = 0; i < N; i++) card2[i] = nextInt();
		Arrays.sort(card1);
		Arrays.sort(card2);
		int max1 = 0, max2 = 0;
		int j = N-1;
		for(i = N-1; i >= 0 ; i--, j--) {
			for(;j >= 0; j--) {
				if(card1[i] > card2[j]) {
					max1++;
					break;
				}
			}
		}
		j = N-1;
		for(i = N-1; i >= 0 ; i--, j--) {
			for(;j >= 0; j--) {
				if(card2[i] > card1[j]) {
					max2++;
					break;
				}
			}
		}
		System.out.println(max1);
		System.out.println(max2);
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