import java.util.Scanner;
public class Q1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int t = input.nextInt();
		int s = input.nextInt();
		int h = input.nextInt();
		for(int i = 0; i < t; i++) {
			for(int j = 0; j < 3; j++) {
				System.out.print("*");
				if(j < 3-1) {
					for(int k = 0; k < s; k++) {
						System.out.print(" ");
					}
				}
			}
			System.out.println();
		}
		for(int i = 0; i < 3 + s*2; i++) {
			System.out.print("*");
		}
		System.out.println();
		
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < (3 + s*2)/2; j++) {
				System.out.print(" ");
			}
			
			System.out.println("*");
		}
	}
}