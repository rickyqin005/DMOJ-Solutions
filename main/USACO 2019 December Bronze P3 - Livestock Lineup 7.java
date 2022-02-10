import java.io.*;
import java.util.*;
public class Cow {
	static HashMap<String,Integer> cowNum = new HashMap<String,Integer>();
	static String[] cowName = {"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
	static int[] order = {0,1,2,3,4,5,6,7};
	static int[] ans = {7,6,5,4,3,2,1,0};
	static int[][] restriction;
	static int N;
	public static void permute(int lvl) {
		if(lvl == 8) {
			int[] pos = new int[8];
			for(int i = 0; i < 8; i++) {
				pos[order[i]] = i;
			}
			for(int i = 0; i < N; i++) {
				if(Math.abs(pos[restriction[i][0]]-pos[restriction[i][1]]) > 1) return;
			}
			for(int i = 0; i < 8; i++) {
				if(order[i] < ans[i]) break;
				if(order[i] > ans[i]) return;
			}
			//System.out.println(Arrays.toString(order));
			ans = order.clone();
		} else {
			for(int i = lvl; i < 8; i++) {
				int temp = order[lvl];
				order[lvl] = order[i];
				order[i] = temp;
				permute(lvl+1);
				order[i] = order[lvl];
				order[lvl] = temp;
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		cowNum.put("Beatrice", 0);
		cowNum.put("Belinda", 1);
		cowNum.put("Bella", 2);
		cowNum.put("Bessie", 3);
		cowNum.put("Betsy", 4);
		cowNum.put("Blue", 5);
		cowNum.put("Buttercup", 6);
		cowNum.put("Sue", 7);

		N = Integer.parseInt(br.readLine());
		restriction = new int[N][2];
		for(int i = 0; i < N; i++) {
			String[] in = br.readLine().split(" must be milked beside ");
			restriction[i][0] = cowNum.get(in[0]);
			restriction[i][1] = cowNum.get(in[1]);
		}
		permute(0);
		for(int i = 0; i < 8; i++) {
			System.out.println(cowName[ans[i]]);
		}
	}
}