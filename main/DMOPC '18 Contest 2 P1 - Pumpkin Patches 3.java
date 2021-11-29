import java.io.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int P = Integer.parseInt(br.readLine());
		int minX = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE;
		int minY = Integer.MAX_VALUE, maxY = Integer.MIN_VALUE;
		for(int i = 0; i < P; i++) {
			String[] in = br.readLine().split(" ");
			int x = Integer.parseInt(in[0]), y = Integer.parseInt(in[1]);
			minX = Math.min(minX,x); maxX = Math.max(maxX,x);
			minY = Math.min(minY,y); maxY = Math.max(maxY,y);
		}
		System.out.println(2*(maxX-minX+maxY-minY));
	}
}