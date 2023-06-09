#!/bin/bash
# -----------------------------------------------------------------------------------------------------
# Copyright (c) 2006-2023, Knut Reinert & Freie Universität Berlin
# Copyright (c) 2016-2023, Knut Reinert & MPI für molekulare Genetik
# This file may be used, modified and/or redistributed under the terms of the 3-clause BSD-License
# shipped with this file.
# -----------------------------------------------------------------------------------------------------

type="$1"

if [ -z "${type}" ]; then
    type="release"
fi


if [ "${type}" == "release" ]; then
    FLAGS="-march=native -O3 -DNDEBUG -s -fconcepts-diagnostics-depth=10 -Wall "
elif [ "${type}" == "debug" ]; then
    FLAGS="-O0 -ggdb -Wall"
fi
#FLAGS="-O0 -ggdb -fsanitize=address -Wall"
#FLAGS="-march=native -O3 -DNDEBUG -ggdb"


INCLUDES="-I . -I ../../lib/IVio/src/ \
    -isystem../../lib/io2/include \
    -DSEQAN_HAS_ZLIB  -isystem../../lib/seqan/include \
    -DBIOCPP_IO_HAS_ZLIB -isystem../../lib/biocpp-io/include \
                   -isystem../../lib/biocpp-core/include \
    -DSEQAN3_HAS_ZLIB -isystem../../lib/seqan3/include -isystem../../lib/sdsl-lite/include \
    -isystem../../lib/seqtk"
ARGS="-std=c++20 ${FLAGS} ${INCLUDES}"


# Building ivio library
for f in $(find ../../lib/IVio/src/ivio | grep .cpp\$); do
    g=$(echo $f | cut -b 11-)
    mkdir -p $(dirname obj/$g)
    g++ ${ARGS} -c $f -o obj/$g.o
done

build () {
    folder=$1
    target=$2
    # Building benchmark
    for f in $(find ${folder} | grep .cpp\$); do
        mkdir -p $(dirname obj/$f)
        g++ ${ARGS} -c $f -o obj/$f.o
    done
    g++ $(find obj/${folder} | grep \\\.o\$) $(find obj/IVio/src/ivio | grep \\\.o\$) -lz-ng -lz ${FLAGS} -o ${target}
}
