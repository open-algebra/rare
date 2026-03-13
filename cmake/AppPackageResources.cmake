function(target_package_resources TARGET_NAME RES_DIR)
        file(GLOB_RECURSE APP_RESOURCES "${RES_DIR}/*")

        target_sources(${TARGET_NAME} PRIVATE
                ${APP_RESOURCES}
        )

        foreach(APP_RESOURCE ${APP_RESOURCES})
            file(RELATIVE_PATH REL_PATH "${RES_DIR}" ${APP_RESOURCE})
            cmake_path(GET REL_PATH PARENT_PATH PARENT)
            set_property(SOURCE ${APP_RESOURCE} PROPERTY MACOSX_PACKAGE_LOCATION "Resources/${PARENT}")
            source_group("Resources/${PARENT}" FILES ${APP_RESOURCE})
        endforeach ()
endfunction()