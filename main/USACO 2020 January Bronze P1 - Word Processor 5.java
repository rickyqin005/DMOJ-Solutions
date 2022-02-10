import java.io.*;
public class Question3 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        int N = Integer.parseInt(in[0]), K = Integer.parseInt(in[1]);
        String[] essay = br.readLine().split(" ");
        int length = 0;
        System.out.print(essay[0]);
        length += essay[0].length();
        for(int i = 1; i < N; i++) {
        	int len = essay[i].length();
    		if(len + length > K) {
    			System.out.print("\n" + essay[i]);
    			length = len;
    		} else {
    			System.out.print(" " + essay[i]);
    			length += len;
    		}
        }
        System.out.println();
    }
}