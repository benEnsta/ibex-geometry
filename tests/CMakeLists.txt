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
