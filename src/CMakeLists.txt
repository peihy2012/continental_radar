aux_source_directory(. DIR_SRCS)
# aux_source_directory(src SRCS)
include_directories(inc)
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
# set(DIR_SRCS ${SRCS})

add_executable(long_range_radar_driver 
    ${DIR_SRCS}
    src/long_range_radar.cc
)
# target_link_libraries(Demo MathFunctions)