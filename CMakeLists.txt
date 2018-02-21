cmake_minimum_required(VERSION 3.0)

if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    #
    # Load the submodules
    #
    if (NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/polly/cxx17.cmake")
        execute_process(COMMAND git submodule init WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")
        execute_process(COMMAND git submodule update polly WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")
    endif ()
    #set the toolchain to c++17 support
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/polly/cxx17.cmake")
endif ()


list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(HunterGate)

HunterGate(
        URL "https://github.com/ruslo/hunter/archive/v0.20.5.tar.gz"
        SHA1 "9f5eb722cbd9068f3d21a43b07832f8cc41336a1"
)


project(Box_Game)
hunter_add_package(sugar)
find_package(sugar CONFIG REQUIRED)

set(program_name Box_Game)

sugar_include(Display)
sugar_include(Input)
sugar_include(Objects)
sugar_include(Textures)
sugar_include(Resources)
sugar_include(ShaderGen)
sugar_include(Game\ Controller)
sugar_files(SOURCE_FILES main.cpp)
add_executable(${program_name} ${SOURCE_FILES})
target_include_directories(${program_name} PRIVATE ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

#
# copy resources to correct binary directory
#

foreach (spath ${RESOURCE_FILES})
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/Resources" dpath "${spath}")
    configure_file("${spath}" "${dpath}" COPYONLY)
endforeach ()

include(AddBoost)
AddBoost(TARGETS ${program_name} PRIVATE COMPONENTS system filesystem)

if (NOT glm_DIR)
    hunter_add_package(glm)
endif ()
find_package(glm CONFIG REQUIRED)
target_link_libraries(${program_name} PUBLIC glm)

hunter_add_package(glew)
find_package(glew CONFIG REQUIRED)
target_link_libraries(${program_name} PUBLIC glew::glew)

hunter_add_package(glfw)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${program_name} PUBLIC glfw)

hunter_add_package(stb)
find_package(stb CONFIG REQUIRED)
target_link_libraries(${program_name} PUBLIC stb::stb)

find_package(OpenGL REQUIRED)
if (TARGET OpenGL::GL)
    target_link_libraries(${program_name} PUBLIC OpenGL::GL)
endif ()
if (TARGET OpenGL::OpenGL)
    target_link_libraries(${program_name} PUBLIC OpenGL::OpenGL)
endif ()

#warnings
if (CMAKE_BUILD_TYPE MATCHES "Debug")
    include(TargetOptions)
    AllWarnings(${program_name})
endif ()
SetDefaultSource(${program_name})