#include <stdio.h>
#include <sys/socket.h>

const char * url = "https://www.randomwordgenerator.com/json/words.json";

int main() {
    int temp_socket = socket(AF_INET, SOCK_STREAM, 0);
}