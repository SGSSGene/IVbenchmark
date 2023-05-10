cmake_minimum_required (VERSION 3.16)

project (bcf-benchmark VERSION 1.0.0)

find_package (SeqAn3 REQUIRED HINTS ../../lib)
find_package (IVio REQUIRED HINTS ../../lib/IVio)
find_package (SeqAn2 REQUIRED HINTS ../../lib)
find_package (seqtk REQUIRED HINTS ../../lib)
find_package (biocpp-all REQUIRED HINTS ../../lib)
find_package (io2 REQUIRED HINTS ../../lib/io2)

add_executable(bcf-benchmark-read
    src/read/main.cpp
    src/read/ivio.cpp
    src/read/bio.cpp
)
target_link_libraries(bcf-benchmark-read
    biocpp::core
    biocpp::io
    io2::io2
    ivio::ivio
    seqan2::seqan2
    seqan3::seqan3
    seqtk::seqtk
)
add_executable(bcf-benchmark-copy
    src/copy/main.cpp
    src/copy/ivio.cpp
    src/copy/seqan2.cpp
    src/copy/bio.cpp
)
target_link_libraries(bcf-benchmark-copy
    biocpp::core
    biocpp::io
    io2::io2
    ivio::ivio
    seqan2::seqan2
    seqan3::seqan3
    seqtk::seqtk
)
