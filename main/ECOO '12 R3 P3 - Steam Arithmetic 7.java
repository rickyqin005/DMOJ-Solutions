import java.util.Scanner;
import java.util.Arrays;
public class Question {
	public static int evaluate(String[] str) {
		int num1, num2;
		int num2loc = 5;
		if(str[3].equals("(")) {
			num1 = evaluate(Arrays.copyOfRange(str, 3, str.length));
			int layer = 1;
			int loc = 4;
			while(layer > 0) {
				if(str[loc].equals("(")) layer++;
				else if(str[loc].equals(")")) layer--;
				loc++;
			}
			num2loc = loc+1;
		} else num1 = Integer.parseInt(str[3]);
		if(str[num2loc].equals("(")) {
			num2 = evaluate(Arrays.copyOfRange(str, num2loc, str.length));
		} else num2 = Integer.parseInt(str[num2loc]);
		switch(str[1]) {
		case "+": return num1 + num2;
		case "-": return num1 - num2;
		case "*": return num1 * num2;
		case "q": return num1 / num2;
		default: return num1 % num2;
		}
	}
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        for(int i = 0; i < 10; i++) {
        	String[] str = input.nextLine().split("");
        	System.out.println(evaluate(str));
        }
    }
}