#ifndef HTTP_H
#define HTTP_H

#include <string>

class HTTPClient {
public:
    HTTPClient(const std::string& host, int port);
    ~HTTPClient();

    std::string get(const std::string& path);

private:
    int sockfd;
    std::string host;
    int port;

    void connect();
    void disconnect();
};

#endif