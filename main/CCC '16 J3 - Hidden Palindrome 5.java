import java.io.*;
public class Question {
	public static boolean isPalindrome(String str) {
		for(int i = 0; i < str.length()/2; i++) {
			if(str.charAt(i) != str.charAt(str.length()-i-1)) return false;
		}
		return true;
	}
    public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	String str = br.readLine();
    	int ans = str.length();
    	outer: for(int i = str.length(); i >= 1; i--) {
    		for(int j = 0; j < str.length()-i+1; j++) {
    			if(isPalindrome(str.substring(j,j+i))) {
    				ans = i; break outer;
    			}
    		}
    	}
    	System.out.println(ans);
    }
}