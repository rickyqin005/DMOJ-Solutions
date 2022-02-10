import java.io.*;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.TreeMap;
public class Question3 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++) {
        	HashMap<String,TreeMap<Integer,Integer>> item = new HashMap<String,TreeMap<Integer,Integer>>();
        	int cost = 0;
        	int N = Integer.parseInt(br.readLine());
        	for(int j = 0; j < N; j++) {
        		int M = Integer.parseInt(br.readLine());
        		for(int k = 0; k < M; k++) {
        			String[] in = br.readLine().split(" ");
        			item.putIfAbsent(in[0],new TreeMap<Integer,Integer>());
        			item.get(in[0]).putIfAbsent(Integer.parseInt(in[1]),0);
        			item.get(in[0]).replace(Integer.parseInt(in[1]),item.get(in[0]).get(Integer.parseInt(in[1]))+Integer.parseInt(in[2]));
        		}
        	}
        	int K = Integer.parseInt(br.readLine());
        	for(int j = 0; j < K; j++) {
        		String[] in = br.readLine().split(" ");
        		int remaining = Integer.parseInt(in[1]);
        		for(Entry<Integer,Integer> k: item.get(in[0]).entrySet()) {
        			int quant = Math.min(remaining,k.getValue());
        			remaining -= quant;
        			cost += quant*k.getKey();
        			if(remaining == 0) break;
        		}
        	}
        	System.out.println(cost);
        }
    }
}