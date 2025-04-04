#include "FileDialog.hpp"
#include <gtkmm-3.0/gtkmm.h>
using namespace std;
Gtk::Main kit;
thread FileDialog::th;
void FileDialog::opendirectory(std::string* FilePath){
  Gtk::FileChooserDialog dialog("Выберите папку", Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
  dialog.add_button("_Выбрать", Gtk::RESPONSE_OK);
  dialog.add_button("_Отмена", Gtk::RESPONSE_CANCEL);
  string folderPath;
  dialog.signal_response().connect([&dialog,&folderPath](int response_id) {
    if (response_id == Gtk::RESPONSE_OK)
    {
      folderPath = dialog.get_filename();
           // return folderPath; 
    }
    dialog.close();
  });

  dialog.show();
  Gtk::Main::run(dialog);
  if(FilePath != nullptr){
    *FilePath = folderPath;
  }
  return;
}
