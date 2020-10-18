#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin() : store{nullptr} {

    set_default_size(800, 200);
    set_title("Mavs Arboreta, Nursery, and Green Association (MANGA)");

    // Put a vertical box container as the Window contents
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
    //   I N S E R T
	// Create a Insert menu and add to the menu bar
	Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
	menubar->append(*menuitem_insert);
	Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
	menuitem_insert->set_submenu(*insertmenu);
    //   T O O L
	// Append Tool to the Insert menu
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
    menuitem_tool->signal_activate().connect([this] {this->on_new_tool_click();});
    insertmenu->append(*menuitem_tool);	
    //   P L A N T
	// Append Plant to the Insert menu
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
    menuitem_plant->signal_activate().connect([this] {this->on_new_plant_click();});
    insertmenu->append(*menuitem_plant);
    //   M U L C H
	// Append Mulch to the Insert menu
    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
    insertmenu->append(*menuitem_mulch);

	vbox->show_all();
}
Mainwin::~Mainwin() { }

void Mainwin::on_quit_click() {
    close();
}
void Mainwin::on_new_tool_click() {
	close();
}
void Mainwin::on_new_plant_click() {
	close();
}
void Mainwin::on_new_mulch_click() {
	close();
}
