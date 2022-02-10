import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		long P = nextInt(), Y = nextInt(), T = nextLong();
		if(P == 0) {System.out.println((long)Math.ceil(T/Y)); return;}
		long low = 1, high = T/Y, mid = 0,sum = 0;
		int count = 0;
		while(low < high) {
			mid = (low+high)/2;
			count = 0;
			sum = 0;
			while(sum < T && count < Y) {
				sum += mid;
				sum += sum*P/100;
				count++;
			}
			if(count == Y && sum < T) low = mid+1;
			else high = mid;
		}
		System.out.println(low);
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