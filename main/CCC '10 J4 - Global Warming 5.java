import java.util.Scanner;
import java.util.Arrays;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(true) {
        	int N = input.nextInt();
        	if(N == 0) break;
        	int[] arr = new int[N];
        	int[] change = new int[N];
        	for(int i = 0; i < N; i++) {
        		int in = input.nextInt();
        		arr[i] = in;
        		if(i > 0) change[i] = in - arr[i-1];
        	}
        	int minCycle = 0;
        	cycleLength: for(int i = 1; i < N-1; i++) {
        		for(int j = i+1; j < N; j += i) {
        			if(j+i > N) {
        				for(int k = j; k < N; k++) {
        					if(change[k-j+1] != change[k]) continue cycleLength;
        				}
        			}
        			else if(!Arrays.equals(Arrays.copyOfRange(change,1,1+i),Arrays.copyOfRange(change,j,j+i))) continue cycleLength;
        		}
        		minCycle = i;
        		break;
        	}
        	if(minCycle == 0) minCycle = N-1;
        	System.out.println(minCycle);
        }
    }
}