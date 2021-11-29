import java.io.*;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<Integer,HashSet<Integer>> graph = new HashMap<Integer,HashSet<Integer>>();
		int[][] connections = {
				{6},
				{6},
				{15,5,4,6},
				{3,5,6},
				{6,4,3},
				{2,1,7,5,4,3},
				{6,8},
				{7,9},
				{8,10,12},
				{9,11},
				{10,12},
				{9,11,13},
				{12,15,14},
				{13},
				{3,13},
				{18,17},
				{16,18},
				{16,17},
		};
		for(int i = 1; i <= 18; i++) {
			graph.put(i, new HashSet<Integer>());
			for(int j = 0; j < connections[i-1].length; j++) {
				graph.get(i).add(connections[i-1][j]);
			}
		}
		while(true) {
			String command = br.readLine();
			int x, y;
			switch(command) {
			case "q": return;
			case "i":
				x = Integer.parseInt(br.readLine()); y = Integer.parseInt(br.readLine());
				graph.putIfAbsent(x, new HashSet<Integer>());
				graph.putIfAbsent(y, new HashSet<Integer>());
				graph.get(x).add(y);
				graph.get(y).add(x);
				break;
			case "d":
				x = Integer.parseInt(br.readLine()); y = Integer.parseInt(br.readLine());
				graph.get(x).remove(y);
				graph.get(y).remove(x);
				break;
			case "n":
				System.out.println(graph.get(Integer.parseInt(br.readLine())).size());
				break;
			case "f":
				x = Integer.parseInt(br.readLine());
				LinkedList<Integer> queue = new LinkedList<Integer>();
				boolean[] isVisited = new boolean[50];
				int separation = 0;
				int ans = 0;
				queue.add(x);
				queue.add(-1);
				while(!queue.isEmpty()) {
					int curr = queue.poll();
					if(curr == -1) {
						if(separation != 1) queue.add(-1);
						separation++; continue;
					}
					if(isVisited[curr]) continue;
					if(separation == 2) ans++;
					else queue.addAll(graph.get(curr));
					isVisited[curr] = true;
				}
				System.out.println(ans);
				break;
			case "s":
				x = Integer.parseInt(br.readLine()); y = Integer.parseInt(br.readLine());
				queue = new LinkedList<Integer>();
				isVisited = new boolean[50];
				boolean isFound = false;
				separation = 0;
				queue.add(x);
				queue.add(-1);
				while(!queue.isEmpty()) {
					int curr = queue.poll();
					if(curr == -1) {
						if(!queue.isEmpty()) queue.add(-1);
						separation++; continue;
					}
					if(isVisited[curr]) continue;
					if(curr == y) {
						isFound = true; break;
					}
					queue.addAll(graph.get(curr));
					isVisited[curr] = true;
				}
				if(!isFound) System.out.println("Not connected");
				else System.out.println(separation);
			}
		}
	}
}