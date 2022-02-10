import java.util.Scanner;
public class Question {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String essay = input.nextLine();
		int numUpper = 0;
		int numLower = 0;
		for(int i = 0; i < essay.length(); i++) {
			int chr = essay.charAt(i);
			if(chr == 32) continue;
			else if(chr <= 90) numUpper++;
			else numLower++;
		}
		if(numUpper > numLower) System.out.println(essay.toUpperCase());
		else if (numUpper < numLower) System.out.println(essay.toLowerCase());
		else System.out.println(essay);
	}
}