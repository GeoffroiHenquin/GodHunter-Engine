#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	// Take input folder and output folder with argc and argv.
	std::cout << "Started embedding assets with\n";
	std::cout << "Input folder: " << argv[1] << "\n";
	std::cout << "Output folder: " << argv[2] << "\n";

	// Initialize the output file.
	std::string output_source_file_url = std::string() + argv[2] + "/embed_assets.cpp";
	std::ofstream output_source_file(output_source_file_url);
	output_source_file.clear();

	output_source_file << "#include \"embed_assets.h\"\n";
	output_source_file << "#include <string>\n\n";

	// For each file in the input folder, embed it in the output folder.
	const std::filesystem::path asset_folder_path{ argv[1] };
	unsigned int file_index = 0;
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ asset_folder_path })
	{
		if (!dir_entry.is_directory())
		{
			std::cout << "Working on file: " << dir_entry.path().lexically_relative(asset_folder_path).generic_string() << "\n";

			// Create the array for the file
			std::string file_path = dir_entry.path().generic_string();
			std::ifstream input_file(file_path, std::ios::binary);
			output_source_file << "const unsigned char file_" << file_index << "[] = {\n";

			// Read the file into the array.
			int char_by_line = 0;
			char c;
			while (input_file.get(c))
			{
				output_source_file << "0x" << std::setw(2) << std::setfill('0') << std::hex << static_cast<unsigned int>(static_cast<unsigned char>(c)) << ", ";

				char_by_line++;
				if (char_by_line == 16)
				{
					output_source_file << "\n";
					char_by_line = 0;
				}
			}

			output_source_file << "0x00\n};\n";
			input_file.close();

			// Raise the index.
			file_index++;
		}
	}

	// Add the data structure to access the right array.
	output_source_file << "\nconst struct EmbeddedFile {\n";
	output_source_file << "	const char* name;\n";
	output_source_file << "	const unsigned char* data;\n";
	output_source_file << "	unsigned int size;\n";
	output_source_file << "} embedded_files[] = {\n";

	file_index = 0;
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ asset_folder_path })
	{
		if (!dir_entry.is_directory())
		{
			std::string file_name = dir_entry.path().lexically_relative(asset_folder_path).generic_string();
			output_source_file << "\t{ \"" << file_name << "\", file_" << file_index << ", sizeof(file_" << file_index << ") - 1 },\n";

			file_index++;
		}
	}

	output_source_file << "\t{NULL, NULL, 0}\n};\n\n";

	// Add the various functions to access the files.
	output_source_file << "const char* getEmbeddedAsset(const char* name_, std::size_t& size_) {\n";
	output_source_file << "\tconst struct EmbeddedFile* file_pointer;\n";
	output_source_file << "\tfor (file_pointer = embedded_files; file_pointer->name != NULL; file_pointer++) {\n";
	output_source_file << "\t\tif (strcmp(name_, file_pointer->name) == 0) {\n";
	output_source_file << "\t\t\tsize_ = file_pointer->size;\n";
	output_source_file << "\t\t\treturn reinterpret_cast<const char*>(file_pointer->data);\n";
	output_source_file << "\t\t}\n";
	output_source_file << "\t}\n";
	output_source_file << "\treturn NULL;\n";
	output_source_file << "}\n";

	return 0;
}