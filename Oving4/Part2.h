//
// Created by Kwecky on 13/09/2020.
//

#ifndef OVING4_PART2_H
#define OVING4_PART2_H
#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::VBox vbox;
    Gtk::Entry entry;
    Gtk::Button button;
    Gtk::Label label;

    Window() {
        button.set_label("Click here");

        vbox.pack_start(entry);  //Add the widget entry to vbox
        vbox.pack_start(button); //Add the widget button to vbox
        vbox.pack_start(label);  //Add the widget label to vbox

        add(vbox);  //Add vbox to window
        show_all(); //Show all widgets

        entry.signal_changed().connect([this]() {
            label.set_text("Entry now contains: " + entry.get_text());
        });

        entry.signal_activate().connect([this]() {
            label.set_text("Entry activated");
        });

        button.signal_clicked().connect([this]() {
            label.set_text("Button clicked");
        });
    }
};

#endif //OVING4_PART2_H
