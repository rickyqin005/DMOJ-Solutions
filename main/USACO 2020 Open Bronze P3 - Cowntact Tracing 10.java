import java.io.*;
import java.util.*;
public class Question4 {
	public static boolean isPossible(int patient, int K, int[][] entry, boolean[] finalInfected) {
		boolean[] infected = new boolean[finalInfected.length]; int i,x,y;
		int[] numShake = new int[finalInfected.length];
		infected[patient] = true;
		for(i = 0; i < entry.length; i++) {
			x = entry[i][1]; y = entry[i][2];
			if(infected[x]) numShake[x]++;
			if(infected[y]) numShake[y]++;
			if(numShake[x] <= K && infected[x]) infected[y] = true;
			if(numShake[y] <= K && infected[y]) infected[x] = true;
		}
		for(i = 0; i < finalInfected.length; i++) {
			if(infected[i] != finalInfected[i]) return false;
		}
		return true;
	}
	public static void main(String[] args) throws IOException {
		int N = nextInt(), T = nextInt(),i,j;
		boolean[] finalInfected = new boolean[N]; String str = nextLine();
		for(i = 0; i < N; i++) finalInfected[i] = str.charAt(i) == '1';
		int[][] entry = new int[T][3];
		for(i = 0; i < T; i++) {
			entry[i][0] = nextInt();
			entry[i][1] = nextInt()-1;
			entry[i][2] = nextInt()-1;
		}
		Arrays.sort(entry, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[0], b[0]);
			}
		});
		int minK = 1000000, maxK = 0;
		int numPatientZero = 0;
		for(i = 0; i < N; i++) {
			boolean flag = false;
			for(j = 0; j <= 251; j++) {
				if(isPossible(i,j,entry,finalInfected)) {
					minK = Math.min(minK, j);
					maxK = Math.max(maxK, j);
					flag = true;
				}
			}
			if(flag) numPatientZero++;
		}
		System.out.println(numPatientZero+" "+minK+" "+(maxK == 251?"Infinity":maxK));
	}
	static int nextInt() throws IOException {return Integer.parseInt(next());}
	static String nextLine() throws IOException {return br.readLine().trim();}
	static String next() throws IOException {
		while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
}