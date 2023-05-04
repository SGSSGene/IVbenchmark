cmake_minimum_required (VERSION 3.16)

project (fastq-benchmark VERSION 1.0.0)

find_package (SeqAn3 REQUIRED HINTS ../../lib/seqan3/build_system)
find_package (IVio REQUIRED HINTS ../../lib/IVio)
find_package (SeqAn2 REQUIRED HINTS ../../lib)
find_package (seqtk REQUIRED HINTS ../../lib)
find_package (biocpp-all REQUIRED HINTS ../../lib)
find_package (io2 REQUIRED HINTS ../../lib/io2)

add_executable(fastq-benchmark-read
    src/read/main.cpp
    src/read/seqan3.cpp
    src/read/ivio.cpp
    src/read/seqan2.cpp
    src/read/bio.cpp
)
target_link_libraries(fastq-benchmark-read
    biocpp::core
    biocpp::io
    io2::io2
    ivio::ivio
    seqan2::seqan2
    seqan3::seqan3
    seqtk::seqtk
)
