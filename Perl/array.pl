#!/usr/bin/perl

use strict;
use warnings;
use 5.010;
use Data::Dumper qw(Dumper);

my @names = ("Foo", "Bar", "Baz");
say Dumper \@names;

say $names[0];
say $#names;
my $data = @names;
say "array: ".$data;

foreach my $i (0 .. $#names) {
  say "$i - $names[$i]";
}

foreach my $i (@names) {
  say "$i";
}

push @names, 'Moo';

say Dumper \@names;

my $last_value = pop @names;
say "Last: $last_value";
say Dumper \@names;

my $first_value = shift @names;
say "First: $first_value";
say Dumper \@names;
