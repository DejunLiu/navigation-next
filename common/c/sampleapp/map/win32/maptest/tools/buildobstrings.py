#
# buildobstrings.py: created 2005/11/11 by Dima Dorfman.
#
# Copyright (C) 2005 Networks In Motion, Inc. All rights reserved.
#
# The information contained herein is confidential and proprietary to
# Networks In Motion, Inc., and is considered a trade secret as
# defined in section 499C of the California Penal Code. Use of this
# information by anyone other than authorized employees of Networks
# In Motion is granted only under a written non-disclosure agreement
# expressly prescribing the scope and manner of such use.
#

"""Build obstrings.[ch] files.

The obstrings module contains obfuscated string constants. They are
accessed through the obstrings structure, which is filled in by the
loadobstrings function (also generated by this program).

The input file has the format:

  key value

where the key is the name of the object to be generated and value is a
string (no newlines). Values will be obfuscated by removing the high
bit. Any other character is valid as long as its high bit is clear.

"""

__all__ = ['main']

import sys

def main():

    global hp, cp
    hfile = open('obstrings.h', 'wc')
    cfile = open('obstrings.c', 'wc')
    hp = hfile.write
    cp = cfile.write

    hp('#ifndef OBSTRINGS_H\n#define OBSTRINGS_H\n')

    cp('#include "bitcomp.h"\n')
    cp('#include "obstrings.h"\n')

    hp('\nstruct obstrings {\n')
    cp('\n')
    keys = []
    for line in sys.stdin:
        s = line.rstrip('\n').split(' ', 2)
        assert len(s) > 2
        cond, key, value = s
        if cond == '*':
			cond = None
        output(cond, key, value)
        keys.append((cond, key))
    hp('};\n')

    hp('\nvoid loadobstrings(struct obstrings *);\n')
    hp('\n#endif\n')

    cp('\nvoid\nloadobstrings(struct obstrings *obs)\n')
    cp('{\n')
    for cond, key in keys:
        target = 'obs->%s' % key
        source = 'obstring_%s' % key
        if cond:
            cp('#ifdef %s\n' % cond)
        cp('\tbitdecomp(%s, sizeof(%s), %s, sizeof(%s));\n' % (
            target, target, source, source))
        if cond:
            cp('#endif\n')
    cp('}\n')

def output(cond, key, value):
    if cond:
        cp('#ifdef %s\n' % cond)
    cp('static const unsigned char obstring_%s[] = {\n\t' % key)
    outputvalue(value)
    cp('\n};\n')
    if cond:
        cp('#endif\n')
        hp('#ifdef %s\n' % cond)
    hp('\tchar %s[%d];\n' % (key, len(value) + 1))
    if cond:
        hp('#endif\n')

def outputvalue(s):
    x = bitcompress(s)
    for i, c in enumerate(octets(x)):
        if i > 0:
            cp(',')
            if i % 14 == 0:
                cp('\n\t')
            else:
                cp(' ')
        cp('%3d' % c)

def octets(x):
    while x > 0:
        yield x & 0xff
        x >>= 8

def bitcompress(s):
    return reduce(lambda a, x: a << 7 | (ord(x) & 0x7f), s, 0)

if __name__ == '__main__':
    main()
