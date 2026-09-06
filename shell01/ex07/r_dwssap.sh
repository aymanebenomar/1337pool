cat /etc/passwd | grep -v '^#' | awk -F: 'NR % 2 == 0 {print $1}' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ',' | sed 's/,$/./; s/,/, /g'
