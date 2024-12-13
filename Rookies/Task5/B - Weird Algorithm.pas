program main;

var
  n: Int64;

begin
  ReadLn(n);
  
  while n <> 1 do
  begin
    Write(n, ' ');
    if n mod 2 = 1 then
      n := 3 * n + 1
    else
      n := n div 2;
  end;
  
  WriteLn(1);
end.

