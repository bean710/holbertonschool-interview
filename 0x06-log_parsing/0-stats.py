#!/usr/bin/python3
"""Uses string parsing to get information from a data log"""
import sys
import re


def print_logs():
    print("File size: {}".format(fSize))

    for code in codeSet:
        if (code in errCodes):
            print("{}: {}".format(code, errCodes[code]))


if __name__ == "__main__":
    codeSet = ("200", "301", "400", "401", "403", "404", "405", "500")

    it = 0
    fSize = 0
    errCodes = {}

    try:
        for line in sys.stdin:
            matches = re.match(
                "^[\d\.]+ - \[.+\] \"GET /\w+/260 HTTP/1\.1\\\" (\d+) (\d+)",
                line)

            fSize += int(matches.group(2))
            if (matches.group(1) in errCodes):
                errCodes[matches.group(1)] += 1
            else:
                errCodes[matches.group(1)] = 1

            it += 1

            if (it == 10):
                it = 0
                print_logs()

    except KeyboardInterrupt:
        print_logs()

    print_logs()
