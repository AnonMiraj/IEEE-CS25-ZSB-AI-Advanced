<?php

/*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

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


function pairs($k, $arr) {

    sort($arr);
    $ans = 0;
    $n= sizeof($arr);

    for ($i = 0; $i < $n; $i++) {
        $st = lower_bound($arr, $i + 1, $n, $k + $arr[$i]);
        $en = upper_bound($arr, $i + 1, $n, $k + $arr[$i]);

        $ans += $en - $st;
    }

    return $ans;
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$first_multiple_input = explode(' ', rtrim(fgets(STDIN)));

$n = intval($first_multiple_input[0]);

$k = intval($first_multiple_input[1]);

$arr_temp = rtrim(fgets(STDIN));

$arr = array_map('intval', preg_split('/ /', $arr_temp, -1, PREG_SPLIT_NO_EMPTY));

$result = pairs($k, $arr);

fwrite($fptr, $result . "\n");

fclose($fptr);

