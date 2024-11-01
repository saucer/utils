cmake_minimum_required(VERSION 3.21)
project(saucer-utils LANGUAGES CXX VERSION 1.1.0)

# --------------------------------------------------------------------------------------------------------
# Setup Library
# --------------------------------------------------------------------------------------------------------

add_library(${PROJECT_NAME} INTERFACE)
add_library(saucer::utils ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20 CXX_EXTENSIONS OFF CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------------------------------------------------------------
# Include directories
# --------------------------------------------------------------------------------------------------------

target_include_directories(${PROJECT_NAME} INTERFACE "include")

# --------------------------------------------------------------------------------------------------------
# Setup Dependencies
# --------------------------------------------------------------------------------------------------------

include("cmake/cpm.cmake")

CPMFindPackage(
  NAME           boost_preprocessor
  GIT_TAG        boost-1.86.0
  GIT_REPOSITORY "https://github.com/boostorg/preprocessor"
)

target_link_libraries(${PROJECT_NAME} INTERFACE Boost::preprocessor)

# --------------------------------------------------------------------------------------------------------
# Install Targets
# --------------------------------------------------------------------------------------------------------

install(DIRECTORY "include/" TYPE INCLUDE)
install(TARGETS ${PROJECT_NAME} INCLUDES DESTINATION include)
