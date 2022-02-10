import java.util.Scanner;
public class Cutting_Logs {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int L = input.nextInt();
		String[] log = input.next().split("");
		int numLogs = 0;
		boolean isLog = false;
		for(int i = 0; i < log.length; i++) {
			if(log[i].equals("O")) {
				if(!isLog) numLogs++;
				isLog = true;
			}
			else isLog = false;
			
		}
		System.out.println(numLogs);
		
		for(int i = 0; i < log.length; i++) {
			if(log[i].equals("O")) {
				System.out.print("O");
				if(i+1 < log.length) {
					if(log[i+1].equals("X")) System.out.println();
				}
			}
		}
	}
}