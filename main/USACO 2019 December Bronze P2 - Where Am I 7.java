import java.util.Scanner;
public class Q3 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		String road = input.next();
		int ans = N;
		outer: for(int i = 0; i < N; i++) {
			boolean multipleOccurence = false;
			for(int j = 0; j < N-i; j++) {
				String substr = road.substring(j, j+i+1);
				if(road.indexOf(substr) != -1 && road.indexOf(substr) != j) {
					multipleOccurence = true;
					continue outer;
				}
			}
			if(!multipleOccurence) {
				ans = i+1;
				break;
			}
		}
		System.out.println(ans);
	}
}