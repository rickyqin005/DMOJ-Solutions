import java.util.Scanner;
import java.util.ArrayList;
public class Q6 {
	public static void recurse(String[][] restriction,ArrayList<String> path,int length,int L) {
		if(path.size() <= L) {
			for(int i = 0; i < path.size(); i++) {
				System.out.print(path.get(i));
			}
			System.out.println();
			for(int i = length+1; i < restriction.length; i++) {
				for(int j = 0; j < restriction[i].length; j++) {
					path.add(restriction[i][j]);
					recurse(restriction,path,i,L);
					path.remove(path.size()-1);
				}
			}
		}
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int L = input.nextInt();
		String[][] restriction = new String[N][];
		for(int i = 0; i < N; i++) {
			int M = input.nextInt();
			restriction[i] = new String[M];
			for(int j = 0; j < M; j++) {
				restriction[i][j] = input.next();
			}
		}
		ArrayList<String> path = new ArrayList<String>();
		for(int i = 0; i < restriction[0].length; i++) {
			path.add(restriction[0][i]);
			recurse(restriction,path,0,L);
			path.remove(0);
		}
	}
}