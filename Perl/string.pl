#!/usr/bin/perl

use strict;
use warnings;
use 5.010;

my $x = 'Hello';
my $y = 'World';

my $z = $x . ' ' . $y;
print $x x 2 . $z . "\n";

use Scalar::Util qw(looks_like_number);

undef $z;
my $z = 3;
say $z;
undef $y;
my $y = "3.14";

if (looks_like_number($z) and looks_like_number($y)) {
  say $z + $y;
}

say $z . $y;

if (defined $y) {
  say "defined";
} else {
  say "NOT";
}

my $str = 'HeLlo';

say lc $str;      # hello
say uc $str;      # HELLO
say length $str;  # 5

my $str = "The black cat climbed the green tree";

say index $str, 'cat';             # 10
say index $str, 'dog';             # -1
say index $str, "The";             # 0
say index $str, "the";             # 22

my $str = "The black cat climbed the green tree";

say substr $str, 4, 5;                      # black

my $str = "The black cat climbed the green tree";
my $z = substr $str, 14, 7, "jumped from";
say $str;

my @names = ('Foo', 'Bar', 'Moo');
my $str = join ':', @names;
say $str;                       # Foo:Bar:Moo

my $data = join "-", $str, "names";
say $data;                      # Foo:Bar:Moo-names

$str = join '', @names, 'Baz';
say $str;                       # FooBarMooBaz

my @words = ('Foo', 'Bar', 'Baz');
my $people = scalar @words;
say $people;
