import java.io.*;
import java.util.*;
public class Question4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[][] boxes = new int[n][4];
		for(int i = 0; i < n; i++) {
			String[] in = br.readLine().split(" ");
			boxes[i][0] = Integer.parseInt(in[0]); boxes[i][1] = Integer.parseInt(in[1]);
			boxes[i][2] = Integer.parseInt(in[2]); boxes[i][3] = boxes[i][0]*boxes[i][1]*boxes[i][2];
			Arrays.sort(boxes[i]);
		}
		Arrays.sort(boxes, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[3] == b[3]) {
					if(a[0] == b[0]) {
						if(a[1] == b[1]) return Integer.compare(a[2], b[2]);
						else return Integer.compare(a[1], b[1]);
					} else return Integer.compare(a[0], b[0]);
				} else return Integer.compare(a[3], b[3]);
			}
		});
		int m = Integer.parseInt(br.readLine());
		outer: for(int i = 0; i < m; i++) {
			String[] in = br.readLine().split(" ");
			int[] item = {Integer.parseInt(in[0]), Integer.parseInt(in[1]), Integer.parseInt(in[2])};
			Arrays.sort(item);
			for(int j = 0; j < n; j++) {
				if(item[0] <= boxes[j][0] && item[1] <= boxes[j][1] && item[2] <= boxes[j][2]) {
					System.out.println(boxes[j][3]); continue outer;
				} else continue;
			}
			System.out.println("Item does not fit.");
		}
	}
}