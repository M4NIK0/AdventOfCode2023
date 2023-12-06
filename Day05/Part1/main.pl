use strict;
use warnings;

sub set_corresponding_hash {
    my (%dic, @numbers) = @_;

    # print numbers
    print("Numbers: ", $numbers[0], " ", $numbers[1], " ", $numbers[2], "\n");
    
    # print keys
    print("Keys: ");
    foreach my $key (keys %dic) {
        print($key, " ", $dic{$key}, " ");
    }

    foreach my $i ($numbers[0] .. $numbers[0] + $numbers[2]) {
        %dic = (%dic, "" . $i => "" . $numbers[2]);
        print(%dic{"" . $i}, "\n");
    }
}

## read file
#print "File location> ";
#my $file = <>;
#
#chomp($file);
#
#open(FH, '<', $file) or die $!;
#
#my $file_content = "";
#
#while (<FH>) {
#    $file_content .= $_;
#}
#
#close(FH);
#
## split file contentby lines
#my @lines = split('\n', $file_content);
#
## print lines
#foreach my $line (@lines) {
#    print($line, "\n");
#}

my @seeds = ('-1' => 'seeds');

my %seed_to_soil = ('-1' => 'seed to soil');

my %soil_to_fertilizer = ('-1' => 'soil to fertilizer');

my %fertilizer_to_water = ('-1' => 'fertilizer to water');

my %water_to_light = ('-1' => 'water to light');

my %light_to_temp = ('-1' => 'light to temp');

my %temp_to_humidity = ('-1' => 'temp to humidity');

my %humidity_to_location = ('-1' => 'humidity to location');

my @test = (10, 50, 46);

set_corresponding_hash(%seed_to_soil, @test);

foreach my $key (keys %seed_to_soil) {
    print($key, " ", $seed_to_soil{$key}, "\n");
}

#for (my $i = 0; $i <= $#r; $i++) {
#    print($test[$i], " ");
#}

print("\n");
