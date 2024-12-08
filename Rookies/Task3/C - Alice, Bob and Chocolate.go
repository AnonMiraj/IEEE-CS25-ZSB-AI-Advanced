
package main

import (
        "bufio"
        "fmt"
        "os"
)

func solve() {
        var n int
        fmt.Scan(&n)

        v := make([]int, n)
        reader := bufio.NewReader(os.Stdin)
        for i := 0; i < n; i++ {
                fmt.Fscan(reader, &v[i])
        }

        atotal := 0
        btotal := 0
        a := 0
        b := 0

        p1 := 0
        p2 := n - 1

        for p1 <= p2 {
                if atotal <= btotal {
                        atotal += v[p1]
                        a++
                        p1++
                } else {
                        btotal += v[p2]
                        b++
                        p2--
                }
        }

        fmt.Println(a, b)
}

func main() {
        solve()
}

