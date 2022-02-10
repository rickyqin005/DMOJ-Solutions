import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        HashMap<String,HashSet<String>> graph = new HashMap<String,HashSet<String>>();
        HashMap<String,Boolean> visited = new HashMap<String,Boolean>();
        graph.put("home", new HashSet<String>());
        visited.put("home", false);
        graph.put("Waterloo GO", new HashSet<String>());
        visited.put("Waterloo GO", false);
        String[] in = br.readLine().split(" ");
        int N = Integer.parseInt(in[0]), T = Integer.parseInt(in[1]);
        for(int i = 0; i < N; i++) {
        	String str = br.readLine();
        	graph.put(str, new HashSet<String>());
        	visited.put(str, false);
        	
        }
        for(int i = 0; i < T; i++) {
        	in = br.readLine().split("-");
        	graph.get(in[0]).add(in[1]);
        	graph.get(in[1]).add(in[0]);
        }
        int ans = 1;
        LinkedList<String> queue = new LinkedList<String>();
        queue.add("home"); queue.add("");
        visited.replace("home", true);
        while(!queue.isEmpty()) {
        	String curr = queue.poll();
        	if(curr.equals("")) {
        		if(!queue.isEmpty()) queue.add("");
        		ans++; continue;
        	}
        	for(String str: graph.get(curr)) {
        		if(visited.get(str)) continue;
        		if(str.equals("Waterloo GO")) {System.out.println(ans); return;}
        		queue.add(str);
        		visited.replace(str, true);
        	}
        }
        System.out.println("RIP ACE");
    }
}