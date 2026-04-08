### Set Icon
### This file is made to set the icon of the executable.

# Windows
if(WIN32)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/data/icon/icon.ico")
        # Generate resource file
        file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/${ProjectId}/icon.rc"
        "IDI_ICON1 ICON \"${CMAKE_CURRENT_SOURCE_DIR}/data/icon/icon.ico\"")
        # Add resource file to target
        target_sources("${ProjectId}" PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/${ProjectId}/icon.rc")
    endif()
endif()

# macOS
if(APPLE)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/data/icon/icon.icns")
        set_target_properties("${ProjectId}" PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_ICON_FILE "${CMAKE_CURRENT_SOURCE_DIR}/data/icon/icon.icns")
    endif()
endif()

# Linux
if(UNIX AND NOT APPLE)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/data/icon/icon.png")
        # Copy icon to build directory
        file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/data/icon/icon.png" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/${ProjectId}/icon/")

        # Add custom command to set icon (requires `xprop` and `wmctrl`)
        add_custom_command(TARGET "${ProjectId}" POST_BUILD
            COMMAND xprop -root _NET_SUPPORTING_WM_CHECK
            COMMAND wmctrl -i "$(_NET_SUPPORTING_WM_CHECK)" -e "0,0,0,0,0"
            COMMAND xprop -id "$(_NET_SUPPORTING_WM_CHECK)" -f _NET_WM_ICON 32c -set _NET_WM_ICON "$(xwd -name "${ProjectId}" | convert xwd:- -resize 64x64 -depth 8 rgba:- | tail -n +5 | tr -d '\n' | sed 's/ //g')"
            COMMAND wmctrl -i "$(_NET_SUPPORTING_WM_CHECK)" -e "0,0,0,0,0"
            COMMENT "Setting icon for ${ProjectId}"
        )
    elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/data/icon/icon.xpm")
        # Copy icon to build directory
        file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/data/icon/icon.xpm" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/${ProjectId}/icon/")

        # Add custom command to set icon (requires `xprop` and `wmctrl`)
        add_custom_command(TARGET "${ProjectId}" POST_BUILD
            COMMAND xprop -root _NET_SUPPORTING_WM_CHECK
            COMMAND wmctrl -i "$(_NET_SUPPORTING_WM_CHECK)" -e "0,0,0,0,0"
            COMMAND xprop -id "$(_NET_SUPPORTING_WM_CHECK)" -f _NET_WM_ICON 32c -set _NET_WM_ICON "$(xwd -name "${ProjectId}" | convert xwd:- -resize 64x64 -depth 8 rgba:- | tail -n +5 | tr -d '\n' | sed 's/ //g')"
            COMMAND wmctrl -i "$(_NET_SUPPORTING_WM_CHECK)" -e "0,0,0,0,0"
            COMMENT "Setting icon for ${ProjectId}"
        )
    endif()
endif()