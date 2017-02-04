include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
  

include_directories(catch)
include_directories(vibes)

ADD_EXECUTABLE(test_Polar test_polar.cpp)
target_link_libraries(test_Polar ${LIBS} ibex-geometry)
ADD_TEST(test_Polar test_Polar)

ADD_EXECUTABLE(test_CtcSegment test_CtcSegment.cpp)
target_link_libraries(test_CtcSegment ${LIBS} ibex-geometry )
ADD_TEST(test_CtcSegment test_CtcSegment)

configure_file(setResult_06 setResult_06 COPYONLY)
configure_file(setResult_07 setResult_07 COPYONLY)

ADD_EXECUTABLE(test_SepPolygon test_SepPolygon.cpp vibes/vibes.cpp)
target_link_libraries(test_SepPolygon ${LIBS} ibex-geometry )
ADD_TEST(test_SepPolygon test_SepPolygon)
