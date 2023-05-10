cmake_minimum_required (VERSION 3.16)

project (fasta-benchmark VERSION 1.0.0)

find_package (SeqAn3 REQUIRED HINTS ../../lib)
find_package (IVio REQUIRED HINTS ../../lib/IVio)
find_package (SeqAn2 REQUIRED HINTS ../../lib)
find_package (seqtk REQUIRED HINTS ../../lib)
find_package (biocpp-all REQUIRED HINTS ../../lib)
find_package (io2 REQUIRED HINTS ../../lib/io2)

add_executable(fasta-benchmark-read
    src/read/main.cpp
    src/read/ivio_mt.cpp
    src/read/seqan3.cpp
    src/read/ivio.cpp
    src/read/seqtk.cpp
    src/read/seqan2.cpp
    src/read/io2.cpp
    src/read/bio.cpp
    src/read/direct.cpp
    src/read/extreme.cpp
)
target_link_libraries(fasta-benchmark-read
    biocpp::core
    biocpp::io
    io2::io2
    ivio::ivio
    seqan2::seqan2
    seqan3::seqan3
    seqtk::seqtk
)
add_executable(fasta-benchmark-write
    src/write/main.cpp
    src/write/seqan3.cpp
    src/write/ivio.cpp
    src/write/seqan2.cpp
)
target_link_libraries(fasta-benchmark-write
    biocpp::core
    biocpp::io
    io2::io2
    ivio::ivio
    seqan2::seqan2
    seqan3::seqan3
    seqtk::seqtk
)

add_executable(fasta-benchmark-read_stream
    src/read_stream/main.cpp
    src/read_stream/seqan3.cpp
    src/read_stream/ivio.cpp
    src/read_stream/seqan2.cpp
    src/read_stream/io2.cpp
    src/read_stream/bio.cpp
)
target_link_libraries(fasta-benchmark-read_stream
    biocpp::core
    biocpp::io
    io2::io2
    ivio::ivio
    seqan2::seqan2
    seqan3::seqan3
    seqtk::seqtk
)
