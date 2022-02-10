import java.util.Scanner;
import java.util.LinkedList;
public class CCC_08_J2_Do_the_Shuffle {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		LinkedList<String> list = new LinkedList<String>();
		list.add("A"); list.add("B"); list.add("C"); list.add("D"); list.add("E");
		button: while(true) {
			int b = input.nextInt();
			int n = input.nextInt();
			for(int i = 0; i < n; i++) {
				switch(b) {
				case 4: break button;
				case 1: 
					list.addLast(list.removeFirst());
					break;
				case 2:
					list.addFirst(list.removeLast());
					break;
				case 3:
					String temp = list.removeFirst();
					list.add(1, temp);
				}
			}
		}
		for(int i = 0; i < 5; i++) {
			System.out.print(list.get(i));
			if(i == 4) System.out.println();
			else System.out.print(" ");
		}
	}
}