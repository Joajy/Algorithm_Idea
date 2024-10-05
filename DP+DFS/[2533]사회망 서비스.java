import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int[] a;
    static List<Integer>[] edges;
    static boolean[] vis;
    static int[][] dp;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        a = new int[n + 1];
        edges = new ArrayList[n + 1];
        dp = new int[n + 1][2];
        vis = new boolean[n + 1];
        for (int i = 1; i <= n; ++i) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            edges[u].add(v);
            edges[v].add(u);
        }
    }

    static void dfs(int cur) {
        vis[cur] = true;
        //[i][0]: 얼리어답터 아닌 경우 | [i][1]: 얼리어답터인 경우(얼리어답터 시작점이므로 1을 대입한다)
        dp[cur][0] = 0;
        dp[cur][1] = 1;
        for (int nxt : edges[cur]) {
            if(vis[nxt]) continue;
            dfs(nxt);
            //얼리어답터의 친구임을 전제
            dp[cur][0] += dp[nxt][1];
            //본인이 얼리어답터이므로, 친구들로부터 얻을 수 있는 가장 작은 값을 가져와서 대입한다.
            dp[cur][1] += Math.min(dp[nxt][0], dp[nxt][1]);
        }
    }

    static void solution() {
        dfs(1);
        int answer = Math.min(dp[1][0], dp[1][1]);
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
