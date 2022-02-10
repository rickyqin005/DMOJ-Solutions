import java.util.Scanner;
public class Question3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double H = in.nextDouble();
        int D = in.nextInt(), E = in.nextInt();
        int[][] defense = new int[D][2];
        int[] time = new int[1000];
        for(int i = 0; i < D; i++) {
        	defense[i][0] = in.nextInt();
        	defense[i][1] = in.nextInt();
        }
        for(int i = 0; i < E; i++) {
        	int T = in.nextInt(), L = in.nextInt(), X = in.nextInt();
        	for(int j = 0; j < L; j++) {
        		time[T+j] += X;
        	}
        }
        for(int i = 0; i < 1000; i++) {
        	double minDamage = time[i];
        	for(int j = 0; j < D; j++) {
        		minDamage = Math.min(minDamage,(time[i]-Math.min(time[i],defense[j][1]))*(1-defense[j][0]/100.0));
        	}
        	H -= minDamage;
        	if(H <= 0) {System.out.println("DO A BARREL ROLL!"); System.exit(0);}
        }
        System.out.printf("%.2f\n",H);
    }
}