import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int N = nextInt(),i;
		int[] arr1 = new int[N];
		int[] arr2 = new int[N];
		for(i = 0; i < N; i++) {
			arr1[i] = nextInt();
			arr2[i] = arr1[i];
		}
		Arrays.sort(arr1);
		boolean hasSwap = false;
		int swap1 = 0, swap2 = 0;
		for(i = 0; i < N; i++) {
			if(arr1[i] != arr2[i]) {
				if(hasSwap) {System.out.println("NO"); return;}
				if(swap1 == 0) {
					swap1 = arr1[i];
					swap2 = arr2[i];
				} else {
					if(swap1 != arr2[i] || swap2 != arr1[i]) {System.out.println("NO"); return;}
					hasSwap = true;
				}
			}
		}
		System.out.println("YES");
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