cmake_minimum_required (VERSION 3.16)

project (ivio-benchmark VERSION 1.0.0)

add_subdirectory(src/bam-benchmarks)
add_subdirectory(src/bcf-benchmarks)
add_subdirectory(src/faidx-benchmarks)
add_subdirectory(src/fasta-benchmarks)
add_subdirectory(src/fastq-benchmarks)
add_subdirectory(src/sam-benchmarks)
add_subdirectory(src/vcf-benchmarks)
