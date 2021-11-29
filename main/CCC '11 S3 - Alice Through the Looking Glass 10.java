import java.util.Scanner;
import java.util.Arrays;
public class Question {
	static int[][] filled = {{1,0},{2,0},{3,0},{2,1}};
    static int[][] zoomIn = {{1,1},{2,2},{3,1}};
    
	public static boolean recurse (int x,int y,int m) {
		boolean hasCrystal = false;
		int[] coor = {x / (int)Math.pow(5, m-1),y / (int)Math.pow(5, m-1)};
		for(int i = 0; i < 3; i++) {
			if(Arrays.equals(coor, zoomIn[i])) {
				if(m != 1) {
					x %= Math.pow(5, m-1);
					y %= Math.pow(5, m-1);
					hasCrystal = recurse(x,y,m-1);
					break;
				}
			}
		}
		for(int i = 0; i < 4; i++) {
			if(Arrays.equals(coor, filled[i])) return true;
		}
		return hasCrystal;
	}
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int T = input.nextInt();
        for(int i = 0; i < T; i++) {
        	int m = input.nextInt();
        	int x = input.nextInt();
        	int y = input.nextInt();
        	if(recurse(x,y,m)) System.out.println("crystal");
        	else System.out.println("empty");
        }
    }
}