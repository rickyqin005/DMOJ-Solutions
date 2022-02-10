import java.util.Scanner;
public class Question {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int[] numColor = {0,0,0,0,0,0};
		//red,orange,yellow,green,blue,black
		for(int i = 0; i < N; i++) {
			switch(input.next()) {
			case "red": numColor[0]++;
				break;
			case "orange": numColor[1]++;
			break;
			case "yellow": numColor[2]++;
			break;
			case "green": numColor[3]++;
			break;
			case "blue": numColor[4]++;
			break;
			case "black": numColor[5]++;
			}
		}
		int maxColor = 0;
		for(int i = 0; i < 6; i++) {
			maxColor = Math.max(numColor[i], maxColor);
		}
		System.out.println(Math.min(maxColor, N-maxColor+1)+N-maxColor);
	}
}