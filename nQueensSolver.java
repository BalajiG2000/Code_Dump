public class NQueensSolver {
    public static void main(String... args) {
        int n = 4;
		if (args.length == 1) {
			n = new java.util.Scanner(args[0]).nextInt();
		}
			
        int[] Q = new int[n + 1];
		System.out.println("SOLUTIONS: ");
        recursiveNQueens(Q, 1);
		
		Q = new int[n + 1];
		count = 0;
		System.out.println("\n\nTRACING BACKTRACK: ");
		recursiveNQueensShowingBackTrack(Q, 1);
    }
	
	public static int count = 0;

    public static void recursiveNQueens(int []Q, int r) {
        int n = Q.length - 1;
		if (r == n + 1) {
            count++;
			System.out.println("Solution " + count + ":");
			printBoard(Q, '*', r - 1);
        } else {
            for (int j = 1; j <= n; j++) {
                boolean isLegal = true;
                for (int i = 1; i < r; i++) {
                    if ((Q[i] == j) || (Q[i] == j + r - i) || (Q[i] == j - r + i)) {
                        isLegal = false;
						break;
                    }
                }
				if (isLegal) {
					Q[r] = j;
					recursiveNQueens(Q, r + 1);
				}
			}
        }
    }

	public static void recursiveNQueensShowingBackTrack(int []Q, int r) {
        int n = Q.length - 1;
		if (r <= n) {
			Q[r] = 0;
			printBoard(Q, '+', r);
		}
        if (r == n + 1) {
            count++;
			System.out.println("Solution " + count + ":");
			printBoard(Q, '*', r - 1);
        } else {
			boolean movedForward = false;
            for (int j = 1; j <= n; j++) {
                boolean isLegal = true;
                for (int i = 1; i < r; i++) {
                    if ((Q[i] == j) || (Q[i] == j + r - i) || (Q[i] == j - r + i)) {
                        isLegal = false;
						break;
                    }
                }
				if (isLegal) {
					Q[r] = j;
					recursiveNQueensShowingBackTrack(Q, r + 1);
					movedForward = true;
				} 
			}
			if (!movedForward) {
				System.out.println("Backtracking from: ");
				printBoard(Q, '-', r);
			}
        }
    }
		
    public static void printBoard(int[] Q, char symbol, int r) {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j < Q.length; j++) {
                System.out.print(Q[i] == j ? "Q" : symbol);
            }
            System.out.println();
        }
        System.out.println();
    }
}
