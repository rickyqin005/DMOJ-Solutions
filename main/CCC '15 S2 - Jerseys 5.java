import java.util.Scanner;
import java.util.HashMap;
public class CCC_15_S2_Jerseys {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int J = input.nextInt();
		int A = input.nextInt();
		HashMap<Integer,Integer> jersey = new HashMap<Integer,Integer>();
		int ans = 0;
		for(int i = 0; i < J; i++) {
			String in = input.next();
			int size;
			if(in.equals("S")) size = 1;
			else if(in.equals("M")) size = 2;
			else size = 3;
			jersey.put(i+1, size);
		}
		for(int i = 0; i < A; i++) {
			int size;
			switch(input.next()) {
			case "S": size = 1;
				break;
			case "M": size = 2;
				break;
			default: size = 3;
			}
			if(size == 2);
			int number = input.nextInt();
			if(jersey.containsKey(number)) {
				if(jersey.get(number) >= size) {
					ans++;
					jersey.remove(number);
				}
			}
		}
		System.out.println(ans);
	}
}