# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.12)

if (TARGET seqan2::seqan2)
    return()
endif()

add_library(seqan2 INTERFACE)
target_include_directories(seqan2 INTERFACE SYSTEM
    ../../lib/seqan/include
)
target_compile_definitions(seqan2 INTERFACE -DSEQAN_HAS_ZLIB)
add_library(seqan2::seqan2 ALIAS seqan2)
