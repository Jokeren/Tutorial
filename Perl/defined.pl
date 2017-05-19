#!/usr/bin/perl

use strict;
use warnings;
use 5.010;

my $x;

# some code here that might set $x

if (defined $x) {
    say '$x is defined';
} else {
    say '$x is undef';
}

$x = 1;

if (defined $x) {
    say '$x is defined';
} else {
    say '$x is undef';
}
