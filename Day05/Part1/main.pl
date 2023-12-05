use strict;
use warnings;

my @test = (10, 50, 46);

my @r = (0..2);

for (my $i = 0; $i <= $#r; $i++) {
    print($test[$i], " ");
}

print("\n");

my $filename = '../input.txt';

open(FH, '<', $filename) or die $!;

my $file_content = "";

while (<FH>) {
    $file_content .= $_;
}

my @splitted = split('\n', $file_content);

foreach my $line (@splitted) {
    print($line, "\n\n");
}

close(FH);
