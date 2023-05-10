// -----------------------------------------------------------------------------------------------------
// Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
// Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
// This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
// shipped with this file.
// -----------------------------------------------------------------------------------------------------
#include "Result.h"

#include <ivio/detail/mmap_reader.h>

auto extreme_bench(std::filesystem::path path) -> Result {
    auto reader = ivio::mmap_reader(path);

    std::array<int, 256> ctChars{};

    auto [ptr, size] = reader.read(std::numeric_limits<uint64_t>::max());
    auto buffer = std::string_view{ptr, size};

    size_t pos = buffer.find('>');
    if (pos != std::string_view::npos) {
        while (pos < size) {
            pos = buffer.find('\n', pos);
            if (pos == std::string_view::npos) break;
            if (++pos >= size) break;
            for(;pos < size and buffer[pos] != '>'; ++pos) {
                assert(pos < size);
                assert(buffer[pos] < 256);
                ctChars[buffer[pos]] += 1;
            }
        }
    }



    Result result;
    result.ctChars[0] = ctChars['A'] + ctChars['a'];
    result.ctChars[1] = ctChars['C'] + ctChars['c'];
    result.ctChars[2] = ctChars['G'] + ctChars['g'];
    result.ctChars[3] = ctChars['T'] + ctChars['t'];
    result.ctChars[4] = ctChars['N'] + ctChars['n'];
    return result;
}
