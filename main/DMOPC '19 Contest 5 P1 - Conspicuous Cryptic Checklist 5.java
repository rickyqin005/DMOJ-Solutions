import java.io.*;
import java.util.HashSet;
public class Question {
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	HashSet<String> item = new HashSet<String>();
    	String[] in = br.readLine().split(" ");
        int N = Integer.parseInt(in[0]);
        int M = Integer.parseInt(in[1]);
        int ans = 0;
        for(int i = 0; i < N; i++) {
        	item.add(br.readLine());
        }
        outer: for(int i = 0; i < M; i++) {
        	int T = Integer.parseInt(br.readLine());
        	for(int j = 0; j < T; j++) {
        		if(!item.contains(br.readLine())) {
        			for(int k = j+1; k < T; k++) {
        				br.readLine();
        			}
        			continue outer;
        		}
        	}
        	ans++;
        }
        System.out.println(ans);
    }
}