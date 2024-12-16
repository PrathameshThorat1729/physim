cmake_minimum_required(VERSION 3.28.0)

project(physim
  VERSION 1.0.0
  LANGUAGES CXX
  DESCRIPTION "Physim - Simple Physics Simulations"  
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

if(EXISTS external/SFML)
  add_subdirectory(external/SFML)
else()
  message(FATAL_ERROR "Error: Git Submodule not upadted")
endif()

file(GLOB_RECURSE SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

if(WIN32)
  add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else()
  add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-system sfml-window)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(EXISTS ${PROJECT_SOURCE_DIR}/assets)
  file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
endif()

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
endif()
