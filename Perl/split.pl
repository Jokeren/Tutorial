#!/usr/bin/perl

my $str = "root:*:0:0:System Administrator:/var/root:/bin/sh";
my ($username, $real_name) = (split /:/, $str)[0, 4];
print "$username\n";
print "$real_name\n";
