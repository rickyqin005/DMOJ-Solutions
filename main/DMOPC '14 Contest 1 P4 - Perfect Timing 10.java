import java.io.*;
import java.util.*;
public class Question5 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] in = br.readLine().split(" ");
        String[] in2 = br.readLine().split(" ");
        int dist = Math.abs(Integer.parseInt(in[0])-Integer.parseInt(in2[0]))
        		+Math.abs(Integer.parseInt(in[1])-Integer.parseInt(in2[1]));
        in = br.readLine().split(":");
        int[] monthLen = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = Integer.parseInt(in[0]), mon = Integer.parseInt(in[1]);
        int day = Integer.parseInt(in[2]), hour = Integer.parseInt(in[3]);
        int min = Integer.parseInt(in[4]), sec = Integer.parseInt(in[5]);
        for(int i = 0; i < dist; i++) {
        	sec++;
        	if(sec == 60) {
        		sec = 0;
        		min++;
        		if(min == 60) {
        			min = 0;
        			hour++;
        			if(hour == 24) {
        				hour = 0;
        				day++;
        				int numDays = monthLen[mon-1];
        				if(mon == 2) {
    						if(year % 4 == 0) {
    							if(year % 100 == 0) {
    								if(year % 400 == 0) numDays = 29;
    								else numDays = 28;
    							} else numDays = 29;
    						}
        				}
        				if(day > numDays) {
        					day = 1;
        					mon++;
        					if(mon == 13) {
        						mon = 1;
        						year++;
        					}
        				}
        			}
        		}
        	}
        }
        System.out.printf("%d:%02d:%02d:%02d:%02d:%02d\n",year,mon,day,hour,min,sec);
    }
}