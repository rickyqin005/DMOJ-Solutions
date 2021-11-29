import java.util.*;
public class CCC_00_S2_Babbling_Brooks {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		ArrayList<Double> flow = new ArrayList<Double>();
		for(int i = 0; i < n; i++) {
			flow.add(input.nextDouble());
		}
		while(true) {
			int num = input.nextInt();
			if(num == 77) break;
			else if(num == 99) {
				int index = input.nextInt()-1;
				int pct = input.nextInt();
				double volume = flow.get(index);
				flow.add(index, volume*pct/100);
				flow.set(index+1, volume - flow.get(index));
			} else {
				int index = input.nextInt()-1;
				flow.set(index, flow.get(index)+flow.get(index+1));
				flow.remove(index+1);
			}
		}
		for(int i = 0; i < flow.size(); i++) {
			System.out.print(Math.round(flow.get(i)) + " ");
		}
	}
}