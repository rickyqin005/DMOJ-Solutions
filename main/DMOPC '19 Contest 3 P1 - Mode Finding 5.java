import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;
public class Question {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		ArrayList<Integer> mode = new ArrayList<Integer>();
		int N = input.nextInt();
		for(int i = 0; i < N; i++) {
			int num = input.nextInt();
			if(!map.containsKey(num)) map.put(num, 1);
			else map.replace(num, map.get(num)+1);
		}
		int maxOccurence = 0;
		for(int i: map.keySet()) {
			int occurence = map.get(i);
			if(occurence > maxOccurence) {
				mode.clear();
				mode.add(i);
				maxOccurence = occurence;
			} else if(occurence == maxOccurence) mode.add(i);
		}
		Collections.sort(mode);
		for(int i = 0; i < mode.size(); i++) {
			System.out.print(mode.get(i));
			if(i < mode.size()-1) System.out.print(" ");
		}
		System.out.println();
	}
}