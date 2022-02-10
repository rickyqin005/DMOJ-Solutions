import java.util.Scanner;
import java.util.Arrays;
public class Question {
	static String[] in;
	public static void recurse(String[] arr) {
		String operation = arr[0];
		int num1Loc = 1;
		int end = 2;
		if(arr[1].equals("-") || arr[1].equals("+")) {
			int layer = 2;
			while(layer > 0) {
				num1Loc++;
				if(arr[num1Loc].equals("-") || arr[num1Loc].equals("+")) layer++;
				else layer--;
			}
			recurse(Arrays.copyOfRange(arr,1,num1Loc+1));
		} else System.out.print(arr[1] + " ");
		int num2Loc = num1Loc+1;
		if(arr[num2Loc].equals("-") || arr[num2Loc].equals("+")) {
			int layer = 2;
			while(layer > 0) {
				end++;
				if(arr[end].equals("-") || arr[end].equals("+")) layer++;
				else layer--;
			}
			end++;
			recurse(Arrays.copyOfRange(arr,num2Loc,end));
		} else System.out.print(arr[num2Loc] + " ");
		System.out.print(arr[0]);
		if(in.length != arr.length) System.out.print(" ");
		
	}
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(true) {
        	in = input.nextLine().split(" ");
        	if(in.length == 1) {
        		if(in[0].equals("0")) break;
        		System.out.println(in[0]);
        	}
        	else {
        		recurse(in);
        		System.out.println();
        	}
        }
    }
}