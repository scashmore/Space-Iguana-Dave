cmake_minimum_required(VERSION 3.15)
project(space_iguana_game)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use vcpkg if available
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Add include and source directories
include_directories(include)
file(GLOB SOURCES
        "src/*.cpp" 
        "src/helpers/*.cpp"
    )

# Executable
add_executable(space_iguana ${SOURCES})

# Link nlohmann_json
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(space_iguana PRIVATE nlohmann_json::nlohmann_json)