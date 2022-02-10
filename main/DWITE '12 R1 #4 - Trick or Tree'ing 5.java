import java.util.*;
import java.io.*;
public class Question5 {
	static StringTokenizer st2;
	static int dist = 0, maxDepth = 0, candy = 0;
	static String next;
	public static void traverseTree(int depth) {
		String next = st2.nextToken();
		if(next.equals("(")) traverseTree(depth+1);
		else candy += Integer.parseInt(next);
		dist += 2;
		next = st2.nextToken();
		if(next.equals("(")) traverseTree(depth+1);
		else candy += Integer.parseInt(next);
		dist += 2;
		st2.nextToken();
		maxDepth = Math.max(maxDepth, depth);
	}
	public static void main(String[] args) throws IOException {
		for(int i = 0; i < 5; i++) {
			dist = 0; maxDepth = 0; candy = 0;
			st2 = new StringTokenizer(nextLine().replace("(", " ( ").replace(")", " ) "));
			next = st2.nextToken();
			if(!next.equals("(")) System.out.println(0 + " " + Integer.parseInt(next));
			else {
				traverseTree(1);
				System.out.println((dist-maxDepth) + " " + candy);
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