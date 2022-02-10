import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int T = nextInt();
		for(int i = 0; i < T; i++) {
			long a1 = nextInt(), a2 = nextInt(), a3 = nextInt(), k = nextInt();
			if(a2-a1 == a3-a2) System.out.println((a1+(a2-a1)*(k-1))%1000000007);
			else {
				k--;
				Stack<Boolean> stack = new Stack<Boolean>();
				long ratio = a2/a1, multiplier = ratio;
				while(k != 1) {
					if(k % 2 == 1) {
						stack.add(false); k--;
					} else {
						stack.add(true); k/=2;
					}
				}
				while(!stack.isEmpty()) {
					if(stack.pop()) multiplier=multiplier*multiplier%1000000007;
					else multiplier=multiplier*ratio%1000000007;
				}
				System.out.println(a1*multiplier%1000000007);
			}
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