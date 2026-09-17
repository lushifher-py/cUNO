cmake_minimum_required( VERSION 3.15)
project(cUNO LANGUAGES C)


#core engine static library
add_library(unocore STATIC
    src/dealermanager/cards.c
    src/dealermanager/dynarr.c)
target_include_directories(unocore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)

#main executable
add_executable(unogame src/main.c)
target_link_libraries(unogame PRIVATE unocore)

#test executables
enable_testing()
include(CTest)

##dealer testing
add_executable(dealertest tests/dealer_t.c)
target_link_libraries(dealertest PRIVATE unocore)
add_test(NAME testdealer COMMAND dealertest)
