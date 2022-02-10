import java.io.*;
import java.util.*;
public class Question5 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int start = Integer.parseInt(br.readLine());
		int end = Integer.parseInt(br.readLine());
		int dimension = (int)Math.ceil(Math.sqrt(end-start+1));
		int[][] spiral = new int[dimension][dimension];
		int startPosC = dimension/2-(dimension%2 == 0 ? 1: 0);
		int startPosR = startPosC;
		spiral[startPosR][startPosC] = start;
		start++;
		
		outer: for(int i = 1; start <= end; i++) {
			int[][] direction = {{-1,0},{0,-1}};
			if(i%2 == 1) {
				direction[0][0] = 1; direction[1][1] = 1;
			}
			for(int j = 0; j < 2; j++) {
				for(int k = 0; k < i; k++) {
					startPosR += direction[j][0];
					startPosC += direction[j][1];
					spiral[startPosR][startPosC] = start;
					if(start == end) break outer;
					start++;
				}
			}
			
		}
		int firstCol = (spiral[0][0] == 0) ? 1 : 0;
		for(int i = 0; i < dimension; i++) {
			for(int j = firstCol; j < dimension; j++) {
				int num = spiral[i][j];
				if(num == 0) System.out.print("   ");
				else {
					if(num < 10) System.out.print(" ");
					System.out.print(spiral[i][j]+ " ");
				}
			}
			System.out.println();
		}
	}
}