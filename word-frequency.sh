cat words.txt | awk -F " " 'BEGIN{} {for(i=1;i<=NF;++i){CNT[$i]=CNT[$i]+1;}} END{for(k in CNT){print k,CNT[k]};}' | sort -rnk2