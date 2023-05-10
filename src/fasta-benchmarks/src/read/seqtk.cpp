// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include "Result.h"

#include <filesystem>
#include <kseq.h>
#include <utils/dna5_rank_view.h>
#include <zlib.h>

KSEQ_INIT(gzFile, gzread)

auto seqtk_bench(std::filesystem::path file) -> Result {
    Result result;

    gzFile fp = gzopen(file.c_str(), "r");
    kseq_t* kseq = kseq_init(fp);
    while (kseq_read(kseq) >= 0) {
//        auto name = std::string_view{kseq->name.s, kseq->name.l};
        auto seq = std::string_view{kseq->seq.s, kseq->seq.l};
        for (auto c : seq | dna5_rank_view) {
            result.ctChars[c] += 1;
        }
    }
    kseq_destroy(kseq);
    gzclose(fp);
    return result;
}
