import java.awt.Point;
import java.util.*;
import java.io.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n, m, answer;
    static char[][] area;
    static final int[] dx = {0, 1, 0, -1};
    static final int[] dy = {1, 0, -1, 0};

    static void input() throws IOException {
        n = 12; m = 6;
        area = new char[n][m];
        for (int i = 0; i < n; ++i) {
            String s = br.readLine();
            for (int j = 0; j < m; ++j) {
                area[i][j] = s.charAt(j);
            }
        }
        answer = 0;
    }

    static List<Point> findDelete() {
        List<Point> explosions = new ArrayList<>();
        boolean[][] vis = new boolean[n][m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                //방문했거나 빈 칸이면 pass
                if(vis[i][j] || area[i][j] == '.') continue;
                vis[i][j] = true;
                Deque<Point> q = new ArrayDeque<>();
                q.add(new Point(i, j));
                int count = 1;
                while (!q.isEmpty()) {
                    Point cur = q.poll();
                    if(count == 4) {
                        explosions.add(cur);
                    }
                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        //범위 밖이나 이미 방문한 경우 pass
                        if(!range(nx, ny) || vis[nx][ny]) continue;
                        //다른 영역이거나 빈 칸일 경우 pass
                        if(area[i][j] != area[nx][ny] || area[nx][ny] == '.') continue;
                        q.add(new Point(nx, ny));
                        vis[nx][ny] = true;
                        ++count;
                    }
                }
            }
        }
        return explosions;
    }

    static void delete(List<Point> explosions) {
        Deque<Point> q = new ArrayDeque<>(explosions);
        while (!q.isEmpty()) {
            Point cur = q.poll();
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(!range(nx, ny) || area[nx][ny] == '.') continue;
                if(area[cur.x][cur.y] != area[nx][ny]) continue;
                q.add(new Point(nx, ny));
            }
            area[cur.x][cur.y] = '.';
        }
    }

    static void gravity() {
        for (int j = 0; j < m; ++j) {
            Deque<Character> puyo = new ArrayDeque<>();
            for (int i = n - 1; i >= 0; --i) {
                if(area[i][j] == '.') continue;
                puyo.add(area[i][j]);
            }
            for (int i = n - 1; i >= 0; --i) {
                if(puyo.isEmpty()) area[i][j] = '.';
                else area[i][j] = puyo.poll();
            }
        }
    }

    static void solution() {
        while(true) {
            //연쇄 터트림 반응
            List<Point> explosions = findDelete();
            if(explosions.isEmpty()) break;
            delete(explosions);
            //밑으로 중력 작용
            gravity();
            ++answer;
        }
        System.out.println(answer);
    }

    private static boolean range(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    public static void main(String[] args) throws IOException {
        input();
        solution();
    }
}
