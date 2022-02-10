import java.util.Scanner;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        int K = input.nextInt();
        String ans = str.substring(0,K);
    	for(int i = 0; i < str.length()-K+1; i++) {
    		String subStr = str.substring(i,i+K);
    		if(subStr.compareTo(ans) < 0) ans = subStr;
    	}
        for(int i = 0; i < ans.length(); i++) {
        	System.out.print(ans.charAt(i));
        }
        System.out.println();
    }
}