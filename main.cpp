#include "lib/webview.h"
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    std::string title;
    std::string url;
    int size_hint = 0;
    int width = 0, height = 0;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "--title" && i + 1 < argc) {
            title = argv[++i];
        } else if (arg == "--url" && i + 1 < argc) {
            url = argv[++i];
        } else if (arg == "--size" && i + 1 < argc) {
            size_hint = std::atoi(argv[++i]);
        } else if (arg == "--width" && i + 1 < argc) {
            width = std::atoi(argv[++i]);
        } else if (arg == "--height" && i + 1 < argc) {
            height = std::atoi(argv[++i]);
        }
    }

    if (title.empty() || url.empty() || width <= 0 || height <= 0) {
        return 0;
    }

    webview::webview w(false, nullptr);
    w.set_title(title);
    w.set_size(width, height, static_cast<webview_hint_t>(size_hint));
    w.navigate(url);
    w.run();
    return 0;
}
