#include "mainwin.h"
#include "entrydialog.h"
#include <iostream>

Mainwin::Mainwin() : store{nullptr} {

    set_default_size(800, 200);
    set_title("MANGA Mania");

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

	display = Gtk::manage(new Gtk::Label());
	display->set_hexpand(true);
	display->set_vexpand(true);
	vbox->add(*display);
	vbox->show_all();
}
Mainwin::~Mainwin() { }

void Mainwin::on_quit_click() {
	close();
}
void Mainwin::on_new_tool_click() {
	Gtk::Dialog dialog{"New Tool", *this};
	Gtk::Grid grid;
	Gtk::Label t_name{"Name"};
	Gtk::Entry e_name;
	grid.attach(t_name, 0, 0, 1, 1);
	grid.attach(e_name, 1, 0, 2, 1);

	Gtk::Label l_price{"Price"};
	Gtk::Entry e_price;
	grid.attach(l_price, 0, 1, 1, 1);
	grid.attach(e_price, 1, 1, 2, 1);

	Gtk::Label l_descr{"Description"};
	Gtk::Entry e_descr;
	grid.attach(l_descr, 0, 2, 1, 1);
	grid.attach(e_descr, 1, 2, 2, 1);

	dialog.get_content_area()->add(grid);

	dialog.add_button("Select", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	int response;
	dialog.show_all();
	while((response = dialog.run()) == Gtk::RESPONSE_OK) {

        // Data validation: If the user doesn't enter a name for the animal, complain
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}

        // Otherwise, extract the information entered into the various widgets
        std::string tool_info = e_name.get_text() + " (Stock #1,$ " +
			e_price.get_text() + " \n"+ " \nDescrption: " + e_descr.get_text();

         // Just display the information right back. In most applications, this is where you'd
         //   create a new object and add it to a std::vector or other container
         Gtk::MessageDialog{*this, "You entered: \n\n" + tool_info}.run();
		break;
    }
}
void Mainwin::on_new_plant_click() {
	Gtk::Dialog dialog{"New Plant", *this};
	Gtk::Grid grid;
	Gtk::Label t_name{"Name"};
	Gtk::Entry e_name;
	grid.attach(t_name, 0, 0, 1, 1);
	grid.attach(e_name, 1, 0, 2, 1);

	Gtk::Label l_price{"Price"};
	Gtk::Entry e_price;
	grid.attach(l_price, 0, 1, 1, 1);
	grid.attach(e_price, 1, 1, 2, 1);

	Gtk::Label l_descr{"Description"};
	Gtk::Entry e_descr;
	grid.attach(l_descr, 0, 2, 1, 1);
	grid.attach(e_descr, 1, 2, 2, 1);

	Gtk::Label l_species{"Species"};
	Gtk::Entry e_species;
	grid.attach(l_species, 0, 3, 1, 1);
	grid.attach(e_species, 1, 3, 2, 1);

	Gtk::Label l_exp{"Exposure"};
	Gtk::Entry e_exp;
	grid.attach(l_exp, 0, 4, 1, 1);
	grid.attach(e_exp, 1, 4, 2, 1);

	dialog.get_content_area()->add(grid);

	dialog.add_button("Select", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	int response;
	dialog.show_all();
	while((response = dialog.run()) == Gtk::RESPONSE_OK) {

        // Data validation: If the user doesn't enter a name for the animal, complain
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}

        // Otherwise, extract the information entered into the various widgets
        std::string plant_info = e_name.get_text() + " (Stock #1,$ " +
			e_price.get_text() + " \n" + e_descr.get_text()
			+ " \nSpecies: " + e_species.get_text() + " \nExposure: " + e_exp.get_text();

         // Just display the information right back. In most applications, this is where you'd
         //   create a new object and add it to a std::vector or other container
         Gtk::MessageDialog{*this, "You entered \n\n" + plant_info}.run();
		break;
    }
}
void Mainwin::on_new_mulch_click() {
	Gtk::Dialog dialog{"New Mulch", *this};
	Gtk::Grid grid;
	Gtk::Label t_name{"Name"};
	Gtk::Entry e_name;
	grid.attach(t_name, 0, 0, 1, 1);
	grid.attach(e_name, 1, 0, 2, 1);

	Gtk::Label l_price{"Price"};
	Gtk::Entry e_price;
	grid.attach(l_price, 0, 1, 1, 1);
	grid.attach(e_price, 1, 1, 2, 1);

	Gtk::Label l_descr{"Description"};
	Gtk::Entry e_descr;
	grid.attach(l_descr, 0, 2, 1, 1);
	grid.attach(e_descr, 1, 2, 2, 1);

	Gtk::Label l_volume{"Volume"};
	Gtk::Entry e_volume;
	grid.attach(l_volume, 0, 3, 1, 1);
	grid.attach(e_volume, 1, 3, 2, 1);

	Gtk::Label l_material{"Material"};
	Gtk::Entry e_material;
	grid.attach(l_material, 0, 4, 1, 1);
	grid.attach(e_material, 1, 4, 2, 1);

	dialog.get_content_area()->add(grid);

	dialog.add_button("Select", Gtk::RESPONSE_OK);
    dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	int response;
	dialog.show_all();
	while((response = dialog.run()) == Gtk::RESPONSE_OK) {

        // Data validation: If the user doesn't enter a name for the animal, complain
        if (e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}

        // Otherwise, extract the information entered into the various widgets
        std::string mulch_info = e_name.get_text() + " (Stock #1,$ " +
			e_price.get_text() + " \n" + e_descr.get_text()
			+ " \nVolume: " + e_volume.get_text() + " \nMaterial: " + e_material.get_text();

         // Just display the information right back. In most applications, this is where you'd
         //   create a new object and add it to a std::vector or other container
         Gtk::MessageDialog{*this, "You entered \n\n" + mulch_info}.run();
		break;
    }
}
void Mainwin::on_view_products_click() {

}

