#include "mainwin.h"
#include "entrydialog.h"
#include <fstream>

Mainwin::Mainwin() : store{nullptr}, display{new Gtk::Label{}}, filename{"untitled.manga"} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(640, 480);
    set_title("MANGA Mania");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
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

	//			N E W   S T O R E 
	// Append New to the File menu
	Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
	menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
	filemenu->append(*menuitem_new);

	//			S A V E
	// Append Save to the File menu
	Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
	menuitem_save->signal_activate().connect([this] {this->on_save_click();});
	filemenu->append(*menuitem_save);

	// 			S A V E  A S	
	// Append Save As to the File menu
	Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("_Save as", true));
	menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
	filemenu->append(*menuitem_save_as);

	//			O P E N
	// Append Open to the File menu
	Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
	menuitem_open->signal_activate().connect([this] {this->on_open_click();});
	filemenu->append(*menuitem_open);

    //     I N S E R T
    // Create an Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    //           T O O L
    // Append Tool to the Insert menu
    Gtk::MenuItem *menuitem_tool = Gtk::manage(new Gtk::MenuItem("_Tool", true));
    menuitem_tool->signal_activate().connect([this] {this->on_new_tool_click();});
    insertmenu->append(*menuitem_tool);

    //           P L A N T
    // Append Plant to the Insert menu
    Gtk::MenuItem *menuitem_plant = Gtk::manage(new Gtk::MenuItem("_Plant", true));
    menuitem_plant->signal_activate().connect([this] {this->on_new_plant_click();});
    insertmenu->append(*menuitem_plant);
    
    //           M U L C H
    // Append Mulch to the Insert menu
    Gtk::MenuItem *menuitem_mulch = Gtk::manage(new Gtk::MenuItem("_Mulch", true));
    menuitem_mulch->signal_activate().connect([this] {this->on_new_mulch_click();});
    insertmenu->append(*menuitem_mulch);

    //           C U S T O M E R
    // Append Customer to the Insert menu
    Gtk::MenuItem *menuitem_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_customer->signal_activate().connect([this] {this->on_new_customer_click();});
    insertmenu->append(*menuitem_customer);

    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //         C U S T O M E R S
    // Append Customers to the View menu
    Gtk::MenuItem *menuitem_customers = Gtk::manage(new Gtk::MenuItem("_Customers", true));
    menuitem_customers->signal_activate().connect([this] {this->on_view_customers_click();});
    viewmenu->append(*menuitem_customers);

    //         P R O D U C T S
    // Append Products to the View menu
    Gtk::MenuItem *menuitem_products = Gtk::manage(new Gtk::MenuItem("_Products", true));
    menuitem_products->signal_activate().connect([this] {this->on_view_products_click();});
    viewmenu->append(*menuitem_products);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

        //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    // /////////////////////////// ////////////////////////////////////////////
    // M A I N   W I N D O W   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    
    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
	on_new_store_click(true);

}
Mainwin::~Mainwin() { }
// /////////////////
// C A L L B A C K S
// /////////////////
void Mainwin::on_new_store_click(bool untitled) {
    std::string name = "Untitled";
	try {
		if(!untitled) name = get_string("New store name?");
		filename = "untitled.manga";
	} catch (std::exception& e) {
	}
	delete store; store = nullptr;
	store = new Store{name};
	on_view_products_click();
}
void Mainwin::on_new_tool_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        store->add_product(*(new Tool{name, price, description}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
}
void Mainwin::on_new_plant_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        std::string species = get_string("Species?");
        double d = get_double("Exposure? (1) Shade (2) Part Sun (3) Sun");
        Exposure exposure = (d==1.0) ? Exposure::SHADE : ((d==3.0) ? Exposure::SUN : Exposure::PARTSUN);
        store->add_product(*(new Plant{name, price, description, species, exposure}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
}
void Mainwin::on_new_mulch_click() {
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        int volume = get_int("Volume (ft³)?");
        int i = get_int("Material? (1) Rubber (2) Pine (3) Cedar (4) Hardwood");
        Material material;
        if(i == 1)       material = Material::RUBBER;
        else if (i == 2) material = Material::PINE;
        else if (i == 3) material = Material::CEDAR;
        else             material = Material::HARDWOOD;
        store->add_product(*(new Mulch{name, price, description, volume, material}));
        on_view_products_click();
    } catch(std::exception& e) {
    }
}
void Mainwin::on_view_products_click() {
    std::string p = "<tt><u>Current Products</u>\n";
    for(int i=0; i<store->products(); ++i) {
        std::ostringstream oss;
        oss << store->product(i) << '\n';
        p += oss.str();
    }
    display->set_markup(p+"</tt>");
}
void Mainwin::on_view_customers_click() {
	
    std::string c = "<tt><u>Current Customers</u>\n";
    for(int j=0; j<store->customers(); ++j) {
        std::ostringstream oss;
        oss << store->customer(j) << '\n';
        c += oss.str();
    }
    display->set_markup(c+"</tt>");
}
void Mainwin::on_quit_click() {
    close();
}
std::string Mainwin::get_string(std::string prompt) {
    EntryDialog edialog(*this, "<big>New Product</big>", true, Gtk::MESSAGE_QUESTION, Gtk::BUTTONS_OK_CANCEL);
    edialog.set_secondary_text(prompt, true);
    if(edialog.run() == Gtk::RESPONSE_CANCEL) throw std::runtime_error{"CANCEL"};
    return edialog.get_text();
}
double Mainwin::get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}
int Mainwin::get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch (std::invalid_argument& e) {
            prompt = "Invalid value, please try again:";
        }
    }
}
void Mainwin::on_about_click() {
	Gtk::AboutDialog dialog;
	dialog.set_transient_for(*this);
	dialog.set_program_name("MANGA Mania");
	dialog.set_version("Version 1.3.1");
	dialog.set_copyright("Copyright 2020-2023");
	dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
	std::vector < Glib::ustring > authors = {"Alexander Martinez"};
	dialog.set_authors(authors);
	dialog.run();
}
void Mainwin::on_open_click() {
	Gtk::FileChooserDialog dialog("Please choose a file",
		Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);

	auto filter_manga = Gtk::FileFilter::create();
	filter_manga->set_name("MANGA files");
	filter_manga->add_pattern("*.manga");
	dialog.add_filter(filter_manga);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	dialog.set_filename("untitled.manga");

	dialog.add_button("_Cancel", 0);
	dialog.add_button("_Open", 1);

	int result = dialog.run();
	if (result == 1) {
		try {
			filename = dialog.get_filename();
			std::ifstream ifs{filename};			
			delete store; store = nullptr;
			store = new Store{ifs};
            if(!ifs.eof()) throw std::runtime_error{"Error reading file" + filename};
			on_view_products_click();
		} catch(std::exception e) {
			Gtk::MessageDialog{*this, "Unable to open store" + std::string{e.what()},
				false, Gtk::MESSAGE_WARNING}.run();
			on_new_store_click(true);
		}
	}
}
void Mainwin::on_save_as_click() {
Gtk::FileChooserDialog dialog("Please choose a file",
		Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
	dialog.set_transient_for(*this);

	auto filter_manga = Gtk::FileFilter::create();
	filter_manga->set_name("MANGA files");
	filter_manga->add_pattern("*.manga");
	dialog.add_filter(filter_manga);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	dialog.set_filename("untitled.manga");

	dialog.add_button("_Cancel", 0);
	dialog.add_button("_Save", 1);

	int result = dialog.run();
	if (result == 1) {
		filename = dialog.get_filename();
		on_save_click();
	}
}
void Mainwin::on_save_click() {
	try {
        std::ofstream ofs{filename};
        store->save(ofs);
		if(!ofs) throw std::runtime_error{"Error writing file" + filename};
    	} catch(std::exception e) {
        	Gtk::MessageDialog{*this, "Unable to save store: " + std::string{e.what()}, 
				false, Gtk::MESSAGE_WARNING}.run();
    }
}
void Mainwin::on_new_customer_click() {
    try {
		Gtk::Dialog dialog {"Insert Customer", *this};
		Gtk::Grid grid;
		Gtk::Label label_name {"Name"};
		Gtk::Entry entry_name;
		grid.attach(label_name, 0, 0, 1, 1);
		grid.attach(entry_name, 1, 0, 2, 1);    
		Gtk::Label label_phone {"Phone"};
		Gtk::Entry entry_phone;
		grid.attach(label_phone, 0, 2, 1, 1);
		grid.attach(entry_phone, 1, 2, 2, 1);
		Gtk::Label label_email {"Email"};
		Gtk::Entry entry_email;
		grid.attach(label_email, 0, 4, 1, 1);
		grid.attach(entry_email, 1, 4, 2, 1);
		dialog.get_content_area()->add(grid);   
		dialog.add_button("Insert", Gtk::RESPONSE_OK);
		dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
		int response;
		dialog.show_all();
		while((response = dialog.run()) == Gtk::RESPONSE_OK) {
        	if (entry_name.get_text().size() == 0) {entry_name.set_text("*required*"); continue;}
        	std::string customer_info = entry_name.get_text() + "\n" +
				entry_phone.get_text() + "\n" + entry_email.get_text();

         // Just display the information right back. In most applications, this is where you'd
         //   create a new object and add it to a std::vector or other container
         	Gtk::MessageDialog{*this, "You entered \n\n" + customer_info}.run();
		//store->add_customer(*(new Customer{entry_name, entry_phone, entry_email}));
    	on_view_customers_click();			
		break;
    	}
		}	catch(std::exception& e) {
	}
}

