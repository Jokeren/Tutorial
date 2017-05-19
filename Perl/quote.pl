#!/usr/bin/perl

my $name = 'Foo';
print 'Hello $name, how are you?\n';

my $name = 'Foo';
my $time  = "today";
print "Hello $name,\nhow are you $time?\n";

my $name = 'foo';
print qq(The "name" is "$name"\n);

print qq(The (name) is "$name"\n);

print qq{The )name( is "$name"\n};
