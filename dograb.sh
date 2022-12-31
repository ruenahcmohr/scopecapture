#!/bin/bash

file="${1}.eps"
scopecapture /dev/ttyUSB0 $file
inkscape -f "$file" -w2048 -h1536 -e "${1}.png" 2>/dev/null
gimp "${1}.png" > /dev/null 2>/dev/null

exit 0
