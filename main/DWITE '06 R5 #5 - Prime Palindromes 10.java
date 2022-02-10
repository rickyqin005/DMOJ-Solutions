import java.io.*;
import java.util.*;
public class Question3 {
	static ArrayList<Integer> palindromes = new ArrayList<Integer>(120);
	static int len = 2, curr = 0;
	public static void findPalindromes(int lvl) {
		if(lvl == len/2) {
			int sqrt = (int)Math.sqrt(curr);
			if(curr % 2 == 0) return;
			for(int i = 3; i <= sqrt; i += 2) {
				if(curr % i == 0) return;
			}
			palindromes.add(curr);
		} else {
			int start = curr;
			for(int i = 0; i < 10; i++) {
				curr += i*pow10(len-lvl-1);
				if(len == 4 && lvl == 0) curr += i*10;
				findPalindromes(lvl+1); curr = start;
			}
		}
	}
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        palindromes.add(2); palindromes.add(3); palindromes.add(5);
        palindromes.add(7); palindromes.add(11);
        for(; len < 6; len += 2) {
        	curr += pow10(len)+1; findPalindromes(0); curr = 0;
        	curr += 3*pow10(len)+3; findPalindromes(0); curr = 0;
        	curr += 7*pow10(len)+7; findPalindromes(0); curr = 0;
        	curr += 9*pow10(len)+9; findPalindromes(0); curr = 0;
        }
        
        for(int i = 0; i < 5; i++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	int L = Integer.parseInt(st.nextToken()), U = Integer.parseInt(st.nextToken());
        	int ans = 0;
        	for(int j: palindromes) {
        		if(j > U) break;
        		if(j >= L) ans++;
        	}
        	System.out.println(ans);
        }
    }
    public static int pow10(int power) {
    	int ans = 1;
    	for(int j = 0; j < power; j++) ans *= 10;
    	return ans;
    }
}