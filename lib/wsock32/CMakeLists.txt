cmake_minimum_required(VERSION 3.25)

project(wsock32_proxy
	DESCRIPTION "wsock32.dll Proxy DLL"
	VERSION 1.0.0.0
)

add_library(${PROJECT_NAME} SHARED)

target_link_libraries(${PROJECT_NAME} PRIVATE common)
target_include_directories(common PRIVATE "common/")

target_sources(${PROJECT_NAME}
	PRIVATE
		"wsock32_exports.cpp"
		"wsock32.def"
)

target_add_versioninfo(${PROJECT_NAME}
	FILE_NAME "wsock32.dll"
	VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSION_TWEAK}"
	COMPANY_NAME ${CMAKE_PROJECT_NAME}
	PRODUCT_NAME ${PROJECT_DESCRIPTION}
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E rename
		"${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.dll"
		"${CMAKE_CURRENT_BINARY_DIR}/wsock32.dll"
)