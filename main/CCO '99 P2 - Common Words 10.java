import java.io.*;
import java.util.*;
public class Question3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i < n; i++) {
			HashMap<String,Integer> wordFreq = new HashMap<String,Integer>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(st.nextToken());
			int k = Integer.parseInt(st.nextToken());
			for(int j = 0; j < m; j++) {
				String str = br.readLine();
				wordFreq.putIfAbsent(str,0);
				wordFreq.replace(str, wordFreq.get(str)+1);
			}
			ArrayList<String> words = new ArrayList<String>(wordFreq.keySet());
			Collections.sort(words, new Comparator<String>() {
				public int compare(String a, String b) {
					return Integer.compare(wordFreq.get(a),wordFreq.get(b))*-1;
				}
			});
			String ordinal = "";
			if(k % 100 >= 10 && k % 100 < 20) ordinal = "th";
			else if(k % 10 == 1) ordinal = "st";
			else if(k % 10 == 2) ordinal = "nd";
			else if(k % 10 == 3) ordinal = "rd";
			else ordinal = "th";
			System.out.println(k + ordinal + " most common word(s):");
			if(k > m) {
				if(i != n-1) System.out.println();
				continue;
			}
			int rank = 1; int count = 1;
			int prevFreq = wordFreq.get(words.get(0));
			for(String j: words) {
				if(wordFreq.get(j) != prevFreq) rank = count;
				if(rank == k) System.out.println(j);
				else if(rank > k) break;
				prevFreq = wordFreq.get(j);
				count++;
			}
			if(i != n-1) System.out.println();
		}
	}
}