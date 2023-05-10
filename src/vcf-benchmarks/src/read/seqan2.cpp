// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include "Result.h"

#include <filesystem>
#include <seqan/vcf_io.h>
#include <utils/dna5_rank_view.h>

using namespace seqan;

auto seqan2_bench(std::filesystem::path file) -> Result {
    Result result;

    VcfFileIn fileIn(file.c_str());

    VcfHeader header;
    readHeader(header, fileIn);

    VcfRecord record;
    while (!atEnd(fileIn)) {
        result.l += 1;
        readRecord(record, fileIn);
        result.ct += record.beginPos+1;
        for (auto c : record.ref | dna5_rank_view) {
            result.ctChars[c] += 1;
        }
        result.bytes += length(record.ref);
    }

    return result;
}
