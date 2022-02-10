import java.util.Scanner;
public class Question {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String[] vowels = {"a","e","i","o","u","y"};
        while(true) {
        	String str = input.next();
        	if(str.equals("quit!")) break;
        	if(str.length() <= 4) {
        		System.out.println(str); continue;
        	}
        	boolean isAmerican = false;
        	String ltr = str.substring(str.length()-3,str.length()-2);
        	if(str.substring(str.length()-2, str.length()).equals("or")) {
        		boolean isConsonant = true;
        		for(int i = 0; i < 6; i++) {
        			if(ltr.equals(vowels[i])) {
        				isConsonant = false; break;
        			}
        		}
        		if(isConsonant) isAmerican = true;
        	}
        	if(isAmerican) System.out.println(str.substring(0,str.length()-2) + "our");
        	else System.out.println(str);
        }
    }
}