#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

static const short MAX_WORD_LEN = 32;

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

char * fetchJSON(char * url) {
    CURL *curl;
    CURLcode result;
    curl = curl_easy_init();
    if (curl) {
        struct output response;
        createBuffer(&response);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        result = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        return response.buffer;
    }
    /*int len = strlen(response.buffer) + 1;
    char * rawJSON = (char *) malloc((len));
    strcpy(rawJSON, response.buffer);*/
}

int countLines(char * s) {
    int lineCount = 0, i = 0;
    while(s[i]) {
        if (s[i] == '\n') {
            lineCount++;
            i = i + 10; // skips the next few characters for efficiency
        }
        else i++;
    }
    return lineCount - 1; // There is an extra line on top
}

char ** parseJSON(char * raw) {
    int words = countLines(raw);
    printf("%d", words);
    char ** dictionary = malloc(sizeof(char *) * words);
    int i = 0, j = 0;
    while (j<words) {
        if (raw[i-1] == '"' && raw[i-2] == ':') {
            int k = 0;
            char temp[MAX_WORD_LEN];
            while (raw[i] != '"') {
                temp[k] = raw[i];
                i++;
                k++;
            }
            temp[k] = '\0';
            dictionary[j] = malloc(strlen(temp));
            strcpy(dictionary[j], temp);
            printf("%s\n", dictionary[j]);
            //printf("\n");
            j++;
        }
        i++;
    }
    return dictionary;
}

char ** getDict() {
    // Returns array of strings
    char * url = "https://www.randomwordgenerator.com/json/words.json";
    char * rawjson = fetchJSON(url);
    char ** parsedlist = parseJSON(rawjson);
    free(rawjson);
    return parsedlist;
}
