import java.io.*;
import java.util.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] in = br.readLine().split(" ");
		int N = Integer.parseInt(in[0]), T = Integer.parseInt(in[1]);
		Card[] cards = new Card[N];
		
		for(int i = 0; i < N; i++) {
			in = br.readLine().split(" ");
			cards[i] = new Card(in[0],Integer.parseInt(in[1]));
		}
		
		Arrays.sort(cards, new Comparator<Card>() {
			public int compare(Card a, Card b) {return a.name.compareTo(b.name);}
		});
		
		for(int i = 0; i < N-2; i++) {
			for(int j = i+1; j < N-1; j++) {
				for(int k = j+1; k < N; k++) {
					if(cards[i].cost + cards[j].cost + cards[k].cost <= T) {
						System.out.println(cards[i].name+" "+cards[j].name+" "+cards[k].name);
					}
				}
			}
		}
	}
	static class Card {
		String name; int cost;
		Card(String n, int c) {
			name = n; cost = c;
		}
	}
}