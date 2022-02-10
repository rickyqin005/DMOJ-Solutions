import java.util.Scanner;
public class Question {
	public static long sum(long[] arr) {
		long sum = 0;
		for(int i = 0; i < arr.length; i++) {
			sum += arr[i];
		}
		return sum;
	}
	public static long deviation(long[] arr,long average) {
		long ans = 0;
		for(int i = 0; i < arr.length; i++) {
			ans += Math.abs(arr[i]-average);
		}
		return ans;
	}
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        long[] friends = new long[N];
        for(int i = 0; i < N; i++) {
        	friends[i] = input.nextLong();
        }
        long sum = sum(friends);
        if(sum % N != 0) System.out.println("Impossible");
        else System.out.println(deviation(friends,sum/N)/2);
    }
}