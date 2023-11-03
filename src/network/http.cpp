#include "include/network/http.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

HTTPClient::HTTPClient(const std::string &host, int port) : sockfd(-1), host(host), port(port) {}

HTTPClient::~HTTPClient()
{
	disconnect();
}

void HTTPClient::connect()
{
	struct sockaddr_in serv_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		std::cerr << "Error opening socket" << std::endl;
		return;
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	if (inet_pton(AF_INET, host.c_str(), &serv_addr.sin_addr) <= 0)
	{
		std::cerr << "Invalid address/ Address not supported" << std::endl;
		return;
	}
	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		std::cerr << "Connection failed" << std::endl;
		return;
	}
}

void HTTPClient::disconnect()
{
	if (sockfd >= 0)
	{
		close(sockfd);
		sockfd = -1;
	}
}

std::string HTTPClient::get(const std::string &path)
{
	connect();
	std::string request = "GET " + path + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
	if (send(sockfd, request.c_str(), request.length(), 0) < 0)
	{
		std::cerr << "Error sending request" << std::endl;
		disconnect();
		return "";
	}
	char buffer[1024];
	std::string response = "";
	int n;
	while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0)
	{
		response.append(buffer, n);
	}
	if (n < 0)
	{
		std::cerr << "Error receiving response" << std::endl;
		disconnect();
		return "";
	}
	disconnect();
	return response;
}
