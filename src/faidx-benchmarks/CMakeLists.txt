# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------
cmake_minimum_required (VERSION 3.16)

project (faidx-benchmark VERSION 1.0.0)

add_executable(faidx-benchmark-read
    src/read/main.cpp
    src/read/ivio.cpp
)
target_link_libraries(faidx-benchmark-read utils)
