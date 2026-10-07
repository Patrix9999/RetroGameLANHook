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
        VERSION "${PROJECT_VERSION}.${PROJECT_VERSION}.${PROJECT_VERSION}.${PROJECT_VERSION}"
        COMPANY_NAME ${CMAKE_PROJECT_NAME}
        PRODUCT_NAME "RetroGameLANHook.asi ASI Plugin"
)