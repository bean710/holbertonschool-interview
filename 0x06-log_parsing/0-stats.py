#!/usr/bin/python3
"""Uses string parsing to get information from a data log"""
import sys
import re

codeSet = ("200", "301", "400", "401", "403", "404", "405", "500")

it = 0
fSize = 0
errCodes = {}

try:
    for line in sys.stdin:
        matches = re.match(
            "^[\d\.]+ - \[.+\] \"GET /projects/260 HTTP/1\.1\\\" (\d+) (\d+)",
            line)

        fSize += int(matches.group(2))
        if (matches.group(1) in errCodes):
            errCodes[matches.group(1)] += 1
        else:
            errCodes[matches.group(1)] = 1

        it += 1

        if (it == 10):
            it = 0
            print("File size: {}".format(fSize))

            for code in codeSet:
                if (code in errCodes):
                    print("{}: {}".format(code, errCodes[code]))

except KeyboardInterrupt:

    print("File size: {}".format(fSize))

    for code in codeSet:
        if (code in errCodes):
            print("{}: {}".format(code, errCodes[code]))
