package main

func find(dsu []int, v int) int {
    if dsu[v] == -1 {
        return v
    }
    dsu[v] = find(dsu, dsu[v])
    return dsu[v]
}

func findRedundantConnection(edges [][]int) []int {
    n := len(edges)
    dsu := make([]int, n+1)
    for i := 0; i <= n; i++ {
        dsu[i] = -1
    }

    for _, edge := range edges {
        parentX := find(dsu, edge[0])
        parentY := find(dsu, edge[1])

        if parentX == parentY {
            return edge
        } else {
            dsu[parentX] = parentY
        }
    }

    return []int{0, 0}
}
