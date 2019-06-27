set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -g")
find_package(Boost 1.66 COMPONENTS system program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(iching main.cc hexagram.cc translator.cc util.cc)
target_link_libraries(iching LINK_PUBLIC ${Boost_LIBRARIES})

install(TARGETS iching RUNTIME DESTINATION bin)
