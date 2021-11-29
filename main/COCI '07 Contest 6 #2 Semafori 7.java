import java.util.Scanner;
import java.util.LinkedList;
public class TrafficLight {
	int distance, cGreen, cRed, cTotal;
	public TrafficLight(int d, int r, int g) {
		distance = d; cGreen = g; cRed = r; cTotal = g+r;
	}
	public static boolean lightColor(int t, TrafficLight light) {
		t = t % light.cTotal;
		if(t < light.cRed) return false;
		else return true;
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		int L = input.nextInt();
		LinkedList<TrafficLight> light = new LinkedList<TrafficLight>();
		for(int i = 0; i < N; i++) {
			light.add(new TrafficLight(input.nextInt(),input.nextInt(),input.nextInt()));
		}
		int position = 0;
		int time = 0;
		while(position < L) {
			if(light.size() > 0) {
				TrafficLight nextLight = light.getFirst();
				if(nextLight.distance > position) position++;
				else {
					if(lightColor(time,nextLight)) {
						position++;
						light.removeFirst();
					}
				}
			} else position++;
			time++;
		}
		System.out.println(time);
	}
}