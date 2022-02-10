import java.util.Scanner;
public class CCC_20_J4_Cyclic_Shifts {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String T = input.next();
		String S = input.next();
		boolean containsCyclicShift = false;
		for(int i = 0; i < S.length(); i++) {
			if(T.indexOf(S) != -1) {
				containsCyclicShift = true;
				break;
			}
			S = S.substring(1) + S.substring(0,1);
		}
		if(containsCyclicShift) {
			System.out.println("yes");
		} else System.out.println("no");
	}
}