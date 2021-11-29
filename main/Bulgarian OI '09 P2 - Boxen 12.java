import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0; i < 2; i++) {
			int N = Integer.parseInt(br.readLine());
			LinkedList<Integer>[] arr = new LinkedList[N];
			for(int j = 0; j < N; j++) {
				arr[j] = new LinkedList<Integer>();
			}
			
			for(int j = 0; j < N; j++) {
				int key = Integer.parseInt(br.readLine())-1;
				arr[key].add(j);
				arr[j].add(key);
			}
			int ans = 0;
			boolean[] visited = new boolean[N];
			for(int j = 0; j < N; j++) {
				if(visited[j]) continue;
				if(arr[j].isEmpty()) continue;
				ans++;
				Queue<Integer> queue = new LinkedList<Integer>();
				queue.add(j); visited[j] = true;
				while(!queue.isEmpty()) {
					int curr = queue.poll();
					for(int k: arr[curr]) {
						if(!visited[k]) {
							queue.add(k);
							visited[k] = true;
						}
					}
				}
			}
			System.out.print(ans);
			if(i == 0) System.out.print(" ");
		}
		System.out.println();
	}
}