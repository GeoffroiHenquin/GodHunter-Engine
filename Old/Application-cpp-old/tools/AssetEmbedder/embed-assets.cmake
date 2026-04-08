### Embed Assets
### This file is made to embed assets into the project.

# Write an embed_assets.h file in the output directory
set(EMBEDASSETS_HEADER_FILE_TEMPLATE [==[
#include <cstddef>

#ifndef GODHUNTER_TOOLS_EMBED_ASSETS_H
#define GODHUNTER_TOOLS_EMBED_ASSETS_H

const char* getAsset(const char* name_, std::size_t& size_);

#endif // GODHUNTER_TOOLS_EMBED_ASSETS_H
]==])
file(WRITE ${CMAKE_BINARY_DIR}/${ProjectId}/assets/embedded_assets.h "${EMBEDASSETS_HEADER_FILE_TEMPLATE}")

# Write an empty embed_assets.cpp file in the output directory
file(WRITE ${CMAKE_BINARY_DIR}/${ProjectId}/assets/embedded_assets.cpp "")

# Add the assets directory to the include directories
target_include_directories(${ProjectId} PUBLIC ${CMAKE_BINARY_DIR}/${ProjectId}/assets)

# Create the embed_assets tool
if (NOT TARGET AssetEmbedder)
	add_executable(AssetEmbedder "./tools/AssetEmbedder/asset_embedder.cpp")
endif()

# Call the embed_assets tool on build
add_custom_command(
	TARGET AssetEmbedder
	POST_BUILD
	COMMAND AssetEmbedder ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_BINARY_DIR}/${ProjectId}/assets
	COMMENT "Embedding the assets"
	VERBATIM
)

# Create a static library containing the embedded assets
add_library(${ProjectId}EmbeddedAssets STATIC
${CMAKE_BINARY_DIR}/${ProjectId}/assets/embedded_assets.cpp
${CMAKE_BINARY_DIR}/${ProjectId}/assets/embedded_assets.h)

# Add the embedded assets library to the project
target_link_libraries(${ProjectId} ${ProjectId}EmbeddedAssets)