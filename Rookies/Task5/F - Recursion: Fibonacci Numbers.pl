my $n = <STDIN>;
chomp($n);
my @v = (0, 1);

for my $i (2..39) {
    $v[$i] = $v[$i - 2] + $v[$i - 1];
}
print $v[$n], "\n";
