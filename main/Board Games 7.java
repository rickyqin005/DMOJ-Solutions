import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
		int[] visited = new int[1000001];
		
		if(N == M) {System.out.println(0); return;}
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(N); visited[N] = 1;
		while(!queue.isEmpty()) {
			int curr = queue.poll();
			int nextDist = visited[curr]+1;
			if(3 * curr <= 1000000) {
				if(3 * curr == M) {System.out.println(nextDist-1); return;}
				if(visited[3*curr] == 0) {
					queue.add(3*curr); visited[3*curr] = nextDist;
				}
			}
			if(curr-1 > 0) {
				if(curr - 1 == M) {System.out.println(nextDist-1); return;}
				if(visited[curr-1] == 0) {
					queue.add(curr-1); visited[curr-1] = nextDist;
				}
			}
			if(curr-3 > 0) {
				if(curr - 3 == M) {System.out.println(nextDist-1); return;}
				if(visited[curr-3] == 0) {
					queue.add(curr-3); visited[curr-3] = nextDist;
				}
			}
			if(curr % 2 == 0) {
				if(curr / 2 == M) {System.out.println(nextDist-1); return;}
				if(visited[curr/2] == 0) {
					queue.add(curr/2); visited[curr/2] = nextDist;
				}
			}
		}
	}
}