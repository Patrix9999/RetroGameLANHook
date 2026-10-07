cmake_minimum_required(VERSION 3.25)

set(TARGET_NAME wsock32_proxy)

add_library(${TARGET_NAME} SHARED)

target_link_libraries(${TARGET_NAME} PRIVATE common)
target_include_directories(common PRIVATE "common/")

target_sources(${TARGET_NAME}
	PRIVATE
		"wsock32_exports.cpp"
		"wsock32.def"
)

target_add_versioninfo(${TARGET_NAME}
	FILE_NAME "wsock32.dll"
	VERSION VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}.${PROJECT_VERSION_TWEAK}"
	COMPANY_NAME ${CMAKE_PROJECT_NAME}
	PRODUCT_NAME "wsock32.dll Proxy DLL"
)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E rename
		"${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.dll"
		"${CMAKE_CURRENT_BINARY_DIR}/wsock32.dll"
)