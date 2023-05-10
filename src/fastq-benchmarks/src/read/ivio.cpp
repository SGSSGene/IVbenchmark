// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include "Result.h"

#include <cassert>
#include <ivio/fastq/reader.h>
#include <utils/dna5_rank_view.h>

auto ivio_bench(std::filesystem::path file) -> Result {
    Result result;

    for (auto && record : ivio::fastq::reader{{.input = file}}) {
        for (auto c : record.seq | dna5_rank_view) {
            assert(c < result.ctChars.size());
            result.ctChars[c] += 1;
        }
    }
    return result;
}
