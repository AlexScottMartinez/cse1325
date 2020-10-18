#include "entrydialog.h"

EntryDialog::EntryDialog(Gtk::Window& parent,
                         const Glib::ustring& message, 
                         bool use_markup, 
                         Gtk::MessageType type, 
                         Gtk::ButtonsType buttons, 
                         bool modal)
  : MessageDialog(parent, message, use_markup, type, buttons, modal), entry{new Gtk::Entry{}} {
    get_content_area()->pack_start(*entry);
    entry->show();                           
}

void EntryDialog::set_text (const Glib::ustring& text) {entry->set_text(text);}
Glib::ustring EntryDialog::get_text () const {return entry->get_text();}

