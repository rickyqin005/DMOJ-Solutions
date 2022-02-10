import java.util.Scanner;
import java.util.ArrayList;
public class Question {
	public static int numChances = 0;
	public static boolean contains(ArrayList<String> list, String str) {
		for(int i = 0; i < list.size(); i++) {
			if(list.get(i).equals(str)) return true;
		}
		return false;
	}
	public static void recurse(int[] point,ArrayList<String> gameLeft, int favourite) {
		if(gameLeft.size() == 0) {
			boolean isMax = true;
			for(int i = 0; i < 4; i++) {
				if(i == favourite-1) continue;
				if(point[i] >= point[favourite-1]) {
					isMax = false;
					break;
				}
			}
			if(isMax) numChances++;
		} else {
			String AB = gameLeft.get(0);
			int A = Integer.parseInt(AB.substring(0,1));
			int B = Integer.parseInt(AB.substring(1,2));
			gameLeft.remove(AB);
			//First team W
			point[A-1] += 3;
			recurse(point,gameLeft,favourite);
			point[A-1] -= 3;
			//T
			point[A-1]++;
			point[B-1]++;
			recurse(point,gameLeft,favourite);
			point[A-1]--;
			point[B-1]--;
			//First team L
			point[B-1] += 3;
			recurse(point,gameLeft,favourite);
			point[B-1] -= 3;
			gameLeft.add(0, AB);
		}
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		int[] point = new int[4];
		ArrayList<String> gameLeft = new ArrayList<String>();
		gameLeft.add("12");
		gameLeft.add("13");
		gameLeft.add("14");
		gameLeft.add("23");
		gameLeft.add("24");
		gameLeft.add("34");
		int G = input.nextInt();
		for(int i = 0; i < G; i++) {
			int A = input.nextInt();
			int B = input.nextInt();
			String AB = Integer.toString(A) + Integer.toString(B);
			gameLeft.remove(AB);
			int Sa = input.nextInt();
			int Sb = input.nextInt();
			if(Sa > Sb) point[A-1] += 3;
			else if(Sa == Sb) {
				point[A-1]++;
				point[B-1]++;
			} else point[B-1] += 3;
		}
		recurse(point,gameLeft,T);
		System.out.println(numChances);
	}
}