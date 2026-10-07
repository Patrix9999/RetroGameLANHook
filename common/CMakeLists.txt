file(GLOB_RECURSE SRC CONFIGURE_DEPENDS
    "*.hpp"
    "*.cpp"
)

add_library(common STATIC)
target_sources(common PRIVATE ${SRC})

target_include_directories(common
    PUBLIC
        "include/"
)