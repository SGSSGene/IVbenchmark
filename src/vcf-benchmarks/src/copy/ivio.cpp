// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include <ivio/vcf/reader.h>
#include <ivio/vcf/writer.h>

void ivio_bench(std::filesystem::path pathIn, std::filesystem::path pathOut) {
    auto reader = ivio::vcf::reader{{.input = pathIn}};


    auto writer = ivio::vcf::writer{{.output = pathOut,
                                     .header = reader.header() }};

    for (auto record_view : reader) {
        writer.write(record_view);
    }
}
