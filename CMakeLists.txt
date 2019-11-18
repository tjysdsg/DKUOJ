cmake_minimum_required(VERSION 3.0)
project(dkuoj)

set(CMAKE_CXX_STANDARD 11)

# get list of subdirs
MACRO(SUBDIRLIST result)
    FILE(GLOB children ${PROJECT_SOURCE_DIR}/*)
    SET(dirlist "")
    FOREACH (child ${children})
        GET_FILENAME_COMPONENT(dirname ${child} NAME)
        IF (IS_DIRECTORY ${child})
            IF (${dirname} MATCHES "^[0-9]+")
                message(${dirname})
                LIST(APPEND dirlist ${dirname})
            ENDIF ()
        ENDIF ()
    ENDFOREACH ()
    SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(SUBDIRS)
FOREACH (subdir ${SUBDIRS})
    FILE(GLOB files ${PROJECT_SOURCE_DIR}/${subdir}/*.cpp ${PROJECT_SOURCE_DIR}/${subdir}/*.c)
    add_executable(${subdir} ${files})
ENDFOREACH ()

