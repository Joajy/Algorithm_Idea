import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n, m;
    static int[][] area;
    static boolean[] col;
    static int[] row;

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        area = new int[n][m];
        col = new boolean[m];
        row = new int[n];
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; ++j) {
                area[i][j] = Integer.parseInt(st.nextToken());
                if(area[i][j] == 1) {
                    col[j] = true;
                    row[i] = j;
                }
            }
        }
    }

    static void solution() {
        int answer = 0;
        /*
        * 오른쪽으로 이동하는 것은 자명하다
        * 그런데, 오른쪽에 더 이상 치울 것이 없을 경우 두 가지 케이스로 나뉜다.
        * 1. 더 오른쪽으로 가서 1이 있는지 확인하는 것
        * 2. 아래로 즉시 내려가서 우향 탐색하는 방법
        * */
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(area[i][j] == 1) {
                    ++answer;
                    //오른쪽으로 이동하기 위해 기준 노드를 잡아준다.
                    //기준 노드 변경해가며 특정 노드부터 시작하여 오른쪽으로 이동한 뒤 하단으로 내려가는 패턴
                    //이렇게 함으로써 가장 오른쪽의 1이 있는 구간에서부터 i + 1 ~ n까지 내려가며 우측 외곽 부분을 제어할 수 있다.
                    int index = j;
                    for (int r = i; r < n; ++r) {
                        for (int c = index; c < m; ++c) {
                            if(area[r][c] == 0) continue;
                            area[r][c] = 0;
                            index = c;
                        }
                    }
                }
            }
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
