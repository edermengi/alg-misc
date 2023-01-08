package algs4;

import edu.princeton.cs.algs4.Graph;
import edu.princeton.cs.algs4.GraphGenerator;
import edu.princeton.cs.algs4.Stack;

public class DFSNoRecursion {
    private final boolean[] marked;    // marked[v] = is there an s-v path?
    private int count;           // number of vertices connected to s

    public DFSNoRecursion(Graph g, Integer v) {
        marked = new boolean[g.V()];
        dfs(g, v);
    }

    private void dfs(Graph g, Integer v) {
        marked[v] = true;
        Stack<Integer> stack = new Stack<>();
        push(stack, g.adj(v));

        while (!stack.isEmpty()) {
            Integer w = stack.pop();
            if (!marked[w]) {
                marked[w] = true;
                count++;
                push(stack, g.adj(w));
            }
        }
    }

    private <T> void push(Stack<T> s, Iterable<T> iter) {
        for (T i : iter) s.push(i);
    }

    public static void main(String[] args) {
        Graph g = GraphGenerator.simple(10, 5);
        System.out.println(g);

        DFSNoRecursion dfs = new DFSNoRecursion(g, 1);
        for (int i = 0; i < g.V(); i++) {
            if (dfs.marked[i]) {
                System.out.print(i + " -> ");
            }
        }
    }


}
