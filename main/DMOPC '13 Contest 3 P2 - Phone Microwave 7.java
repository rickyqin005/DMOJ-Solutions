import java.util.Scanner;
public class Q4 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int S = input.nextInt();
		input.nextLine();
		String[] time = input.nextLine().split("[/: ]");
		int year = Integer.parseInt(time[0]);
		int month = Integer.parseInt(time[1]);
		int day = Integer.parseInt(time[2]);
		int hour = Integer.parseInt(time[3]);
		int minute = Integer.parseInt(time[4]);
		int second = Integer.parseInt(time[5]);
		int[] monthLength = {31,28,31,30,31,30,31,31,30,31,30,31};
		while(S > 0) {
			hour--;
			S--;
			if(hour < 0) {
				day--;
				hour = 23;
				if(day == 0) {
					month--;
					if(month == 0) {
						year--;
						month = 12;
					}
					day = monthLength[month-1];
				}
			}
		}
		System.out.printf("%04d/%02d/%02d %02d:%02d:%02d", year,month,day,hour,minute,second);
	}
}