import java.util.Scanner;
import java.util.ArrayList;
public class CCC_15_J4_Wait_Time {
	public static boolean contains(ArrayList<Integer> list, int value) {
		int length = list.size();
		for(int i = 0; i < length; i++) {
			if(list.get(i) == value) return true;
		}
		return false;
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int M = input.nextInt();
		ArrayList<Integer> list = new ArrayList<Integer>();
		String[][] info = new String[M][2];
		input.nextLine();
		for(int i = 0; i < M; i++) {
			info[i] = input.nextLine().split(" ");
			if(!info[i][0].equals("W") && !contains(list,Integer.parseInt(info[i][1]))) {
				list.add(Integer.parseInt(info[i][1]));
			}
		}
		list.sort(null);		
		for(int i = 0; i < list.size(); i++) {
			int totalTime = 0;
			int currentTime = 0;
			boolean isWaiting = false;
			for(int j = 0; j < M; j++) {
				if(isWaiting) {
					if(info[j][0].equals("W")) currentTime += Integer.parseInt(info[j][1]);
					else if(!info[j-1][0].equals("W")) currentTime++;
				}
				if(Integer.parseInt(info[j][1]) == list.get(i)) {
					if(info[j][0].equals("R")) {
						isWaiting = true;
						continue;
					}
					else if(info[j][0].equals("S")) {
						totalTime += currentTime;
						currentTime = 0;
						isWaiting = false;
					}
				}
			}
			System.out.print(list.get(i) + " ");
			if(isWaiting) System.out.println(-1);
			else System.out.println(totalTime);
		}
	}
}