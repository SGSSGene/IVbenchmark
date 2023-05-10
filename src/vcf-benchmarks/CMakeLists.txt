# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.16)

project (vcf-benchmark VERSION 1.0.0)

add_executable(vcf-benchmark-read
    src/read/main.cpp
    src/read/ivio.cpp
    src/read/seqan2.cpp
    src/read/bio.cpp
)
target_link_libraries(vcf-benchmark-read utils)

add_executable(vcf-benchmark-copy
    src/copy/main.cpp
    src/copy/ivio.cpp
    src/copy/seqan2.cpp
    src/copy/bio.cpp
)
target_link_libraries(vcf-benchmark-copy utils)
