import java.io.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		String[] partner1 = br.readLine().split(" ");
		String[] partner2 = br.readLine().split(" ");
		boolean isConsistent = true;
		outer: for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(partner1[j].equals(partner2[i])) {
					if(partner2[j].equals(partner1[i]) && !partner1[i].equals(partner2[i]));
					else {
						isConsistent = false;
						break outer;
					}
				}
			}
		}
		if(isConsistent) System.out.println("good");
		else System.out.println("bad");
	}
}