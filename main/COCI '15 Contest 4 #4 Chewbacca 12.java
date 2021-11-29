import java.util.*;
import java.io.*;
public class Question2 {
	public static void main(String[] args) throws IOException {
		long N = nextLong();
		int K = nextInt(), Q = nextInt(),i;
		long[] sumPowers = new long[60];
		sumPowers[0] = 1;
		for(i = 1; i < 60; i++) {
			sumPowers[i] = sumPowers[i-1]*K;
			if(sumPowers[i] > N) break;
		}
		for(i = 0; i < Q; i++) {
			 long x = nextLong(), y = nextLong(), temp = x;
			 if(K == 1) {System.out.println(Math.abs(x-y)); continue;}
			 x = Math.min(temp, y); y = Math.max(temp, y);
			 int lvlX = 0, lvlY = 0;
			 int currDepth = 0;
			 while(x > sumPowers[currDepth]) {
				 x -= sumPowers[currDepth];
				 y -= sumPowers[currDepth];
				 lvlX++; lvlY++;
				 currDepth++;
			 }
			 while(y > sumPowers[currDepth]) {
				 y -= sumPowers[currDepth];
				 lvlY++;
				 currDepth++;
			 }
			 x--; y--;
			 int ans = 0;
			 while(lvlY > lvlX) {
				 y /= K;
				 lvlY--;
				 ans++;
			 }
			 while(x != y) {
				 x /= K;
				 y /= K;
				 ans += 2;
			 }
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