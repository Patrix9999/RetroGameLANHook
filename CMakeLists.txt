cmake_minimum_required(VERSION 3.21)

project(RetroGameLANHook)

add_library(${PROJECT_NAME} SHARED)

target_sources(${PROJECT_NAME}
	PRIVATE
		"dllmain.cpp"
)

set_target_properties(${PROJECT_NAME}
	PROPERTIES
		SUFFIX ".asi"
)