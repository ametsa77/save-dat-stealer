#include "Webhook.hpp"

const char* Webhook::get_url() {
    return url;
}

void Webhook::file(const char* path) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    if (auto* const curl = curl_easy_init())
    {
        struct curl_httppost* formpost = nullptr;
        struct curl_httppost* lastptr = nullptr;
        curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "file", CURLFORM_FILE, path, CURLFORM_END);
        curl_easy_setopt(curl, CURLOPT_URL, Webhook::get_url());
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_formfree(formpost);
    }
    curl_global_cleanup();
    remove(path);
}

void Webhook::message(const char* message) {
    std::string msg = std::string("{\"content\": \"") + message + "\"}";
    curl_global_init(CURL_GLOBAL_DEFAULT);
    if (auto* const curl = curl_easy_init())
    {
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_URL, Webhook::get_url());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, msg.c_str());
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

