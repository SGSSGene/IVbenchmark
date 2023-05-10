// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include "Result.h"

#include <seqan/seq_io.h>

using namespace seqan;

auto seqan2_bench(std::ifstream& stream, bool compressed) -> Result {
    Result result;
    if (compressed) return result;

    SeqFileIn seqFileIn(stream);

    CharString id;
    Dna5String seq;

    while(!atEnd(seqFileIn)) {
        readRecord(id, seq, seqFileIn);
        for (auto c : seq) {
            result.ctChars[c] += 1;
        }
    }
    return result;
}
