# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.16)

project (ivio-benchmark VERSION 1.0.0)

find_package (SeqAn3 REQUIRED PATHS lib/seqan3/build_system)
find_package (IVio REQUIRED PATHS lib/IVio)
find_package (SeqAn2 REQUIRED PATHS lib)
find_package (seqtk REQUIRED PATHS lib)
find_package (biocpp-all REQUIRED PATHS lib)
find_package (io2 REQUIRED PATHS lib/io2)

add_subdirectory(src/utils)
add_subdirectory(src/bam-benchmarks)
add_subdirectory(src/bcf-benchmarks)
add_subdirectory(src/faidx-benchmarks)
add_subdirectory(src/fasta-benchmarks)
add_subdirectory(src/fastq-benchmarks)
add_subdirectory(src/sam-benchmarks)
add_subdirectory(src/vcf-benchmarks)

file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/scripts/evaluate.sh      ${CMAKE_CURRENT_BINARY_DIR}/evaluate.sh SYMBOLIC)
file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/scripts/run-benchmark.sh ${CMAKE_CURRENT_BINARY_DIR}/run-benchmark.sh SYMBOLIC)
file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/scripts/prepareFiles.sh ${CMAKE_CURRENT_BINARY_DIR}/prepareFiles.sh SYMBOLIC)

#add_custom_target(prepare_data ./prepareFiles.sh)
add_custom_target(prepare_data ALL)
add_custom_command(TARGET prepare_data PRE_BUILD
   COMMAND prepareFiles.sh
)
