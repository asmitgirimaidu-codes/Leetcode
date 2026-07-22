class Solution(object):
    def solveNQueens(self, n):
        """:type n: int
        :rtype: List[List[str]]
        """
        res = []
        col = set()
        positive_diag = set()  # (r + c)
        negative_diag = set()  # (r - c)

        board = [["."] * n for _ in range(n)]

        def backtrack(r):
            if r == n:
                res.append(["".join(row) for row in board])
                return

            for c in range(n):
                if c in col or (r + c) in positive_diag or (r - c) in negative_diag:
                    continue

                col.add(c)
                positive_diag.add(r + c)
                negative_diag.add(r - c)
                board[r][c] = "Q"

                backtrack(r + 1)

                col.remove(c)
                positive_diag.remove(r + c)
                negative_diag.remove(r - c)
                board[r][c] = "."

        backtrack(0)
        return res