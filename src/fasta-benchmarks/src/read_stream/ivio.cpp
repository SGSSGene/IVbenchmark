// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include "Result.h"

#include <cassert>
#include <fstream>
#include <ivio/fasta/reader.h>
#include <utils/dna5_rank_view.h>

auto ivio_bench(std::ifstream& stream, bool compressed) -> Result {
    Result result;

    auto reader = ivio::fasta::reader{{.input = stream, .compressed = compressed}};
    for (auto && [id, seq] : reader) {
        for (auto c : seq | dna5_rank_view) {
            result.ctChars[c] += 1;
        }
    }
    return result;
}
