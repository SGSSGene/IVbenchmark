# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------

cmake_minimum_required (VERSION 3.12)

if (TARGET biocpp::core AND TARGET biocpp::io)
    return()
endif()

find_package (biocpp REQUIRED HINTS ${CMAKE_CURRENT_LIST_DIR}/biocpp-core/build_system)
find_package (biocpp_io REQUIRED HINTS ${CMAKE_CURRENT_LIST_DIR}/biocpp-io/build_system)
