file(GLOB CPPS "*.cpp")

file(GLOB HPPS "*.h")


include_directories(../gtest/gtest/include)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})


add_executable(mytest ${CPPS} ${HPPS})

target_link_libraries(mytest gtest code)