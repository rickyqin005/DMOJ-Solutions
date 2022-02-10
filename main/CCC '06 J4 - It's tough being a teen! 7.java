import java.io.*;
import java.util.*;
public class Question {
	static ArrayList<int[]> rules;
	static int[] ans = {7,7,7,7,7,7,7};
	static int[] order = {0,1,2,3,4,5,6};
	static int numRules = 5;
	public static void permute(int lvl) {
		if(lvl == 7) {
			int[] pos = new int[7];
			for(int i = 0; i < 7; i++) {
				pos[order[i]] = i;
			}
			for(int[] i: rules) {
				if(pos[i[0]] > pos[i[1]]) return;
			}
			int i = 0;
			for(; i < 7; i++) {
				if(order[i] > ans[i]) return;
				else if(order[i] < ans[i]) break;
			}
			for(; i < 7; i++) {
				ans[i] = order[i];
			}
		} else {
			for(int i = lvl; i < 7; i++) {
				int temp = order[lvl];
				order[lvl] = order[i];
				order[i] = temp;
				permute(lvl+1);
				temp = order[lvl];
				order[lvl] = order[i];
				order[i] = temp;
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		rules = new ArrayList<int[]>(15);
		rules.add(new int[] {0,6});
		rules.add(new int[] {0,3});
		rules.add(new int[] {1,0});
		rules.add(new int[] {2,3});
		rules.add(new int[] {2,4});
		while(true) {
			int a = Integer.parseInt(br.readLine()), b = Integer.parseInt(br.readLine());
			if(a == 0 && b == 0) break;
			rules.add(new int[]{a-1,b-1});
			numRules++;
		}
		permute(0);
		
		if(ans[0] == 7) {
			System.out.println("Cannot complete these tasks. Going to bed.");
		} else {
			System.out.print(ans[0]+1);
			for(int i = 1; i < 7; i++) {
				System.out.print(" "+(ans[i]+1));
			}
			System.out.println();
		}
	}
}