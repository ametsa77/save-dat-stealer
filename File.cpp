#include "File.hpp"

const char* File::get_temp_path() {
	return temp_path;
}

std::string File::data_path() {
	std::string path;
	char* appdata = nullptr;
	_dupenv_s(&appdata, 0, "LOCALAPPDATA");
	if (appdata != nullptr) path = std::string(appdata) + "\\Growtopia\\save.dat";
	return path;
}

void File::create_temp(std::string path) {
	std::ifstream read(File::data_path(), std::ios::binary);
	std::string content((std::istreambuf_iterator<char>(read)), std::istreambuf_iterator<char>());
	std::ofstream write(File::get_temp_path());
	write << content, write.close();
}