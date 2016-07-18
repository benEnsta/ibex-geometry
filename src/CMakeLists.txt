# add_subdirectory(pixelmap)
# add_subdirectory(extra_sep)
#



# add_subdirectory(polygon)
# add_subdirectory(polar)

# add_library(ibex-geometry ${LIBS_OBJS} config.h)
#
# include_directories(polar)
# include_directories(polygon)
set( SRCS
      # Polar sources
      polar/ibex_CtcAngle.cpp
      polar/ibex_CtcPolar.cpp
      polar/ibex_SepPolarXY.cpp
      # Polygon sources
      polygon/ibex_CtcSegment.cpp
      polygon/ibex_PdcInPolygon.cpp
  		polygon/ibex_SepPolygon.cpp

		)
set( HEADERS
      #Polar headers
      ${CMAKE_CURRENT_SOURCE_DIR}/polar/ibex_CtcAngle.h
      ${CMAKE_CURRENT_SOURCE_DIR}/polar/ibex_CtcPolar.h
			${CMAKE_CURRENT_SOURCE_DIR}/polar/ibex_SepPolarXY.h
      #Polygon headers
      ${CMAKE_CURRENT_SOURCE_DIR}/polygon/ibex_CtcSegment.h
      ${CMAKE_CURRENT_SOURCE_DIR}/polygon/ibex_PdcInPolygon.h
			${CMAKE_CURRENT_SOURCE_DIR}/polygon/ibex_SepPolygon.h
		)

# add_subdirectory(polar)
FILE(COPY ${HEADERS} DESTINATION ${HEADERS_DIR})

add_library(ibex-geometry ${SRCS} ${HEADERS})
target_link_libraries(ibex-geometry ${LIBS})

INSTALL( TARGETS ibex-geometry DESTINATION lib)
install(FILES ${HEADERS} DESTINATION "include/ibex-geometry")


# PYBIND11_ADD_MODULE(pyibex-geometry SHARED
    # pyIbex_geometry.cpp
#
# )
# target_link_libraries(pyibex-geometry ${LIBS} ibex-geometry)

# add_custom_command(TARGET pyibex-geometry POST_BUILD
	# COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:pyibex-geometry>" "${PYTHON_PACKAGE_DIR}/pyibex-geometry"
# )
