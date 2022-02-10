import java.util.Scanner;
public class Question4 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int X = input.nextInt(), Y = input.nextInt(), Z = input.nextInt();
		for(int i = X; i <= X*Y; i += X) {
			if(i % Y == Z) {System.out.println("YES"); System.exit(0);}
		}
		System.out.println("NO");
	}
}