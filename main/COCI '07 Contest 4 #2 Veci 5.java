import java.util.Scanner;
public class Question {
	static int ans = Integer.MAX_VALUE;
	static int num;
	static String[] N;
	public static void swap(int int1, int int2) {
		String temp = N[int1];
		N[int1] = N[int2];
		N[int2] = temp;
	}
	public static void permute(int p) {
		if(p == N.length) {
			int value = 0;
			for(int i = 0; i < N.length; i++) {
				value += Integer.parseInt(N[N.length-1-i]) * (int)Math.pow(10, i);
			}
			if(value > num && value-num < ans) ans = value-num;
		} else {
			for(int i = p; i < N.length; i++) {
				swap(p,i);
				permute(p+1);
				swap(p,i);
			}
		}
	}
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        num = input.nextInt();
        N = Integer.toString(num).split("");
        permute(0);
        if(ans == Integer.MAX_VALUE) System.out.println(0);
        else System.out.println(num+ans);
    }
}