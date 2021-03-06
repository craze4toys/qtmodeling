#!/usr/bin/env perl
#############################################################################
##
## Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
## Contact: http://www.qt-project.org/legal
##
## This file is part of the QtModeling project of the Qt Toolkit.
##
## $QT_BEGIN_LICENSE:LGPL$
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and Digia.  For licensing terms and
## conditions see http://qt.digia.com/licensing.  For further information
## use the contact form at http://qt.digia.com/contact-us.
##
## GNU Lesser General Public License Usage
## Alternatively, this file may be used under the terms of the GNU Lesser
## General Public License version 2.1 as published by the Free Software
## Foundation and appearing in the file LICENSE.LGPL included in the
## packaging of this file.  Please review the following information to
## ensure the GNU Lesser General Public License version 2.1 requirements
## will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
##
## In addition, as a special exception, Digia gives you certain additional
## rights.  These rights are described in the Digia Qt LGPL Exception
## version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
##
## GNU General Public License Usage
## Alternatively, this file may be used under the terms of the GNU
## General Public License version 3.0 as published by the Free Software
## Foundation and appearing in the file LICENSE.GPL included in the
## packaging of this file.  Please review the following information to
## ensure the GNU General Public License version 3.0 requirements will be
## met: http://www.gnu.org/copyleft/gpl.html.
##
##
## $QT_END_LICENSE$
##
############################################################################/

use strict;
use warnings;

use Getopt::Std;
use File::Path qw(make_path);
use XML::XPath;
use Template;

my %options=(); 
getopt("oip",\%options);

my $tt = Template->new(INTERPOLATE  => 1, INCLUDE_PATH => 'templates/');

my $xmi = XML::XPath->new(filename => $options{i});
my $namespace = $xmi->findvalue('//uml:Package/@name');

if ($namespace eq "") {
    $namespace = $xmi->findvalue('//uml:Profile/@name');
}

make_path($options{o}."/".$namespace."/"."qobjects");

{
local *STDOUT;

my $globalHeader = "qt".lc($namespace)."global.h";
open STDOUT, '>', $options{o}."/".$namespace."/".$globalHeader;
if ($tt->process('global.h', {
    namespace => $namespace,
}) ne 1) { print $tt->error(); }
close STDOUT;

open STDOUT, '>', $options{o}."/".$namespace."/qt".lc($namespace)."namespace.h";
if ($tt->process('modulenamespace.h', {
    xmi => $options{i},
    namespace => $namespace,
}) ne 1) { print $tt->error(); }
close STDOUT;

open STDOUT, '>', $options{o}."/".$namespace."/qt".lc($namespace)."namespace.cpp";
if ($tt->process('modulenamespace.cpp', {
    xmi => $options{i},
    namespace => $namespace,
}) ne 1) { print $tt->error(); }
close STDOUT;

open STDOUT, '>', $options{o}."/".$namespace."/".lc($namespace).".pri";
if ($tt->process('module.pri', {
    xmi => $options{i},
    namespace => $namespace,
}) ne 1) { print $tt->error(); }
close STDOUT;

open STDOUT, '>', $options{o}."/".$namespace."/".lc($namespace).".pro";
if ($tt->process('module.pro', {
    namespace => $namespace,
}) ne 1) { print $tt->error(); }
close STDOUT;

}

my $classset = $xmi->find('//packagedElement[@xmi:type=\'uml:Class\']');
if ($classset->size() == 0) {
    $classset = $xmi->find('//packagedElement[@xmi:type=\'uml:Stereotype\']');
}
foreach my $class ($classset->get_nodelist) {
    my $className = $class->findvalue('@name');
    die "could not fork" unless defined(my $pid = fork);
    unless ($pid) { #child execs
        exec "./generate-class.pl", "-i", $options{i}, "-o", $options{o}, "-c", $className;
        die "exec of generate-class.pl failed";
    }
    my $buf;
    do {
        sleep(1);
        $buf = `ps -ef | grep generate-class | grep -v grep | wc -l`;
    } while ($buf >= $options{p});
}

