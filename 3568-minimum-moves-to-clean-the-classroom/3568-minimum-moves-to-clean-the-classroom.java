     class State {

    int r;
    int c;
    int energy;
    int mask;
    int moves;

    State(int r, int c, int energy, int mask, int moves) {
        this.r = r;
        this.c = c;
        this.energy = energy;
        this.mask = mask;
        this.moves = moves;
    }
}

class Solution {
    public int minMoves(String[] classroom, int energy) {
                 int m = classroom.length;
        int n = classroom[0].length();

        int startR = 0;
        int startC = 0;

        // 1. Find starting position and count litter
        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i].charAt(j) == 'S') {
                    startR = i;
                    startC = j;
                }

                if (classroom[i].charAt(j) == 'L') {
                    litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0) {
            return 0;
        }

        // 2. Give every litter an index
        int[][] litterIndex = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                litterIndex[i][j] = -1;
            }
        }

        int index = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i].charAt(j) == 'L') {
                    litterIndex[i][j] = index;
                    index++;
                }
            }
        }

        // 3. All litter collected mask
        int fullMask = (1 << litterCount) - 1;

        // 4. BFS
        Queue<State> queue = new LinkedList<>();

        queue.offer(new State(startR, startC, energy, 0, 0));

        // visited[row][col][energy][mask]
        boolean[][][][] visited =
                new boolean[m][n][energy + 1][1 << litterCount];

        visited[startR][startC][energy][0] = true;

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!queue.isEmpty()) {

            State current = queue.poll();

            int r = current.r;
            int c = current.c;
            int e = current.energy;
            int mask = current.mask;
            int moves = current.moves;

            
            if (mask == fullMask) {
                return moves;
            }

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                    continue;
                }

            
                if (classroom[nr].charAt(nc) == 'X') {
                    continue;
                }

        
                if (e == 0) {
                    continue;
                }

                int newEnergy = e - 1;
                int newMask = mask;

    
                if (classroom[nr].charAt(nc) == 'L') {

                    int bit = litterIndex[nr][nc];

                    newMask = mask | (1 << bit);
                }

                
                if (classroom[nr].charAt(nc) == 'R') {
                    newEnergy = energy;
                }

            
                if (!visited[nr][nc][newEnergy][newMask]) {

                    visited[nr][nc][newEnergy][newMask] = true;

                    queue.offer(
                        new State(
                            nr,
                            nc,
                            newEnergy,
                            newMask,
                            moves + 1
                        )
                    );
                }
            }
        }

        return -1;
    }
}