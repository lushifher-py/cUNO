cmake_minimum_required( VERSION 3.15)
project(cUNO LANGUAGES C)


#core engine static library
add_library(unocore STATIC
    src/dealermanager/cards.c
    src/dealermanager/dynarr.c
    src/dealermanager/shuffler.c
    src/dealermanager/dealer.c)
target_include_directories(unocore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include)

#visual engine static library
add_library(unovisual STATIC
    src/visuallib/utils.c
)
target_include_directories(unovisual PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/Include 
    dependencies/raylib/include
)
target_link_directories(unovisual PUBLIC dependencies/raylib/lib)
target_link_libraries(unovisual PUBLIC 
    raylib 
    opengl32 
    gdi32 
    winmm
)

#main executable
add_executable(unogame src/main.c)
target_link_libraries(unogame PRIVATE unocore)
target_link_libraries(unogame PRIVATE unovisual)

#test executables
enable_testing()
include(CTest)

##dealer testing
add_executable(dealertest tests/dealer_t.c)
target_link_libraries(dealertest PRIVATE unocore)
add_test(NAME testdealer COMMAND dealertest)

##visual testing
add_executable(visualtest tests/visual_t.c)
target_link_libraries(visualtest PRIVATE unovisual)
