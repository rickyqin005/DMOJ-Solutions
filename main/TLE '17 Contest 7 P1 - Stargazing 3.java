import java.io.*;
import java.util.HashMap;
public class Planet {
	int X,Y;
	public Planet(int x, int y) {
		X = x; Y = y;
	}
	public boolean equals(Object o) {
		Planet p2 = (Planet)o;
		if(X == p2.X && Y == p2.Y) return true;
		return false;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		HashMap<Integer,Planet> planets = new HashMap<Integer,Planet>();
		planets.put(0,new Planet(0,0));
		int N = Integer.parseInt(br.readLine());
		int ans = N;
		for(int i = 1; i < N; i++) {
			String[] in = br.readLine().split(" ");
			int P = Integer.parseInt(in[0]),X = Integer.parseInt(in[1]),Y = Integer.parseInt(in[2]);
			Planet p = new Planet(X + planets.get(P-1).X,Y + planets.get(P-1).Y);
			if(planets.containsValue(p)) ans--;
			planets.put(i,p);
		}
		System.out.println(ans);
	}
}