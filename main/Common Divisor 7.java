import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashSet<Long> factA = new HashSet<Long>();
		HashSet<Long> factGCD = new HashSet<Long>();
		String[] in = br.readLine().split(" ");
        long A = Long.parseLong(in[0]);
        long B = Long.parseLong(in[1]);
        int K = Integer.parseInt(in[2]);
        int sqrtA = (int)Math.sqrt(A);
        int sqrtB = (int)Math.sqrt(B);
        for(long i = 1; i <= sqrtA; i++) {
        	if(A % i == 0) {
        		factA.add(i);
        		factA.add(A/i);
        	}
        }
        for(long i = 1; i <= sqrtB; i++) {
        	if(B % i == 0) {
        		if(factA.contains(i)) factGCD.add(i);
        		if(factA.contains(B/i)) factGCD.add(B/i);
        	}
        }
        if(K > factGCD.size()) System.out.println(-1);
        else {
        	Long[] arr = new Long[factGCD.size()];
        	factGCD.toArray(arr);
        	Arrays.sort(arr);
        	System.out.println(arr[arr.length-K]);
        }
	}
}