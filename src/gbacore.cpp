//deals with opening and running GBA games
#include "./headder_files/default.h"
#include "./headder_files/version_data.h"
#include "./headder_files/state_data.h"
#include "./headder_files/fd.h"

//#include <QtWidgets>
char* ptr = (char*) malloc(sizeof(char));

using namespace pfd;
using namespace std;

int open_gba_file_fdh(unsigned long cpu_clock_speed){
    auto selection = pfd::open_file("Select a file", ".", {
        "Gameboy Advance ROMs", "*.gba"
    }).result();
    if (!selection.empty())
        std::cout << "User selected file " << selection[0] << "\n";
    return -1;
}
/*int open_gba_file_qt(int argc, char* argv[]){

    QApplication app(argc, argv);

    // Create a file dialog to prompt the user to select the Gameboy Advance file
    QFileDialog file_dialog;
    file_dialog.setNameFilter("Gameboy Advance files (*.gba)");
    file_dialog.setFileMode(QFileDialog::ExistingFile);

    // Show the file dialog and get the selected file path
    if (file_dialog.exec()) {
        QString file_path = file_dialog.selectedFiles().at(0);

        // Open and read the selected file using std::ifstream as shown in the previous examples
        std::ifstream file(file_path.toStdString(), std::ios::binary);
        // ...
    }

}*/

void passover(unsigned long cpu_clock_speed){
    if (!pfd::settings::available())
    {
        std::cout << "Portable File Dialogs are not available on this platform.\n";
        /*open_gba_file_qt(, cpu_clock_speed)*/
    }
    else{
        cout << open_gba_file_fdh(cpu_clock_speed);
    }
}