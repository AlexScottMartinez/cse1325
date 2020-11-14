#include "mainwin.h"
#include "entrydialog.h"
#include <fstream>

const std::string APPNAME = "MANGA Mania";

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

    //           O R D E R
    // Append Order to the Insert menu
    Gtk::MenuItem *menuitem_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_order->signal_activate().connect([this] {this->on_new_order_click();});
    insertmenu->append(*menuitem_order);

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

    //         O R D E R S
    // Append Orders to the View menu
    Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menuitem_orders->signal_activate().connect([this] {this->on_view_orders_click();});
    viewmenu->append(*menuitem_orders);

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

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    //     N E W   S T O R E
    // Add a new store icon
    Gtk::ToolButton *new_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_store_button->set_tooltip_markup("Create a new store, discarding any in progress");
    new_store_button->signal_clicked().connect([this] {this->on_new_store_click();});
    toolbar->append(*new_store_button);

    //     O P E N   S T O R E
    // Add a open store icon
    Gtk::ToolButton *open_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    new_store_button->set_tooltip_markup("Open an store");
    open_store_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*open_store_button);

    //     S A V E   S T O R E
    // Add a save store icon
    Gtk::ToolButton *save_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    save_store_button->set_tooltip_markup("Save an store");
    save_store_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*save_store_button);

    //     S A V E   S T O R E   A S
    // Add a save store as icon
    Gtk::ToolButton *save_store_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    new_store_button->set_tooltip_markup("Save as an store");
    open_store_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*save_store_as_button);

    Gtk::SeparatorToolItem *sep1 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep1);

    //     I N S E R T   C U S T O M E R
    // Add an icon for inserting customers
    Gtk::Image* customer_image = Gtk::manage(new Gtk::Image{"customer.png"});
    Gtk::ToolButton* insert_customer = Gtk::manage(new Gtk::ToolButton(*customer_image));
    insert_customer->set_tooltip_markup("Insert new customer");
    insert_customer->signal_clicked().connect([this] {this->on_new_customer_click();});
    toolbar->append(*insert_customer);

    //     I N S E R T   O R D E R
    // Add an icon for inserting order
    Gtk::Image* order_image = Gtk::manage(new Gtk::Image{"order.png"});
    Gtk::ToolButton* insert_order = Gtk::manage(new Gtk::ToolButton(*order_image));
    insert_order->set_tooltip_markup("Insert new order");
    insert_order->signal_clicked().connect([this] {this->on_new_order_click();});
    toolbar->append(*insert_order);

    Gtk::SeparatorToolItem *sep2 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep2);

    //     I N S E R T   T O O L
    // Add an icon for inserting tools
    Gtk::Image* tool_image = Gtk::manage(new Gtk::Image{"tool.png"});
    Gtk::ToolButton* insert_tool = Gtk::manage(new Gtk::ToolButton(*tool_image));
    insert_tool->set_tooltip_markup("Insert new tool");
    insert_tool->signal_clicked().connect([this] {this->on_new_tool_click();});
    toolbar->append(*insert_tool);

    //     I N S E R T   P L A N T
    // Add an icon for inserting plants
    Gtk::Image* plant_image = Gtk::manage(new Gtk::Image{"plant.png"});
    Gtk::ToolButton* insert_plant = Gtk::manage(new Gtk::ToolButton(*plant_image));
    insert_plant->set_tooltip_markup("Insert new plant");
    insert_plant->signal_clicked().connect([this] {this->on_new_plant_click();});
    toolbar->append(*insert_plant);

    //     I N S E R T   M U L C H
    // Add an icon for inserting mulchs
    Gtk::Image* mulch_image = Gtk::manage(new Gtk::Image{"mulch.png"});
    Gtk::ToolButton* insert_mulch = Gtk::manage(new Gtk::ToolButton(*mulch_image));
    insert_mulch->set_tooltip_markup("Insert new mulch");
    insert_mulch->signal_clicked().connect([this] {this->on_new_mulch_click();});
    toolbar->append(*insert_mulch);

    Gtk::SeparatorToolItem *sep3 = Gtk::manage(new Gtk::SeparatorToolItem());
    toolbar->append(*sep3);

    //     V I E W   C U S T O M E R
    // Add an icon for viewing all customers
    Gtk::Image* view_customer_image = Gtk::manage(new Gtk::Image{"view_customer.png"});
    Gtk::ToolButton* view_customer = Gtk::manage(new Gtk::ToolButton(*view_customer_image));
    view_customer->set_tooltip_markup("View all customers");
    view_customer->signal_clicked().connect([this] {this->on_view_customers_click();});
    toolbar->append(*view_customer);

    //     V I E W   O R D E R S
    // Add an icon for viewing all orders
    Gtk::Image* view_order_image = Gtk::manage(new Gtk::Image{"view_order.png"});
    Gtk::ToolButton* view_order = Gtk::manage(new Gtk::ToolButton(*view_order_image));
    view_order->set_tooltip_markup("View all orders");
    view_order->signal_clicked().connect([this] {this->on_view_orders_click();});
    toolbar->append(*view_order);

    //     V I E W   P R O D U C T S
    // Add a View Products button to the toolbar
    Gtk::Image* view_products_image = Gtk::manage(new Gtk::Image{"view_products.png"});
    Gtk::ToolButton* view_products_button = Gtk::manage(new Gtk::ToolButton(*view_products_image));
    view_products_button->set_tooltip_markup("View all products");
    view_products_button->signal_clicked().connect([this] {this->on_view_products_click();});
    toolbar->append(*view_products_button);

    // /////////////////////////// ////////////////////////////////////////////
    // M A I N   W I N D O W   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);

    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    
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
    set_status();
    std::string name = "Untitled";
	try {
		if(!untitled) name = get_string("New store name?");
		filename = "untitled.manga";
	} catch (std::exception& e) {
	}
	delete store; store = nullptr;
	store = new Store{name};
    if(!untitled) set_status("Created new store: " + name);
    set_title(APPNAME + " - " + store->name());
	on_view_products_click();
}
void Mainwin::on_new_tool_click() {
    set_status();
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        store->add_product(*(new Tool{name, price, description}));
        set_status("Added tool " + name);
    } catch(std::exception& e) {
    }
    on_view_products_click();
}
void Mainwin::on_new_plant_click() {
    set_status();
    try {
        std::string name = get_string("Name?");
        double price = get_double("Price?");
        std::string description = get_string("Description?");
        std::string species = get_string("Species?");
        double d = get_double("Exposure? (1) Shade (2) Part Sun (3) Sun");
        Exposure exposure = (d==1.0) ? Exposure::SHADE : ((d==3.0) ? Exposure::SUN : Exposure::PARTSUN);
        store->add_product(*(new Plant{name, price, description, species, exposure}));
        set_status("Added plant " + name);
    } catch(std::exception& e) {
    }
    on_view_products_click();
}
void Mainwin::on_new_mulch_click() {
    set_status();
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
        set_status("Added mulch " + name);
    } catch(std::exception& e) {
    }
    on_view_products_click();
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
    std::vector< Glib::ustring > artists = {
        "View all orders image,https://icons8.com/icons/set/order",
        "Insert Mulch image,https://www.pngitem.com/middle/ibTbwTm_alt-attribute-png-download-mulch-png-transparent-png/",
        "Insert Tool image,https://freepngimg.com/png/17964-tool-png",
        "Insert Plant image,https://commons.wikimedia.org/wiki/File:Tea_plant.png",
        "Insert Customer image,https://www.pngarts.com/explore/27292",
        "View all customers,https://toppng.com/marketing-automation-single-customer-view-single-view-of-customer-ico-PNG-free-PNG-Images_269172"};
    dialog.set_artists(artists);
	dialog.run();
}
void Mainwin::on_open_click() {
    set_status();
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
			on_view_products_click();
		} catch(std::exception e) {
			Gtk::MessageDialog{*this, "Unable to open store" + std::string{e.what()},
				false, Gtk::MESSAGE_WARNING}.run();
			on_new_store_click(true);
		}
	}
    set_status("Opened " + filename);
    set_title(APPNAME + " - " + store->name());
    on_view_products_click();
}
void Mainwin::on_save_as_click() {
    set_status();
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
    set_status();
	try {
        std::ofstream ofs{filename};
        store->save(ofs);
		if(!ofs) throw std::runtime_error{"Error writing file" + filename};
        set_status("Saved to " + filename);
    	} catch(std::exception e) {
        	Gtk::MessageDialog{*this, "Unable to save store: " + std::string{e.what()}, 
				false, Gtk::MESSAGE_WARNING}.run();
    }
}
void Mainwin::on_new_customer_click() {
        set_status();
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
        entry_phone.set_placeholder_text("xxx-xxx-xxxx");
		Gtk::Label label_email {"Email"};
		Gtk::Entry entry_email;
		grid.attach(label_email, 0, 4, 1, 1);
		grid.attach(entry_email, 1, 4, 2, 1);
        entry_email.set_placeholder_text("xxx@domain.com");
		dialog.get_content_area()->add(grid);   
		dialog.add_button("Insert", Gtk::RESPONSE_OK);
		dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
		int response;
		dialog.show_all();
		std::string name;
        while(dialog.run()) {
            try {
                name = entry_name.get_text();
                if(name.empty()) {entry_name.set_text("### Required ###"); continue;}
                Customer customer{name, 
                                entry_phone.get_text(),
                                entry_email.get_text()};
                store->add_customer(customer);
                set_status("Added customer " + name);
                break;
             } catch(std::exception& e) {
                Gtk::MessageDialog{*this, "Unable to create new customer " + name 
                                        + ": " + std::string{e.what()},
                    false, Gtk::MESSAGE_WARNING}.run();
                break;
            }
        }
        on_view_customers_click();		
}
void Mainwin::on_new_order_click() {
    set_status();
    int ordernum;
    std::ostringstream oss;
    
    // Select a customer
    {
      Gtk::Dialog dialog{"Order for which customer?", *this};
    
      Gtk::ComboBoxText cbt;
      for(int i=0; i<store->customers(); ++i) {
        oss.str(""); // clear the string stream
        oss << store->customer(i);
        cbt.append(oss.str());
      }
      cbt.set_active(store->customers()-1);
      dialog.get_content_area()->add(cbt);
    
      dialog.add_button("Start Order", 1);
      dialog.add_button("Cancel", 0);
    
      dialog.show_all();
    
      if(dialog.run() == 0) return; 
      ordernum = store->add_order(store->customer(cbt.get_active_row_number()));
      set_status("Created order " + std::to_string(ordernum));
    }
    
    // Select products
    {
      Gtk::MessageDialog dialog{*this, "Add to Order " + std::to_string(ordernum)};
      
      // Quantity (spin button)
      Gtk::HBox qbox;
      Gtk::Label lq{"Quantity"};
      qbox.add(lq);
      Gtk::SpinButton sb;
      sb.set_range(1.0, 99.0);
      sb.set_increments(1.0, 10.0);
      qbox.add(sb);
      dialog.get_content_area()->add(qbox);
      
      // Product (combo box text)
      Gtk::ComboBoxText cbt;
      for(int i=0; i<store->products(); ++i) {
        oss.str("");
        oss << store->product(i);
        cbt.append(oss.str());
      }
      dialog.get_content_area()->add(cbt);

      // Buttons
      dialog.add_button("Add to Order", 1);    
      dialog.add_button("Order Complete", 0);
    
      // Collect products
      while(true) {
        // Show current order
        oss.str("");
        oss << store->order(ordernum);
        dialog.set_secondary_text(oss.str());
        
        dialog.show_all();
    
        if(dialog.run() == 1)
          store->add_item(ordernum, store->product(cbt.get_active_row_number()), static_cast<int>(sb.get_value()));
        else
          break;
      }
    }
    
    // View the orders
    on_view_orders_click();
}
void Mainwin::on_view_orders_click() {
    std::string p = "<tt><u>Current Orders</u>\n";
    for(int i=0; i<store->orders(); ++i) {
        std::ostringstream oss;
        oss << store->order(i) << '\n';
        p += oss.str();
    }
    display->set_markup(p+"</tt>");
}
void Mainwin::set_status(std::string status) {
    msg->set_markup(status);
}

