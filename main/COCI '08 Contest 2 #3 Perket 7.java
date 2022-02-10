import java.util.Scanner;
import java.util.ArrayList;
public class Question {
	static int min = 1000000000;
	static int[] sourness;
	static int[] bitterness;
	public static void nCr(ArrayList<Integer> list, int n, int r, int l) {
		if(list.size() >= r) {
			int totalSour = 1;
			int totalBitter = 0;
			for(int i = 0; i < list.size(); i++) {
				totalSour *= sourness[list.get(i)];
				totalBitter += bitterness[list.get(i)];
			}
			min = Math.min(min, Math.abs(totalSour-totalBitter));
		} else {
			for(int i = l+1; i < n; i++) {
				list.add(i);
				nCr(list,n,r,i);
				list.remove(list.size()-1);
			}
		}
	}
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        sourness = new int[N];
        bitterness = new int[N];
        for(int i = 0; i < N; i++) {
        	sourness[i] = input.nextInt();
        	bitterness[i] = input.nextInt();
        }
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 1; i <= N; i++) {
        	nCr(list,N,i,-1);
        }
        System.out.println(min);
    }
}