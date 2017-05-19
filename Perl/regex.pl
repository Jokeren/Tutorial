#!/usr/bin/perl

my $str = 'The black cat jumped from the green tree';
if ($str =~ m/cat/) {
  print "There is a cat\n";
}

if (not $str =~ m/dog/) {
  print "There is no dog\n";
}

if ($str =~ m/c[^x]t/) {
  print "approximate\n";
}
