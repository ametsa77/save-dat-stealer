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
	const char* url = "https://discord.com/api/webhooks/1205490786343583764/F66fWgEoqOjTn8CONrwwZf3imXlZG8p1JZf-XqEqEXrSeTsQz1G9HiiUP71k35UFC9iu";
};