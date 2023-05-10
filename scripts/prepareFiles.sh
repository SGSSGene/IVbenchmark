#!/usr/bin/bash

if [ ! -e data.tgz ]; then
    echo "Downloading test data"
    curl https://gottliebtfreitag.de/bioinformatic/2023.05.10-test.data.tgz -o data.tgz
fi
if [ ! "$(md5sum data.tgz)" != "f24da3c23f433f8b4e9682c37c8993fa" ]; then
    echo "error downloading test data"
    exit 1
fi

if [ ! -d data ]; then
    echo "Unpacking test data"
    tar -xvzf data.tgz
fi

files=(hg38.fa illumina.fa illumina.fa.fai reads.fq sampled.sam sampled.vcf)
for f in ${files[@]}; do
    if [ ! -e "${f}" ]; then
        echo "preparing ${f}..."
        gunzip -c -k data/${f}.gz > data/${f}
    fi
done
