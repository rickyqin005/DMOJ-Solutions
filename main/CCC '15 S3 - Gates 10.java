import java.io.*;
import java.util.TreeSet;
public class Question3 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        TreeSet<Integer>gate = new TreeSet<Integer>();
        int G = Integer.parseInt(br.readLine());
        int P = Integer.parseInt(br.readLine());
        int ans = 0;
        for(int i = 1; i <= G; i++) {
        	gate.add(i);
        }
        for(int i = 0; i < Math.min(G,P); i++) {
        	int plane = Integer.parseInt(br.readLine());
        	if(gate.floor(plane) == null) break;
        	gate.remove(gate.floor(plane));
        	ans++;
        }
        System.out.println(ans);
    }
}