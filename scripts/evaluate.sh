#!/usr/bin/bash
# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------
cd "$(dirname "$0")"

DATA=data


#########
# BAM
#########
methods=(seqan2 seqan3 io2 ivio)
files=(${DATA}/sampled.bam)

source run-benchmark.sh bam read

#########
# BCF
#########
methods=(bio ivio)
files=(${DATA}/sampled.bcf)

source run-benchmark.sh bcf read

source run-benchmark.sh bcf copy

#########
# FAIDX
#########
methods=(ivio)
files=(${DATA}/illumina.fa ${DATA}/hg38.fa)

source run-benchmark.sh faidx read

#########
# FASTA
#########
methods=(seqan2 seqan3 io2 bio seqtk ivio ivio_mt direct extreme)
files=(${DATA}/illumina.fa ${DATA}/illumina.fa.gz ${DATA}/hg38.fa ${DATA}/hg38.fa.gz)

source run-benchmark.sh fasta read

source run-benchmark.sh fasta read_stream

files=(${DATA}/illumina.fa ${DATA}/hg38.fa)
source run-benchmark.sh fasta write

#########
# FASTQ
#########

methods=(seqan2 seqan3 bio ivio)
files=(${DATA}/reads.fq ${DATA}/reads.fq.gz)

source run-benchmark.sh fastq read

#########
# SAM
#########
methods=(seqan2 seqan3 io2 ivio)
files=(${DATA}/sampled.sam)

source run-benchmark.sh sam read

#########
# VCF
#########
methods=(seqan2 bio ivio)
files=(${DATA}/sampled.vcf)

source run-benchmark.sh vcf read

source run-benchmark.sh vcf copy
