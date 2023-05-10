cmake_minimum_required (VERSION 3.16)

set(FILES
    hg38.fa.gz
    hg38.fa.fai.gz
    illumina.fa.gz
    illumina.fa.fai
    reads.fq.gz
    sampled.bam
    sampled.bcf
    sampled.sam.gz
    sampled.vcf.gz
)

foreach(file ${FILES})
    file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/${file} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endforeach()

add_custom_target(prepare_data ALL)
add_custom_command(TARGET prepare_data PRE_BUILD
   COMMAND ${CMAKE_CURRENT_BINARY_DIR}/../prepareFiles.sh ${CMAKE_CURRENT_BINARY_DIR}
)
