//
// Created by Kwecky on 13/09/2020.
//

#ifndef OVING4_PART2_H
#define OVING4_PART2_H
#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::VBox vbox;
    Gtk::Entry firstNameEntry;
    Gtk::Entry lastNameEntry;
    Gtk::Button button;
    Gtk::Label resultText;
    Gtk::Label firstNameText;
    Gtk::Label lastNameText;

    Window() {
        firstNameText.set_text("First name");
        lastNameText.set_text("Last name");
        button.set_label("Combine names");
        button.set_sensitive(false);

        vbox.pack_start(firstNameText);
        vbox.pack_start(firstNameEntry);
        vbox.pack_start(lastNameText);
        vbox.pack_start(lastNameEntry);  //Add the widget entry to vbox
        vbox.pack_start(button); //Add the widget button to vbox
        vbox.pack_start(resultText);  //Add the widget resultText to vbox

        add(vbox);  //Add vbox to window
        show_all(); //Show all widgets

        lastNameEntry.signal_changed().connect([this]() {
            button.set_sensitive(!(firstNameEntry.get_text().compare("") == 0 || lastNameEntry.get_text().compare("") == 0));
        });

        firstNameEntry.signal_changed().connect([this]() {
            button.set_sensitive(!(firstNameEntry.get_text().compare("") == 0 || lastNameEntry.get_text().compare("") == 0));
        });

        button.signal_clicked().connect([this]() {
            resultText.set_text("Name: " + firstNameEntry.get_text() + ", " + lastNameEntry.get_text());
        });
    }
};

#endif //OVING4_PART2_H
