import java.util.*;
import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		int N = nextInt(), B = nextInt(), i;
		int[][] friends = new int[N][2];
		for(i = 0; i < N; i++) {
			friends[i][0] = nextInt();
			friends[i][1] = nextInt();
		}
		Arrays.sort(friends, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[0]+a[1], b[0]+b[1]);
			}
		});
		int spent = 0;
		for(i = 0; i < N; i++) {
			if(spent+friends[i][0]+friends[i][1] > B) {
				if(spent+friends[i][0]/2+friends[i][1] > B) break;
				i++; break;
			}
			spent += friends[i][0]+friends[i][1];
		}
		System.out.println(i);
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