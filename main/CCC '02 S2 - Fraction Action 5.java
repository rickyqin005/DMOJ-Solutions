import java.util.*;
import java.io.*;
public class Question2 {
	public static int gcd(int a, int b) {
		int temp = 0;
		while(b != 0) {
			temp = a;
			a = b;
			b = temp%b;
		}
		return a;
	}
	public static void main(String[] args) throws IOException {
		int numerator = nextInt(), denominator = nextInt();
		int gcd = gcd(Math.max(numerator, denominator),Math.min(numerator, denominator));
		numerator /= gcd;
		denominator /= gcd;
		if(numerator % denominator == 0) System.out.println(numerator);
		else if(numerator < denominator) System.out.println(numerator+"/"+denominator);
		else {
			System.out.println((numerator/denominator)+" "+(numerator%denominator)+"/"+denominator);
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