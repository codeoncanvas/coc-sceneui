if( NOT TARGET CoC-SceneUI )
    get_filename_component( COC-SCENEUI_SOURCE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../src" ABSOLUTE )

    FILE(GLOB_RECURSE COC-SCENEUI_SOURCES ${COC-SCENEUI_SOURCE_PATH}/ *.cpp)

    add_library( CoC-SceneUI ${COC-SCENEUI_SOURCES} )
    target_include_directories( CoC-SceneUI PUBLIC
            ${COC-SCENEUI_SOURCE_PATH}/ )

    # If Cinder included from this block:

    target_include_directories( CoC-SceneUI SYSTEM BEFORE PUBLIC "${CINDER_PATH}/include" )

    if( NOT TARGET cinder )
        include( "${CINDER_PATH}/proj/cmake/configure.cmake" )
        find_package( cinder REQUIRED PATHS
                "${CINDER_PATH}/${CINDER_LIB_DIRECTORY}"
                "$ENV{CINDER_PATH}/${CINDER_LIB_DIRECTORY}" )
    endif()

    # Add CoC-UI block as a dependency
    get_filename_component( COC-SCENE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../CoC-UI/proj/cmake" ABSOLUTE )
    find_package( CoC-UI REQUIRED PATHS "${COC-SCENE_MODULE_PATH}" )
    if (CoC-Scene_FOUND)
        add_dependencies( CoC-UI CoC-SceneUI )
        target_link_libraries( CoC-UI PUBLIC CoC-SceneUI)
    endif()

    # Add CoC-Scene block as a dependency
    get_filename_component( COC-SCENE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../../CoC-Scene/proj/cmake" ABSOLUTE )
    find_package( CoC-Scene REQUIRED PATHS "${COC-SCENE_MODULE_PATH}" )
    if (CoC-Scene_FOUND)
        add_dependencies( CoC-Scene CoC-SceneUI )
        target_link_libraries( CoC-Scene PUBLIC CoC-SceneUI)
    endif()

    target_link_libraries( CoC-SceneUI PRIVATE cinder)

endif()
