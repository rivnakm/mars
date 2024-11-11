add_library(mars-lib STATIC src/tokenizer.cpp)

target_include_directories(mars-lib PRIVATE include)
target_link_libraries(mars-lib PRIVATE ${LLVM_LIBS})
set_target_properties(mars-lib PROPERTIES OUTPUT_NAME "mars")
