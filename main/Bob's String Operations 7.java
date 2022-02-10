import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
public class Question {
    public static void main(String[] args) throws IOException{
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	HashMap<Character,Character> map = new HashMap<Character,Character>();
        char[] str1 = br.readLine().toCharArray();
        char[] str2 = br.readLine().toCharArray();
        boolean isPossible = true;
        for(int i = 0; i < str1.length; i++) {
        	if(map.containsKey(str1[i])) {
        		if(map.get(str1[i]) != str2[i]) {
        			isPossible = false; break;
        		}
        	} else if(map.containsValue(str2[i])) {
        		isPossible = false; break;
        	}
        	map.putIfAbsent(str1[i],str2[i]);
        }
        if(isPossible) System.out.println("Yes");
        else System.out.println("No");
    }
}