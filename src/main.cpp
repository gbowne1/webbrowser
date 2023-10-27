#include <iostream>
#include "ui/window.h"
#include "network/http.h"
#include "rendering/html.h"

int main(int argc, char *argv[]) {
    // Initialize the user interface
    window_init();

    // Make an HTTP request
    http_response_t *response = http_get("https://www.example.com");

    // Render the HTML response
    html_render(response->body);

    // Clean up resources
    http_response_free(response);
    window_cleanup();

    return 0;
}