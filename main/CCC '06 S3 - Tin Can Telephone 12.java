import java.io.*;
import java.util.*;
public class Question {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int ans = 0;
		String[] in = br.readLine().split(" ");
		int xR = Integer.parseInt(in[0]), yR = Integer.parseInt(in[1]);
		int xJ = Integer.parseInt(in[2]), yJ = Integer.parseInt(in[3]);
		double stringM = xR-xJ == 0 ? Double.POSITIVE_INFINITY : (double)(yR-yJ)/(xR-xJ);
		double stringB = stringM == Double.POSITIVE_INFINITY ? Double.NaN : -stringM*xR+yR;
		int n = Integer.parseInt(br.readLine());
		for(int i = 0; i < n; i++) {
			in = br.readLine().split(" ");
			boolean isBlocking = false;
			int numCorners = Integer.parseInt(in[0]);
			int prevX = Integer.parseInt(in[1]);
			int prevY = Integer.parseInt(in[2]);
			for(int j = 1; j < numCorners; j++) {
				int currX = Integer.parseInt(in[2*j+1]);
				int currY = Integer.parseInt(in[2*(j+1)]);
				double sideM = prevX-currX == 0 ? Double.POSITIVE_INFINITY :
						(double)(prevY-currY)/(prevX-currX);
				double sideB = sideM == Double.POSITIVE_INFINITY ? Double.NaN :
						-sideM*currX+currY;
				//System.out.println(sideM + " " + sideB);
				if(stringM == sideM) {//same slope
					if(stringB == sideB) {//same line
						if(Math.min(prevX,currX) >= Math.min(xR,xJ) && Math.max(prevX,currX) <= Math.max(xR,xJ)
						&& Math.min(prevY,currY) >= Math.min(yR,yJ) && Math.max(prevY,currY) <= Math.max(yR,yJ)) {
							isBlocking = true; break;
						}
					}
					//will never intersect
				}
				else {
					if(stringM == Double.POSITIVE_INFINITY) {
						double intersectionY = sideM*xR+sideB;
						if(Math.min(prevX, currX) <= xR && Math.max(prevX, currX) >= xR &&
						intersectionY >= Math.min(yR, yJ) && intersectionY <= Math.max(yR, yJ)) {
							isBlocking = true; break;
						}
					} else {
						if(sideM == Double.POSITIVE_INFINITY) {
							double intersectionY = stringM*currX+stringB;
							if(Math.min(xR, xJ) <= currX && Math.max(xR, xJ) >= currX &&
							intersectionY >= Math.min(currY, prevY) && intersectionY <= Math.max(currY, prevY)) {
								isBlocking = true; break;
							}
						} else {
							double intersectionX = (double)(sideB-stringB)/(stringM-sideM);
							if(intersectionX >= Math.min(xR, xJ) && intersectionX <= Math.max(xR, xJ)
							&& intersectionX >= Math.min(currX, prevX) && intersectionX <= Math.max(currX, prevX)) {
								isBlocking = true; break;
							}
						}
					}
				}
				
				prevX = currX;
				prevY = currY;
			}
			if(isBlocking) ans++;
		}
		System.out.println(ans);
	}
}