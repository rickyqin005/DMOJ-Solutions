import java.util.Scanner;
import java.util.ArrayList;
public class Q7 {
	public static boolean listContains(ArrayList<int[]> list, int[] arr) {
		for(int i = 0; i < list.size(); i++) {
			if(arrayEquals(list.get(i),arr)) return true;
		}
		return false;
	}
	public static boolean arrayEquals(int[] arr1, int[] arr2) {
		for(int i = 0; i < 3; i++) {
			if(arr1[i] != arr2[i]) return false;
		}
		return true;
	}	
	public static boolean allIn(String str, String chr) {
		for(int i = 0; i < str.length(); i++) {
			if(chr.indexOf(str.charAt(i)) == -1) return false;
		}
		return true;
	}
	public static int duration(int[] time) {
		return 3600*time[0] + 60*time[1] + time[2];
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String[] in = input.next().split("[:]");
		String buttons = input.next();
		ArrayList<int[]> allTimes = new ArrayList<int[]>();
		int[] time = {Integer.parseInt(in[0]),Integer.parseInt(in[1]),Integer.parseInt(in[2])};
		int offset = Integer.MAX_VALUE;
		int[] bestTime = time;
		
		allTimes.add(time);
		if(time[1] < 40) {
			int[] time2 = time.clone();
			time2[0]--;
			time2[1] += 60;
			if(!listContains(allTimes,time2) && time2[0] >= 0 && time2[0] < 100) allTimes.add(time2);
		} else if(time[1] >= 60) {
			int[] time2 = time.clone();
			time2[0]++;
			time2[1] -= 60;
			if(!listContains(allTimes,time2) && time2[0] >= 0 && time2[0] < 100) allTimes.add(time2);
		}
		for(int i = 0; i < allTimes.size(); i++) {
			if(allTimes.get(i)[2] < 40) {
				int[] time2 = allTimes.get(i).clone();
				time2[1]--;
				time2[2] += 60;
				if(time2[1] < 0) {
					time2[0]--;
					time2[1] += 60;
				}
				if(!listContains(allTimes,time2) && time2[0] >= 0 && time2[0] < 100) allTimes.add(time2);
			} else if(allTimes.get(i)[2] >= 60) {
				int[] time2 = allTimes.get(i).clone();
				time2[1]++;
				time2[2] -= 60;
				if(time2[1] >= 100) {
					time2[0]++;
					time2[1] -= 60;
				}
				if(!listContains(allTimes,time2) && time2[0] >= 0 && time2[0] < 100) allTimes.add(time2);
			}
		}
		outer1: for(int i = 0; i < allTimes.size(); i++) {
			int[] timeDown = allTimes.get(i).clone();
			
			while(!allIn(String.format("%02d", timeDown[0]),buttons)) {
				timeDown[0]--;
				timeDown[1] = 99;
				timeDown[2] = 99;
				if(timeDown[0] < 0 || timeDown[0] >= 100) continue outer1;
			}
			while(!allIn(String.format("%02d", timeDown[1]),buttons)) {
				timeDown[1]--;
				timeDown[2] = 99;
				if(timeDown[1] < 0) {
					timeDown[0]--;
					timeDown[1] += 100;
					if(timeDown[0] < 0 || timeDown[0] >= 100) continue outer1;
				}
			}
			while(!allIn(String.format("%02d", timeDown[2]),buttons)) {
				timeDown[2]--;
				if(timeDown[2] < 0) {
					timeDown[1]--;
					timeDown[2] += 100;
					if(timeDown[1] < 0) {
						timeDown[0]--;
						timeDown[1] += 100;
						if(timeDown[0] < 0 || timeDown[0] >= 100) continue outer1;
					}
				}
			}
			if(Math.abs(duration(time) - duration(timeDown)) < offset && allIn(String.format("%02d%02d%02d",timeDown[0],timeDown[1],timeDown[2]),buttons)) {
				offset = Math.abs(duration(time) - duration(timeDown));
				bestTime = timeDown;
			}
		}
		
		outer2: for(int i = 0; i < allTimes.size(); i++) {
			int[] timeUp = allTimes.get(i).clone();
			while(!allIn(String.format("%02d", timeUp[0]),buttons)) {
				timeUp[0]++;
				timeUp[1] = 0;
				timeUp[2] = 0;
				if(timeUp[0] < 0 || timeUp[0] >= 100) continue outer2;
			}
			while(!allIn(String.format("%02d", timeUp[1]),buttons)) {
				timeUp[1]++;
				timeUp[2] = 0;
				if(timeUp[1] > 99) {
					timeUp[0]++;
					timeUp[1] -= 100;
					if(timeUp[0] < 0 || timeUp[0] >= 100) continue outer2;
				}
			}
			while(!allIn(String.format("%02d", timeUp[2]),buttons)) {
				timeUp[2]++;
				if(timeUp[2] > 99) {
					timeUp[1]++;
					timeUp[2] -= 100;
					if(timeUp[1] > 99) {
						timeUp[0]++;
						timeUp[1] -= 100;
						if(timeUp[0] < 0 || timeUp[0] >= 100) continue outer2;
					}
				}
			}
			if(Math.abs(duration(time) - duration(timeUp)) < offset  && allIn(String.format("%02d%02d%02d",timeUp[0],timeUp[1],timeUp[2]),buttons)) {
				offset = Math.abs(duration(time) - duration(timeUp));
				bestTime = timeUp;
			}
			
		}
		System.out.printf("%02d:%02d:%02d\n", bestTime[0],bestTime[1],bestTime[2]);
	}
}