#include "mainwin.h"

int main (int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.manga.sprint6");
    Mainwin win;
    return app->run(win);
}

