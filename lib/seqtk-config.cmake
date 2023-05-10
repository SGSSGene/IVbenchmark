# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.12)

if (TARGET seqtk::seqtk)
    return()
endif()

add_library(seqtk INTERFACE)
target_include_directories(seqtk INTERFACE SYSTEM
    lib/seqtk
)
target_compile_definitions(seqtk INTERFACE)
add_library(seqtk::seqtk ALIAS seqtk)
