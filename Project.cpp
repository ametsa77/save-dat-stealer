#include "Webhook.hpp"
#include "File.hpp"

int main() {
	File f;
	f.create_temp(f.data_path());
	Webhook w;
	w.file(f.get_temp_path());
}