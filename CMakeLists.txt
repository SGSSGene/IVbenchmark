# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.16)

project (ivio-benchmark VERSION 1.0.0)

find_package (SeqAn3 REQUIRED HINTS lib/seqan3/build_system)
find_package (IVio REQUIRED HINTS lib/IVio)
find_package (SeqAn2 REQUIRED HINTS lib)
find_package (seqtk REQUIRED HINTS lib)
find_package (biocpp-all REQUIRED HINTS lib)
find_package (io2 REQUIRED HINTS lib/io2)

add_subdirectory(src/utils)
add_subdirectory(src/bam-benchmarks)
add_subdirectory(src/bcf-benchmarks)
add_subdirectory(src/faidx-benchmarks)
add_subdirectory(src/fasta-benchmarks)
add_subdirectory(src/fastq-benchmarks)
add_subdirectory(src/sam-benchmarks)
add_subdirectory(src/vcf-benchmarks)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/scripts/evaluate.sh      DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/scripts/run-benchmark.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
