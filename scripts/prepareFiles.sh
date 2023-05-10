#!/usr/bin/bash


cd $1

files=(hg38.fa hg38.fa.fai illumina.fa reads.fq sampled.sam sampled.vcf)
for f in ${files[@]}; do
    echo "preparing ${f}..."
    if [ ! -e "${f}" ]; then
        gunzip -c -k ${f}.gz > ${f}
    fi
done
