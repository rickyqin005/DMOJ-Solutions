import java.util.Scanner;
public class Q5 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		for(int i = 0; i < N; i++) {
			String str = input.next();
			for(int j = 0; j < str.length(); j++) {
				int block = 0;
				for(int k = j; k < str.length(); k++) {
					if(str.substring(j, j+1).equals(str.substring(k, k+1))) block++;
					else break;
				}
				System.out.print(block + " " + str.substring(j, j+1));
				if(j + block < str.length()) System.out.print(" ");
				j += block-1;
			}
			System.out.println();
		}
	}
}