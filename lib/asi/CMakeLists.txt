project(RetroGameLANHook
        DESCRIPTION "RetroGameLANHook.asi ASI Plugin"
        VERSION 1.0.0.0
)

add_library(${PROJECT_NAME} SHARED)

target_link_libraries(${PROJECT_NAME} PRIVATE common)
target_include_directories(common PRIVATE "common/")

target_sources(${PROJECT_NAME}
    PRIVATE
        "dllmain.cpp"
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        SUFFIX ".asi"
)

target_add_versioninfo(${PROJECT_NAME}
        FILE_NAME "${PROJECT_NAME}.asi"
        VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSION_TWEAK}"
        COMPANY_NAME ${CMAKE_PROJECT_NAME}
        PRODUCT_NAME ${PROJECT_DESCRIPTION}
)