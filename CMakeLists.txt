cmake_minimum_required (VERSION 3.16)

project (ivio-benchmark VERSION 1.0.0)

add_subdirectory(src/bam-benchmarks)
add_subdirectory(src/bcf-benchmarks)
add_subdirectory(src/faidx-benchmarks)
add_subdirectory(src/fasta-benchmarks)
add_subdirectory(src/fastq-benchmarks)
add_subdirectory(src/sam-benchmarks)
add_subdirectory(src/vcf-benchmarks)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/scripts/evaluate.sh      DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/scripts/run-benchmark.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
