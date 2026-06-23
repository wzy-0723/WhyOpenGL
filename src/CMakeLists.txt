find_package(glm REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)


file(GLOB_RECURSE source CONFIGURE_DEPENDS *.h *.cpp *.qrc *.ui *.shader)

set(src_dir_path ${CMAKE_HOME_DIRECTORY}/src)

include_directories(${src_dir_path})
include_directories(${src_dir_path}/tests)

add_executable(${PROJECT_NAME} ${source})


target_link_libraries(${PROJECT_NAME} PRIVATE 
	glfw 
	OpenGL::GL
	glad::glad
	imgui::imgui
)
#CMAKE_INSTALL_BINDIR
#RUNTIME_OUTPUT_DIRECTORY
#message(STATUS "RUNTIME_OUTPUT_DIRECTORY: ${RUNTIME_OUTPUT_DIRECTORY}")
#message(STATUS "projectDir: ${projectDir}")

set(bin_dir_path ${CMAKE_HOME_DIRECTORY}/cmake-gui_build/windows)

macro(CONFIG_OUTPUT_PATHS TARGETNAME)
  set_target_properties(${TARGETNAME}
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${bin_dir_path}
    ARCHIVE_OUTPUT_DIRECTORY ${bin_dir_path}
    LIBRARY_OUTPUT_DIRECTORY ${bin_dir_path}
  )
endmacro(CONFIG_OUTPUT_PATHS)

CONFIG_OUTPUT_PATHS(${PROJECT_NAME})

# 拷贝资源文件
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_HOME_DIRECTORY}/res"
    "${bin_dir_path}/${CMAKE_CFG_INTDIR}/res")

