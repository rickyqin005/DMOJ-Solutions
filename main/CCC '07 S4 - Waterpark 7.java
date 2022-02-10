import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		if(N == 1) {System.out.println(1); return;}
		ArrayList<Integer>[] connections = new ArrayList[N];
		for(int i = 0; i < N; i++) {
			connections[i] = new ArrayList<Integer>();
		}
		
		while(true) {
			String[] in = br.readLine().split(" ");
			int x = Integer.parseInt(in[0]), y = Integer.parseInt(in[1]);
			if(x == 0 && y == 0) break;
			connections[x-1].add(y-1);
		}
		
		int[] numPaths = new int[N];
		numPaths[0] = 1;
		for(int i = 0; i < N; i++) {
			for(int j: connections[i]) {
				numPaths[j] += numPaths[i];
			}
		}
		System.out.println(numPaths[N-1]);
	}
}