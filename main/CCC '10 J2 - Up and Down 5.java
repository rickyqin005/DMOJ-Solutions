import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int ans1 = 0, ans2 = 0;
		int a = Integer.parseInt(br.readLine());
		int b = Integer.parseInt(br.readLine());
		int c = Integer.parseInt(br.readLine());
		int d = Integer.parseInt(br.readLine());
		int s = Integer.parseInt(br.readLine());
		ans1 += (a-b)*(s/(a+b));
		ans1 += Math.min(a,s%(a+b)) - Math.max(0,s%(a+b)-a);
		ans2 += (c-d)*(s/(c+d));
		ans2 += Math.min(c,s%(c+d)) - Math.max(0,s%(c+d)-c);
		if(ans1 > ans2) System.out.println("Nikky");
		else if (ans1 == ans2) System.out.println("Tied");
		else System.out.println("Byron");
	}
}