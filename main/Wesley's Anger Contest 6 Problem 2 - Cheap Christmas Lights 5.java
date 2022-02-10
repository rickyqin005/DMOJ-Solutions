import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(), i,b;
		boolean[] light = new boolean[N];
		int numOn = 0;
		for(i = 0; i < N; i++) {
			light[i] = next().equals("1");
			if(light[i]) numOn++;
		}
		if(numOn == 0) {System.out.println(0); return;}
		for(i = 1; i <= M; i++) {
			b = nextInt()-1;
			light[b] = !light[b];
			if(light[b]) numOn++;
			else numOn--;
			if(numOn == 0) {System.out.println(i); return;}
			if(i >= numOn) {System.out.println(i); return;}
		}
		System.out.println(numOn);
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