// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include <cassert>
#include <fstream>
#include <vector>
#include <ivio/fasta/writer.h>
#include <utils/dna5_rank_view.h>
#include <utils/rank_to_dna5.h>


void ivio_bench(std::filesystem::path file, std::vector<std::tuple<std::string, std::vector<uint8_t>>> const& data) {
    auto writer = ivio::fasta::writer{{.output = file}};
    std::string seq_as_str;
    for (auto const& [seq_id, seq] : data) {
        seq_as_str.resize(seq.size());
        rank_to_dna5(seq, seq_as_str);
        writer.write({.id  = seq_id,
                      .seq = seq_as_str});
    }
}
