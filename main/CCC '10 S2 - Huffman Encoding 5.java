import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        HashMap<String,Character> code = new HashMap<String,Character>();
        for(int i = 0; i < k; i++) {
        	String[] in = br.readLine().split(" ");
        	code.put(in[1],in[0].charAt(0));
        }
        String decode = br.readLine();
        outer:for(int i = 0; i < decode.length(); i++) {
        	for(int j = i+1; j <= decode.length(); j++) {
        		if(code.containsKey(decode.substring(i,j))) {
        			System.out.print(code.get(decode.substring(i,j)));
        			i += j-i-1;
        			continue outer;
        		}
        	}
        }
        System.out.println();
    }
}