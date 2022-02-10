import java.util.Scanner;
public class CCC_18_J4_S2_Sunflowers {
	public static int[][] deepCopy(int[][] grid) {
		int N = grid.length;
		int[][] gridCopy = new int[N][N];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				gridCopy[i][j] = grid[i][j];
			}
		}
		return gridCopy;
	}
	public static int[][] rotate(int[][] grid) {
		int N = grid.length;
		int[][] gridTemp = deepCopy(grid);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				grid[i][j] = gridTemp[j][N-1-i];
			}
		}
		return grid;
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int grid[][] = new int[N][N];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				grid[i][j] = input.nextInt();
			}
		}
		outer:for(int i = 0; i < 4; i++) {
			for(int j = 0; j < N; j++) {
				for(int k = 1; k < N; k++) {
					if (grid[j][k] <= grid[j][k-1]) {
						grid = rotate(grid);
						continue outer;
					}
				}
			}
			for(int j = 0; j < N; j++) {
				for(int k = 1; k < N; k++) {
					if (grid[k][j] <= grid[k-1][j]) {
						grid = rotate(grid);
						continue outer;
					}
				}
			}
			break outer;
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				System.out.print(grid[i][j]);
				if(j < N-1) System.out.print(" ");
			}
			System.out.println();
		}
	}
}