import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int L = Integer.parseInt(br.readLine());
		for(int i = 0; i < L; i++) {
			HashMap<String,ArrayList<String>> tree = new HashMap<String,ArrayList<String>>();
			int n = Integer.parseInt(br.readLine());
			String[] message = new String[n];
			for(int j = 0; j < n; j++) {
				message[j] = br.readLine();
			}
			Stack<String> stack = new Stack<String>();
			stack.add(message[n-1]);
			for(int j = 0; j < n; j++) {
				String name = message[j];
				if(name.equals(stack.get(Math.max(stack.size()-2,0)))) stack.pop();
				else {
					tree.putIfAbsent(stack.peek(), new ArrayList<String>());
					tree.get(stack.peek()).add(name);
					stack.add(name);
				}
			}
			Queue<String> queue = new LinkedList<String>();
			queue.add(message[n-1]); queue.add("");
			int ans = -1;
			String curr;
			while(!queue.isEmpty()) {
				curr = queue.poll();
				if(curr.equals("")) {
					if(!queue.isEmpty()) queue.add("");
					ans++; continue;
				}
				if(tree.containsKey(curr)) queue.addAll(tree.get(curr));
			}
			System.out.println(n*10-ans*20);
		}
	}
}