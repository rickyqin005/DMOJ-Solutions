import java.util.Scanner;
public class Question {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int totalEdge = 0;
		int[][] matrix = new int[4][4];
		for(int i = 0; i < 4; i++) {
			int currEdge = 0;
			for(int j = 0; j < 4; j++) {
				int num = in.nextInt();
				if(num == 1) {
					if(i == j) {System.out.println("No"); System.exit(0);}
					totalEdge++;
					currEdge++;
				}
				matrix[i][j] = num;
			}
			if(currEdge == 0) {System.out.println("No"); System.exit(0);}
		}
		for(int i = 0; i < 3; i++) {
			for(int j = i+1; j < 4; j++) {
				if(matrix[i][j] != matrix[j][i]) {System.out.println("No"); System.exit(0);}
			}
		}
		if(totalEdge != 6) System.out.println("No");
		else System.out.println("Yes");
	}
}