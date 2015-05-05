#cat file.txt | awk '{if(NR==10){print $0}}'
tail -n +10 file.txt | head -n1