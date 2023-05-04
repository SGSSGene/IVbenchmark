#!/usr/bin/python

import iv2py as iv
import numpy
import sys
from collections import Counter

res = Counter()
for record in iv.fasta.reader(file=sys.argv[1]):
    res += Counter(record.seq)
