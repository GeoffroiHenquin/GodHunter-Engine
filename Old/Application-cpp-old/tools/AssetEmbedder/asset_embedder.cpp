#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
	// Print Start
	std::cout << "Embedding assets with\n" << "Input folder: " << argv[1] << "\n" << "Output folder: " << argv[2] << "\n";

	// Get input and output directory
	std::string input_directory_url = argv[1];
	std::string output_directory_url = argv[2];

	// Init the output file
	std::ofstream output_source_file(output_directory_url + "/embedded_assets.cpp");
	output_source_file.clear();

	// Add includes
	output_source_file << "#include \"embedded_assets.h\"\n"
		<< "#include <string>\n"
		<< "#include <fstream>\n"
		<< "#include <vector>\n\n";

	// For each file in the input folder, embed it in the output file.
	const std::filesystem::path asset_folder_path{ input_directory_url };
	unsigned int file_index = 0;
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ asset_folder_path })
	{
		if (!dir_entry.is_directory())
		{
			std::cout << "Embedding file: " << dir_entry.path().lexically_relative(asset_folder_path).generic_string() << "\n";

			// Create the array for the file
			std::string file_path = dir_entry.path().generic_string();
			std::ifstream input_file(file_path, std::ios::binary);
			output_source_file << "const unsigned char embedded_file_" << file_index << "[] = {\n";

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

	// Add the data structure to access the static array.
	output_source_file << "\nconst struct EmbeddedFile {\n"
		<< "\tconst char* name;\n"
		<< "\tconst unsigned char* data;\n"
		<< "\tunsigned int size;\n"
		<< "} embedded_files[] = {\n";

	file_index = 0;
	for (auto const& dir_entry : std::filesystem::recursive_directory_iterator{ asset_folder_path })
	{
		if (!dir_entry.is_directory())
		{
			std::string file_name = dir_entry.path().lexically_relative(asset_folder_path).generic_string();
			output_source_file << "\t{ \"" << file_name << "\", embedded_file_" << file_index << ", sizeof(embedded_file_" << file_index << ") - 1 },\n";

			file_index++;
		}
	}

	output_source_file << "\t{NULL, NULL, 0}\n};\n\n";

	// Add the data structure to access the dynamic array.
	output_source_file << "std::vector<EmbeddedFile> dynamic_embedded_files;\n\n";

	// Add the function to get the data.
	output_source_file << "const char* getAsset(const char* name_, std::size_t& size_) {\n"
		<< "\tconst struct EmbeddedFile* file_pointer;\n"
		// Search file in the static array.
		<< "\tfor (file_pointer = embedded_files; file_pointer->name != NULL; file_pointer++) {\n"
		<< "\t\tif (strcmp(name_, file_pointer->name) == 0) {\n"
		<< "\t\t\tsize_ = file_pointer->size;\n"
		<< "\t\t\treturn reinterpret_cast<const char*>(file_pointer->data);\n"
		<< "\t\t}\n"
		<< "\t}\n"
		// Search file in the dynamic array.
		<< "\tfor (auto dynamic_file : dynamic_embedded_files) {\n"
		<< "\t\tif (strcmp(name_, dynamic_file->name) == 0) {\n"
		<< "\t\t\tsize_ = dynamic_file->size;\n"
		<< "\t\t\treturn reinterpret_cast<const char*>(dynamic_file->data);\n"
		<< "\t\t}\n"
		<< "\t}\n"
		// Search file in file system and add it to the dynamic array.
		<< "\tstd::ifstream input_file(name_, std::ios::binary);\n"
		<< "\tif (input_file.is_open()) {\n"
		<< "\t\tint file_size = input_file.tellg();\n"
		<< "\t\tchar* file_array = new char[file_size];\n"
		<< "\t\tinput_file.seekg(0, std::ios::beg);\n"
		<< "\t\tinput_file.read(file_array, file_size);\n"
		<< "\t\tinput_file.close();\n"
		<< "\t\tdynamic_embedded_files.push_back({ name_, reinterpret_cast<const unsigned char*>(file_array), file_size });\n"
		<< "\t\tsize_ = file_size;\n"
		<< "\t\treturn reinterpret_cast<const char*>(file_array);\n"
		<< "\t}\n"
		// If file not found, return NULL
		<< "\treturn NULL;\n"
		<< "}\n";

	output_source_file.close();
	std::cout << "Finished embedding assets\n";

	return 0;
}