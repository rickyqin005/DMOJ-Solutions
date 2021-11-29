import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt();
		boolean[] gift = new boolean[N];
		for(int i = 0; i < N; i++) {
			int L = nextInt()-1;
			if(gift[L]) {System.out.println("NO"); return;}
			gift[L] = true;
		}
		System.out.println("YES");
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