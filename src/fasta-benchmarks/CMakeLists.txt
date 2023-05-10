# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.16)

project (fasta-benchmark VERSION 1.0.0)

add_executable(fasta-benchmark-read
    src/read/main.cpp
    src/read/ivio_mt.cpp
    src/read/seqan3.cpp
    src/read/ivio.cpp
    src/read/seqtk.cpp
    src/read/seqan2.cpp
    src/read/io2.cpp
    src/read/bio.cpp
    src/read/direct.cpp
    src/read/extreme.cpp
)
target_link_libraries(fasta-benchmark-read utils)

add_executable(fasta-benchmark-write
    src/write/main.cpp
    src/write/seqan3.cpp
    src/write/ivio.cpp
    src/write/seqan2.cpp
)
target_link_libraries(fasta-benchmark-write utils)

add_executable(fasta-benchmark-read_stream
    src/read_stream/main.cpp
    src/read_stream/seqan3.cpp
    src/read_stream/ivio.cpp
    src/read_stream/seqan2.cpp
    src/read_stream/io2.cpp
    src/read_stream/bio.cpp
)
target_link_libraries(fasta-benchmark-read_stream utils)
