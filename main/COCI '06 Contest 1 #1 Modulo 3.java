import java.util.Scanner;
import java.util.HashMap;
public class Question {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		for(int i = 0; i < 10; i++) {
			map.putIfAbsent(input.nextInt() % 42,0);
		}
		System.out.println(map.size());
	}
}