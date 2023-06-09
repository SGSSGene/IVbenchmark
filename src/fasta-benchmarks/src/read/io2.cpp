// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include "Result.h"

#include <io2/seq_io_reader.h>

auto io2_bench(std::filesystem::path _file) -> Result {
    Result result;

    auto reader = io2::seq_io::reader {
        .input = _file,
//        .alphabet = sgg_io::type<seqan3::dna4>, // by default dna5
    };

    for (auto && [id, seq, qual] : reader) {
        for (auto c : seq) {
            result.ctChars[c.to_rank()] += 1;
        }
    }
    std::swap(result.ctChars[3], result.ctChars[4]);
    return result;
}
