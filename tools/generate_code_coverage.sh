#!/usr/bin/sh
gcovr -j12 --delete --print-summary -f "src/*" --html-details --html-title CodeCoverage --html build/coverage.html build/