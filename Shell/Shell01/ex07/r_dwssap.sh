#!/bin/sh

cat /etc/passwd | sed 's/#.*//' | sed  /^$/d | tail -n+2 | sed -n 'p;n' | cut -d ":" -f1 | rev | sort -r | tail -n +$FT_LINE1 | head -n $(($FT_LINE2-$FT_LINE1+1)) | tr "\n" "," | sed 's/,$/./' | sed 's/,/, /g' | tr -d '\n'
