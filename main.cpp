#include "lib/webview.h"

int main() {
    webview::webview w(false, nullptr);
    w.set_title("Пример WebView");
    w.set_size(800, 600, WEBVIEW_HINT_NONE);
    w.set_html("<h1>Привет из WebView!</h1><p>Это встроенное HTML-окно.</p>");
    w.run();
    return 0;
}
