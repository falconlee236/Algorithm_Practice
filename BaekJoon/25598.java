package BaekJoon;
import java.io.*;
import java.util.*;
class main {
    private HashMap<Character, int[]> mp;
    int[][] arr;
    PriorityQueue<int[]> pq;
    int N;
    private class Zombie {
        int type, speed;
        char dir;
        int[] pos;
        Zombie(int[] pos, int type, char dir, int speed){
            this.type = type;
            this.dir = dir;
            this.speed = speed;
            this.pos = pos;
        }
    }
    private char opposite(char c){
        if (c == 'U') return 'D';
        if (c == 'D') return 'U';
        if (c == 'L') return 'R';
        return 'L';
    }
    private void getWallCount(int[] cur, char c, int priority){
        int[] next = mp.get(c);
        int nx = cur[0] + next[0];
        int ny = cur[1] + next[1];
        int num = 0;
        while (0 < nx && nx <= N && 0 < ny && ny <= N){
            if (arr[nx][ny] == -1) num++;
            nx += next[0];
            ny += next[1];
        }
        pq.offer(new int[]{num, priority, c - 'A'});
    }
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        arr = new int[N + 1][N + 1];
        char[] command = br.readLine().toCharArray();
        int[] pos = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int W = Integer.parseInt(br.readLine());
        for(int i = 0; i < W; i++){
            st = new StringTokenizer(br.readLine());
            arr[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = -1;
        }
        int Z = Integer.parseInt(br.readLine());
        Zombie[] zombies = new Zombie[Z];
        for(int i = 0; i < Z; i++){
            st = new StringTokenizer(br.readLine());
            zombies[i] = new Zombie(
                new int[]{Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())}, 
                Integer.parseInt(st.nextToken()),
                st.nextToken().charAt(0),
                Integer.parseInt(st.nextToken())
            );
        }
        int D = Integer.parseInt(br.readLine());
        mp = new HashMap<>();
        mp.put('U', new int[]{-1, 0});
        mp.put('D', new int[]{1, 0});
        mp.put('L', new int[]{0, -1});
        mp.put('R', new int[]{0, 1});
        mp.put('S', new int[]{0, 0});
        pq = new PriorityQueue<>((int[] o1, int[] o2) -> {
            if (o1[0] == o2[0]) return o2[1] - o1[1];
            return o2[0] - o1[0];
        });
        for(int t = 0; t < D; t++){
            int[] next = mp.get(command[t]);
            int nx = pos[0] + next[0], ny = pos[1] + next[1];
            if (0 < nx && nx <= N && 0 < ny && ny <= N && arr[nx][ny] != -1){
                pos[0] = nx;
                pos[1] = ny;
            }
            for (Zombie z : zombies) {
                next = mp.get(z.dir);
                nx = z.pos[0];
                ny = z.pos[1];
                for(int i = 0; i < z.speed; i++){
                    if (1 > nx + next[0] || nx + next[0] > N || 1 > ny + next[1] || ny + next[1] > N) {
                        if (z.type == 0) z.dir = opposite(z.dir);
                        break;
                    }
                    if (arr[nx + next[0]][ny + next[1]] == -1) {
                        if (z.type == 1) arr[nx + next[0]][ny + next[1]] = 0;
                        else z.dir = opposite(z.dir);
                        break;
                    }
                    nx += next[0];
                    ny += next[1];
                }
                z.pos[0] = nx;
                z.pos[1] = ny;
                if (z.type == 1){
                    getWallCount(z.pos, 'U', 4);
                    getWallCount(z.pos, 'R', 3);
                    getWallCount(z.pos, 'D', 2);
                    getWallCount(z.pos, 'L', 1);
                    z.dir = (char)(pq.peek()[2] + 'A');
                    pq.clear();
                }
            }
            for (Zombie zombie : zombies) {
                if (zombie.pos[0] == pos[0]  && zombie.pos[1] == pos[1]){
                    System.out.println(t + 1);
                    System.out.println("DEAD...");
                    return;
                }
            }
        }
        System.out.println("ALIVE!");
    }
    public static void main(String[] args) throws Exception{
        new main().solution();
    }
}