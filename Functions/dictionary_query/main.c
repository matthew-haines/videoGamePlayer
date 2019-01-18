#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

const char * url = "https://www.randomwordgenerator.com/json/words.json";
char buffer[4096];
int buffer_count = 0;

struct output {
    char * buffer;
    size_t len;
};

void createBuffer(struct output * instance) {
    instance->len = 0; // Sets size of string
    instance->buffer = malloc(instance->len+1); // Creates memory area for buffer
    instance->buffer[instance->len] = '\0';
}

size_t writeData(void * ptr, size_t size, size_t nmemb, struct output * s) {
    // Takes parameters size of data stream and number of element
    size_t len = s->len + size*nmemb; // number of elements * size of elements
    s->buffer = realloc(s->buffer, len+1);
    memcpy(s->buffer+s->len, ptr, size*nmemb);
    s->buffer[len] = '\0';
    s->len = len;
    return size * nmemb;
}

char * parseJson(char * raw) {
    
}

int main(void) {
    CURL *curl;
    CURLcode result;
    curl = curl_easy_init();
    if (curl) {
        struct output buffer;
        createBuffer(&buffer);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        result = curl_easy_perform(curl);

        printf("%s\n", buffer.buffer);

        curl_easy_cleanup(curl);
    }
    return 0;   
}