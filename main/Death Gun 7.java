import java.util.*;
import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		int M = nextInt(),i,Ai,Bi; String A,B;
		String[] names = new String[901];
		HashMap<String,Integer> index = new HashMap<String,Integer>();
		ArrayList<Integer>[] adj = new ArrayList[901];
		for(i = 0; i < 901; i++) adj[i] = new ArrayList<Integer>();
		int[] outDeg = new int[901];
		int next = 0;
		for(i = 0; i < M; i++) {
			A = next(); B = next();
			Ai = 0; Bi = 0;
			if(!index.containsKey(A)) {
				names[next] = A;
				index.put(A, next);
				next++;
			}
			if(!index.containsKey(B)) {
				names[next] = B;
				index.put(B, next);
				next++;
			}
			Ai = index.get(A); Bi = index.get(B);
			adj[Bi].add(Ai);
			outDeg[Ai]++;
		}
		boolean[] visited = new boolean[next];
		boolean notCycle = true;
		while(notCycle) {
			notCycle = false;
			for(i = 0; i < next; i++) {
				if(outDeg[i] == 0 && !visited[i]) {
					visited[i] = true;
					notCycle = true;
					System.out.println(names[i]);
					for(int j: adj[i]) outDeg[j]--;
					break;
				}
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