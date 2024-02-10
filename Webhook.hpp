#define CURL_STATICLIB
#include <curl/curl.h>
#include <iostream>
#include <string>

class Webhook {
public:
	void file(const char* path);
	void message(const char* message);
	const char* get_url();
private:
	const char* url = "";
};