include_directories(catch)
ADD_EXECUTABLE(test_Polar test_polar.cpp)
target_link_libraries(test_Polar ${LIBS} ibex-geometry)
ADD_TEST(test_Polar test_Polar)

ADD_EXECUTABLE(test_CtcSegment TestCtcSegment.cpp)
target_link_libraries(test_CtcSegment ibex-geometry ${LIBS} )
ADD_TEST(test_CtcSegment test_CtcSegment)
