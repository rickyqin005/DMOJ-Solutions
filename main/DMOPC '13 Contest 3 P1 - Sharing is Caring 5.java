import java.util.Scanner;
import java.util.ArrayList;
public class Question {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int M = input.nextInt();
		int[] share = new int[M];
		String[] document = new String[M];
		ArrayList<String> shareWithMe = new ArrayList<String>();
		for(int i = 0; i < M; i++) {
			input.nextInt();
			share[i] = input.nextInt();
			input.nextLine();
			document[i] = input.nextLine();
		}
		int Y = input.nextInt();
		for(int i = 0; i < M; i++) {
			if(share[i] == Y) shareWithMe.add(document[i]);
		}
		for(int i = 0; i < shareWithMe.size(); i++) {
			System.out.println(shareWithMe.get(i));
		}
	}
}