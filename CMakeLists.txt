cmake_minimum_required(VERSION 3.15)
project(mjpgv CXX)
#find_package(OpenCV CONFIG REQUIRED COMPONENTS core imgcodecs highgui videoio )
find_package(OpenCV CONFIG REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} src/mjpgv.cpp src/main.cpp src/opencv.cpp)

message("MYMSG ${OpenCV_INCLUDE_DIRS} \t ${OpenCV_INCLUDE_DIR} \t ${OpenCV_LIBS} \t ${OpenCV_LIBRARIES}")

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include ${OpenCV_INCLUDE_DIRS})

#target_link_libraries(mjpgv PRIVATE ${OpenCV_LIBRARIES})
target_link_libraries(mjpgv PRIVATE opencv_videoio opencv_core opencv_imgcodecs opencv_highgui)
#target_link_libraries(mjpgv PRIVATE opencv_videoio opencv_highgui)
#target_link_libraries(mjpgv PRIVATE opencv_core)
#target_link_libraries(mjpgv PRIVATE opencv_imgcodecs)


#install(TARGETS mjpgv DESTINATION "."
#        RUNTIME DESTINATION bin
#        ARCHIVE DESTINATION lib
#        LIBRARY DESTINATION lib
#        )

set(proj_dir "~/workspace/mjpgv")

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Debug
	RUNTIME DESTINATION ${proj_dir}/bin/Debug)
install(TARGETS ${PROJECT_NAME}
	CONFIGURATIONS Release
	RUNTIME DESTINATION ${proj_dir}/bin/Release)
