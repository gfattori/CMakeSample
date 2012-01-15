cmake_minimum_required (VERSION 2.8)

# Default to release
IF (NOT CMAKE_BUILD_TYPE)
  SET (CMAKE_BUILD_TYPE "Release" CACHE STRING
    "Choose the type of build, options are: Debug Release
      RelWithDebInfo MinSizeRel." FORCE)
ENDIF ()



project(testing)



# The version number.
set (testing_VERSION_MAJOR 0)
set (testing_VERSION_MINOR 3)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/testingConfig.h.in"
  "${PROJECT_BINARY_DIR}/testingConfig.h"
  )
 
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")




# should we use our own math functions?
option (USE_MYLIB
        "Use tutorial provided math implementation" ON)

# add the MathFunctions library?
#
if (USE_MYLIB)
  include_directories ("${PROJECT_SOURCE_DIR}/lib")
  add_subdirectory (lib)
  set (EXTRA_LIBS ${EXTRA_LIBS} giolib)
endif (USE_MYLIB)




include_directories("${PROJECT_SOURCE_DIR}/trk")
add_subdirectory (trk)


add_executable(testing main.cpp)
target_link_libraries(testing trk)


install (TARGETS testing DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/testingConfig.h"        
         DESTINATION include)

# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE  
     "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${testing_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${testing_VERSION_MINOR}")
include (CPack)

