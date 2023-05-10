cmake_minimum_required (VERSION 3.16)

project (faidx-benchmark VERSION 1.0.0)

add_executable(faidx-benchmark-read
    src/read/main.cpp
    src/read/ivio.cpp
)
target_link_libraries(faidx-benchmark-read
    biocpp::core
    biocpp::io
    io2::io2
    ivio::ivio
    seqan2::seqan2
    seqan3::seqan3
    seqtk::seqtk
)
