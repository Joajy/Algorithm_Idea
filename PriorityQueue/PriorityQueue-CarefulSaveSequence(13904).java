import java.io.*;
import java.util.*;

public class Main {
	
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int n, m, answer;
	static class Info {
		int d, w;
		Info(int d, int w) {
			this.d = d;
			this.w = w;
		}
	}
	static PriorityQueue<Info> pq;
	static int[] points;
	
    static void input() throws IOException {
    	pq = new PriorityQueue<>((o1, o2) -> {
    		if(o1.d == o2.d) {
    			return Integer.compare(o2.w, o1.w);
    		}
    		return Integer.compare(o2.d, o1.d);
    	});
    	n = Integer.parseInt(br.readLine());
    	for(int i = 0; i < n; ++i) {
        	st = new StringTokenizer(br.readLine());
        	int d = Integer.parseInt(st.nextToken());
        	int w = Integer.parseInt(st.nextToken());
        	pq.add(new Info(d, w));
    	}
    	points = new int[1001];
    }
    
    static void solution() {
    	while(!pq.isEmpty()) {
    		Info cur = pq.poll();
    		for(int i = cur.d; i > 0; --i) {
    			if(points[i] < cur.w) {
    				for(int j = 1; j <= i; ++j) {
    					points[j - 1] = points[j];
    				}
    				points[i] = cur.w;
    				break;
    			}
    		}
    	}
    	for(int i = 1; i < points.length; ++i) {
    		answer += points[i];
    	}
    	System.out.println(answer);
    }
    
    public static void main(String[] args) throws IOException {
    	input();
    	solution();
    }
}
