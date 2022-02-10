import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int ans1 = 0;
		int ans2 = 0;
		int[][] last = {
				{0,0,0,0},
				{1,1,1,1},
				{2,4,8,6},
				{3,9,7,1},
				{4,6,4,6},
				{5,5,5,5},
				{6,6,6,6},
				{7,9,3,1},
				{8,4,2,6},
				{9,1,9,1}
		};
		char[] name1 = br.readLine().toLowerCase().toCharArray();
		for(int i = 0; i < name1.length; i++) {
			ans1 += last[((int)name1[i]-96)%10][i%4];
		}
		ans1--; ans1 %= 10; ans1++;
		name1 = br.readLine().toLowerCase().toCharArray();
		for(int i = 0; i < name1.length; i++) {
			ans2 += last[((int)name1[i]-96)%10][i%4];
		}
		ans2--; ans2 %= 10; ans2++;
		System.out.println(ans1+ans2);
	}
}