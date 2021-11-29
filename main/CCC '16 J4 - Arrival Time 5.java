import java.util.Scanner;
public class CCC_16_J4_Arrival_Time {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String[] in = input.next().split(":");
		int h = Integer.parseInt(in[0]);
		int m = Integer.parseInt(in[1]);
		int dist = 0;
		while(dist < 24) {
			if((h >= 7 && h < 10) || (h >= 15 && h < 19)) dist ++;
			else dist += 2;
			m += 10;
			if(m == 60) {
				m = 0;
				h++;
				if(h == 24) h = 0;
			}
		}
		System.out.printf("%02d:%02d", h, m);
	}
}