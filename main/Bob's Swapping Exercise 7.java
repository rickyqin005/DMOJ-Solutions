import java.util.*;
import java.io.*;
public class Question5 {
	public static long gcd(long a, long b) {
		long temp = 0;
		while(b != 0) {
			temp = a%b;
			a = b;
			b = temp;
		}
		return a;
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(), M = nextInt(),i;
		int[] arr = new int[N];
		for(i = 0; i < N; i++) arr[i] = i;
		int l,r,temp;
		for(i = 0; i < M; i++) {
			l = nextInt()-1; r = nextInt()-1;
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
		long ans = 1;
		boolean[] visited = new boolean[N];
		int len, next;
		for(i = 0; i < N; i++) {
			if(visited[i]) continue;
			len = 1;
			next = arr[i];
			while(next != i) {
				visited[next] = true;
				len++;
				next = arr[next];
			}
			ans = (ans*len)/gcd(Math.max(ans, len), Math.min(ans, len));
		}
		System.out.println(ans);
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