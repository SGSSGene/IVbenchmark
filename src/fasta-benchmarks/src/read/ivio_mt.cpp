// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include "Result.h"

#include <ivio/fasta/reader_mt.h>
#include <utils/dna5_rank_view.h>

auto ivio_mt_bench(std::filesystem::path file) -> Result {
    Result result;

    auto reader = ivio::fasta::reader_mt{{.input = file}};
    for (auto && [id, seq] : reader) {
        for (auto c : seq | dna5_rank_view) {
            result.ctChars[c] += 1;
        }
    }
    return result;
}
