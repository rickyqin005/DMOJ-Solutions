import java.util.Scanner;
import java.util.HashMap;
public class PhoneNumber {
	String name;
	int frequency;
	String number;
	public PhoneNumber(String n, String num) {
		name = n;
		frequency = 0;
		number = num;
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		HashMap<String,PhoneNumber> book = new HashMap<String,PhoneNumber>();
		int N = input.nextInt();
		for(int i = 0; i < N; i++) {
			String name = input.next();
			String number = input.next();
			book.put(number, new PhoneNumber(name,number));
		}
		int D = input.nextInt();
		for(int i = 0; i < D; i++) {
			book.get(input.next()).frequency++;
		}
		PhoneNumber mostFrequent = new PhoneNumber("","99999999");
		for(String i: book.keySet()) {
			if(book.get(i).frequency > mostFrequent.frequency) {
				mostFrequent = book.get(i);
			} else if(book.get(i).frequency == mostFrequent.frequency && Integer.parseInt(book.get(i).number) < Integer.parseInt(mostFrequent.number)) {
				mostFrequent = book.get(i);
			}
		}
		System.out.println(mostFrequent.name);
	}
}