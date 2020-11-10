#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "store.h"
#include "customer.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_store_click(bool untitled = false);     // Create a new store
        void on_new_tool_click();      // Create a new tool product
        void on_new_plant_click();     // Create a new plant product
        void on_new_mulch_click();     // Create a new mulch product
        void on_view_products_click(); // Update the display
        void on_quit_click();          // Exit the game
		void on_save_click();		   // Save store
		void on_save_as_click();	   // Save store to specific location
		void on_open_click();		   // Open a previously saved store
		void on_about_click();		   // Shows the about section
		void on_view_customers_click();
		void on_new_customer_click();
        void on_view_orders_click();
        void on_new_order_click();
        
    private:
        int get_int(std::string prompt);
        double get_double(std::string prompt);
        std::string get_string(std::string prompt);
        void set_status(std::string status);       
        Store* store;               // The currently active store
        Gtk::Label* display;        // Status message display
        Gtk::Label* msg;		
        std::string filename;
};
#endif 

