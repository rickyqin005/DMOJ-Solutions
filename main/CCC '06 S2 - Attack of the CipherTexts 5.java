import java.util.Scanner;
import java.util.HashMap;
public class Question {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		HashMap<Character,Character> map = new HashMap<Character,Character>();
		char[] plain = input.nextLine().toCharArray();
		char[] cipher1 = input.nextLine().toCharArray();
		char[] cipher2 = input.nextLine().toCharArray();
		for(int i = 0; i < plain.length; i++) {
			map.putIfAbsent(cipher1[i], plain[i]);
		}
		for(int i = 0; i < cipher2.length; i++) {
			if(map.containsKey(cipher2[i])) System.out.print(map.get(cipher2[i]));
			else System.out.print(".");
		}
		System.out.println();
	}
}