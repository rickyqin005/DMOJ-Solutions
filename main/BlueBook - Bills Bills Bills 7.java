import java.io.*;
import java.util.*;
public class Question5 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int[] level = {20, 55, 85};
		double[] rate = {23.73, 22.71, 21.78};
		while(true) {
			String account = br.readLine();
			if(Integer.parseInt(account) < 0) break;
			st = new StringTokenizer(br.readLine());
			int ob1 = Integer.parseInt(st.nextToken()), ob2 = Integer.parseInt(st.nextToken());
			int consumption = (ob2 < ob1) ? ob2+10000-ob1 : ob2-ob1;
			double ans = 6.59;
			consumption -= Math.min(consumption, 10);
			for(int i = 0; i < 3; i++) {
				int currCons = Math.min(level[i], consumption);
				ans += currCons*rate[i]/100;
				consumption -= currCons;
				if(consumption <= 0) break;
			}
			ans += consumption*20.85/100;
			System.out.println("Account #: " + account);
			System.out.printf("Bill: %.2f\n",ans);
		}
	}
}