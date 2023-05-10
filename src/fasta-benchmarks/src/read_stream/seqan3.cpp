// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include "Result.h"

#include <seqan3/io/sequence_file/all.hpp>

auto seqan3_bench(std::ifstream& stream, bool compressed) -> Result {
    Result result;

    auto reader = seqan3::sequence_file_input{stream, seqan3::format_fasta{}};

    //!TODO this should really be [id, seq, qual], seqan3 is backwards
    for (auto && [seq, id, qual] : reader) {
        for (auto c : seq) {
            result.ctChars[c.to_rank()] += 1;
        }
    }
    std::swap(result.ctChars[3], result.ctChars[4]); // swap so N is on last place
    return result;
}
