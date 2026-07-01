public class Solution {
    public int MaximumSafenessFactor(IList<IList<int>> grid) {
        int n = grid.Count;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        int[][] dist = new int[n][];
        for (int i = 0; i < n; i++) {
            dist[i] = new int[n];
            Array.Fill(dist[i], -1);
        }

        Queue<int[]> queue = new Queue<int[]>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue.Enqueue(new int[] { i, j });
                    dist[i][j] = 0;
                }
            }
        }

        int[][] dirs = new int[][] { new int[] { 0, 1 }, new int[] { 0, -1 }, new int[] { 1, 0 }, new int[] { -1, 0 } };

        // Multi-source BFS for distances
        while (queue.Count > 0) {
            int[] curr = queue.Dequeue();
            foreach (var dir in dirs) {
                int ni = curr[0] + dir[0];
                int nj = curr[1] + dir[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[curr[0]][curr[1]] + 1;
                    queue.Enqueue(new int[] { ni, nj });
                }
            }
        }

        // Max-Heap (using PriorityQueue)
        // C# PriorityQueue defaults to min-heap, so we invert the priority
        PriorityQueue<int[], int> pq = new PriorityQueue<int[], int>(Comparer<int>.Create((a, b) => b.CompareTo(a)));
        pq.Enqueue(new int[] { 0, 0, dist[0][0] }, dist[0][0]);
        dist[0][0] = -1; // Mark as visited

        while (pq.Count > 0) {
            pq.TryDequeue(out int[] curr, out int safeness);
            int r = curr[0], c = curr[1], val = curr[2];

            if (r == n - 1 && c == n - 1) return val;

            foreach (var dir in dirs) {
                int ni = r + dir[0];
                int nj = c + dir[1];
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && dist[ni][nj] != -1) {
                    int newSafeness = Math.Min(val, dist[ni][nj]);
                    pq.Enqueue(new int[] { ni, nj, newSafeness }, newSafeness);
                    dist[ni][nj] = -1; // Mark as visited
                }
            }
        }
        return 0;
    }
}