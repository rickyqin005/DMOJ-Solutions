import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
public class Question3 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        HashSet<Integer> ans = new HashSet<Integer>();
        int[] arr = new int[N];
        int[] diff = new int[N-1];
        int minDiff = Integer.MAX_VALUE;
        
        for(int i = 0; i < N; i++) {
        	arr[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(arr);
        for(int i = 1; i < N; i++) {
        	diff[i-1] = arr[i] - arr[i-1];
        	minDiff = Math.min(minDiff,diff[i-1]);
        }
        if(minDiff >= 2) {
	        for(int i = 1; i <= Math.sqrt(minDiff); i++) {
	        	boolean bool = true;
	        	for(int j = 0; j < N-1; j++) {
	        		if(diff[j] % i != 0) {
	        			bool = false; break;
	        		}
	        	}
	        	if(bool) ans.add(i);
	        	
	        	bool = true;
	        	for(int j = 0; j < N-1; j++) {
	        		if(diff[j] % (minDiff/i) != 0) {
	        			bool = false; break;
	        		}
	        	}
	        	if(bool) ans.add(minDiff/i);
	        }
	        ans.remove(1);
	        if(ans.size() > 0) {
		        Integer[] ansArr = new Integer[ans.size()];
		        ans.toArray(ansArr);
		        for(int i = 0; i < ansArr.length-1; i++) {
		        	System.out.print(ansArr[i] + " ");
		        }
		        System.out.println(ansArr[ansArr.length-1]);
	        }
        }
    }
}