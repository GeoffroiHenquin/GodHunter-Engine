/**
 * @file assets.h
 * This file is part of the GodHunter Engine
 *
 * This file declare a way for the engine to handle assets.
 *
 * MIT License
 *
 * Copyright (c) 2025 GeoffroiHenquin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

// Related header

// C system headers

// C++ standard library headers
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

// Third party libraries headers

// Project headers

// Exceptions

#ifndef GODHUNTER_ENGINE_ASSETS_H_
#define GODHUNTER_ENGINE_ASSETS_H_

namespace godhunter
{

	// https://freedium.cfd/https://david-delassus.medium.com/im-embedding-my-game-assets-into-the-executable-here-s-how-i-did-it-1f5b78c02d57

	// If the engine is built in release mode, we want to embed all assets into the executable or library
	// Else, we want to load them from the assets/ folder

	// On getAsset()
	// Check if the asset is already loaded in memory
	// If not, load it from the assets/ folder (debug mode) or from the embedded assets (release mode)
	// If not found, check if it can be found around the executable
	// If still not found, return nullptr

	// TODO: Embed all files from the assets/ folder into the executable here

	struct Asset
	{
		std::string name;
		char* data;
		std::size_t size;
	};

	class AssetManager
	{
	private:
		std::vector<Asset> m_loaded_assets;
	public:
		AssetManager()
		{
		}
		~AssetManager()
		{
		}

		bool loadAssetFromFile(std::string asset_url_)
		{
			// Open file
			std::ifstream file(asset_url_, std::ios::binary);
			if (!file.is_open())
			{
				return false;
			}

			// Create asset
			Asset new_asset;

			// Get file name
			new_asset.name = asset_url_;

			// Get file size and read it into memory
			file.seekg(0, std::ios::end);
			new_asset.size = file.tellg();
			file.seekg(0, std::ios::beg);

			// Allocate memory and read file
			new_asset.data = new char[new_asset.size];
			file.read(new_asset.data, new_asset.size);

			// Add asset to loaded assets
			m_loaded_assets.push_back(new_asset);

			// Close file
			file.close();

			// TODO: Return false if an error occurred
			return true;
		}

		bool loadAssetFromMemory(std::string asset_url_)
		{
			// TODO: Load asset from embedded assets
			return false;
		}

		bool assetIsLoaded(std::string asset_url_)
		{
			for (const auto& asset : m_loaded_assets)
			{
				if (asset.name == asset_url_)
				{
					return true;
				}
			}
			return false;
		}

		char* getAsset(std::string asset_url_)
		{
			// TODO: Check if the asset is loaded, if not load it
			if (assetIsLoaded(asset_url_))
			{
				return nullptr; // TODO: Return pointer to asset in memory
			}

			// TODO: If the asset cannot be loaded, return nullptr

			// TODO: Return a pointer to the asset in memory
		}
	};

} // namespace godhunter

#endif // GODHUNTER_ENGINE_ASSETS_H_