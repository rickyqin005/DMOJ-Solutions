import java.io.*;
import java.util.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i = 0; i < 5; i++) {
			int N = Integer.parseInt(br.readLine());
			int[] cardOrder = new int[N];
			boolean isPossible = true;
			ArrayList<Integer> allCards = new ArrayList<Integer>();
			for(int j = 0; j < N; j++) {
				allCards.add(j+1);
			}
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				int count = Integer.parseInt(st.nextToken());
				if(allCards.size()-count-1 < 0) {
					isPossible = false; break;
				} else cardOrder[j] = allCards.remove(allCards.size()-count-1);
			}
			if(isPossible) {
				for(int j = 0; j < N; j++) {
					System.out.print(cardOrder[j]);
					if(j == N-1) System.out.println();
					else System.out.print(" ");
				}
			} else System.out.println("IMPOSSIBLE");
		}
	}
}