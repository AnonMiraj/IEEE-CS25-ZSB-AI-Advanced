<?php
function solve() {
    fscanf(STDIN, "%d %d %d", $n, $l, $r);
    $v = array_map('intval', explode(' ', trim(fgets(STDIN))));

    sort($v);

    $ans = 0;

    for ($i = 0; $i < $n; $i++) {
        $st = lower_bound($v, $i + 1, $n, $l - $v[$i]);
        $en = upper_bound($v, $i + 1, $n, $r - $v[$i]);

        $ans += $en - $st;
    }

    echo $ans . "\n";
}

function lower_bound($arr, $start, $end, $value) {
    while ($start < $end) {
        $mid = intdiv($start + $end, 2);
        if ($arr[$mid] < $value) {
            $start = $mid + 1;
        } else {
            $end = $mid;
        }
    }
    return $start;
}

function upper_bound($arr, $start, $end, $value) {
    while ($start < $end) {
        $mid = intdiv($start + $end, 2);
        if ($arr[$mid] <= $value) {
            $start = $mid + 1;
        } else {
            $end = $mid;
        }
    }
    return $start;
}

$t = 1;
  fscanf(STDIN, "%d", $t);

while ($t--) {
    solve();
}

