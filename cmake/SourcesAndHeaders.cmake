# set(sources
#     src/tmp.cpp
# )
file(GLOB_RECURSE sources src/*.cpp)

# 添加main.cpp的话当前有问题，覆盖率没法出来
set(exe_sources
		src/main.cpp
		${sources}
)

# set(headers
#     include/project/tmp.hpp
# )
file(GLOB_RECURSE headers include/*.h)

# set(test_sources
#   src/tmp_test.cpp
# )
file(GLOB_RECURSE test_sources test/*.cpp)
