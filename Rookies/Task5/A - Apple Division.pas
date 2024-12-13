program main;

uses Math;

type
  TIntArray = array of Int64;

function f(ind, a, b, n: Int64; arr: TIntArray): Int64;
begin
  if ind = n then
    Exit(Abs(a - b));

  f := Min(
    f(ind + 1, a + arr[ind], b, n, arr),
    f(ind + 1, a, b + arr[ind], n, arr)
  );
end;

var
  n, i: Int64;
  arr: TIntArray;
begin
  readln(n);

  SetLength(arr, n);
  for i := 0 to n - 1 do
    read(arr[i]);

  writeln(f(0, 0, 0, n, arr));
end.

