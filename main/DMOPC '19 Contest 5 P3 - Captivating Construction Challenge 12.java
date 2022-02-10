import java.util.*;
import java.io.*;
public class Question4 {
	public static int gcd(int a, int b) {
		int temp;
		while(b != 0) {
			temp = a;
			a = b;
			b = temp % b;
		}
		return a;
	}
	public static void main(String[] args) throws IOException {
		int H = nextInt(), V = nextInt(),i,j,x,y,dx,dy,gcd;
		long ans = 0;
		for(i = 1; i < H; i++) {
			for(j = 0; j < V; j++) {
				gcd = gcd(Math.max(i, j),Math.min(i, j));
				dx = i/gcd;
				dy = j/gcd;
				x = j+dx;
				y = i+dy;
				while(x < V && y < H) {
					ans += (H-y)*(V-x);
					x += dx;
					y += dy;
				}
			}
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