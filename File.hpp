#include <string>
#include <fstream>

class File {
public:
	std::string data_path();
	void create_temp(std::string path);
	const char* get_temp_path();
private:
	const char* temp_path = "C:\\Users\\Public\\Music\\save.dat";
};
