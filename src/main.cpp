//main header file for GBAdvanceulator
//G++ Autocompiles all referenced files into a neat ELF file/EXE file

//includes
#include <iostream>
#include "./headder_files/version_data.h" //version data, imports GBA_EMU_VER and GBA_EMU_TYP
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xft/Xft.h>
#include <ft2build.h>
#include <string>
#include <sstream>
#include <ft2build.h>
#include FT_FREETYPE_H
#include "./headder_files/state_data.h"
#include "./getCWD.cpp"
#include "./gbacore.cpp"

//defines
#define CLOCK_SPD = 4.194

using namespace std;



int main(int argc, char* argv[]){
    string state = state_title;
    ostringstream titleStreaming;
    titleStreaming << GBA_EMU_NOM << " v" << GBA_EMU_VER << " " << GBA_EMU_TYP;
    if(GBA_EMU_MOD == 1){
        titleStreaming << " | " << GBA_EMU_MOD_NOM << " v" << GBA_EMU_MOD_VER << " " << GBA_EMU_MOD_TYP;
    }
    string titlez = titleStreaming.str();
    string todraw[] = {titlez, "1) Open ROM ", "2) Options", "3) About", "4) Github page", "5) exit"};
    if(GBA_EMU_MOD == 0){
        cout << "Gameboy Advanculator V" << GBA_EMU_VER << " " << GBA_EMU_TYP << endl;
    }
    else{
        cout << "Gameboy Advanculator V" << GBA_EMU_VER << " " << GBA_EMU_TYP << " | " << GBA_EMU_MOD_NOM << " v" << GBA_EMU_MOD_VER << " " << GBA_EMU_MOD_TYP << endl;
    }
    
    // Initialize X11
    Display* display = XOpenDisplay(NULL);
    if (!display) {
        // Handle error
        return -1;
    }

    // Create a window
    int screen = DefaultScreen(display);
    Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0, 480, 320, 0, BlackPixel(display, screen), WhitePixel(display, screen));
    ostringstream titleStream;
    titleStream << GBA_EMU_NOM << " v" << GBA_EMU_VER << " " << GBA_EMU_TYP;
    string title = titleStream.str();
    XStoreName(display, window, title.c_str());
    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    // Load font
    FT_Library ft;
    FT_Face face;
    if (FT_Init_FreeType(&ft)) {
        cerr << "Failed to initialize freetype library." << endl;
        return -1;
    }
    cout <<GetDirectory(argv[0]) <<endl;
    ostringstream f;
    f << GetDirectory(argv[0]) << "/assets/font.ttf";
    cout << "loading font: " << f.str().c_str() <<endl;
    if (FT_New_Face(ft, f.str().c_str(), 0, &face)) {
        cerr << "Failed to load font." << endl;
        return -1;
    }
    FT_Set_Pixel_Sizes(face, 0, 24); // Set font size

    // Enter the event loop
    XEvent event;
    bool quit = false;
    while (!quit) {
        XNextEvent(display, &event);
        switch (event.type) {
            case Expose: {
                // Redraw the window
                XClearWindow(display, window);

                XWindowAttributes attrs;
                XGetWindowAttributes(display, window, &attrs);

                // Render text
                XftDraw* draw = XftDrawCreate(display, window, DefaultVisual(display, screen), DefaultColormap(display, screen));
                XftColor color;
                color.color.red = 0x0000;
                color.color.green = 0x0000;
                color.color.blue = 0x0000;
                color.color.alpha = 0xffff;
                XftFont* xftFont = XftFontOpenName(display, screen, face->family_name);
                for(size_t i = 0; i < sizeof(todraw)/sizeof(todraw[0]); i++) {
                    XftDrawString8(draw, &color, xftFont, 30, 30+(i*20), (FcChar8*) todraw[i].c_str(), todraw[i].length());
                    cout << todraw[i].c_str() << " at Y coordinate:" << 30+(i*20) <<endl;
                }
                XftDrawDestroy(draw);


                break;
            }
            case KeyPress:
                KeySym key;
                char buffer[1];
                XLookupString(&event.xkey, buffer, sizeof(buffer), &key, NULL);
                switch (key) {
                    case XK_1:
                        if(state == "title"){
                            passover(4.194);
                        }
                        break;
                    case XK_2:
                        if(state == "title"){
                            //do menu shit here
                        }
                        break;
                    case XK_3:
                        if(state=="title"){
                            //change to about here
                        }
                        break;
                    case XK_4:
                        system("open https://github.com/aLibraryEnthusiast/Gameboy-Advanculator");
                        break;
                    case XK_5:
                        if(state == "title"){
                            exit(0);
                        }
                        break;
                    case XK_Up:
                        //UP
                        cout << "UP" <<endl;
                        break;
                    case XK_Down:
                        //DWN
                        cout << "DOWN" <<endl;
                        break;
                    case XK_Left:
                        //LFT
                        cout << "LEFT" <<endl;
                        break;
                    case XK_Right:
                        //RGT
                        cout << "RIGHT" <<endl;
                        break;
                    case XK_Z:
                        //A button
                        cout << "A" <<endl;
                        break;
                    case XK_X:
                        //B button
                        cout << "B" <<endl;
                        break;
                    case XK_z:
                        //A button
                        cout << "A" <<endl;
                        break;
                    case XK_x:
                        //B button
                        cout << "B" <<endl;
                        break;
                }
                break;

        }
    }

    // Clean up and exit
    FT_Done_Face(face);
    FT_Done_FreeType(ft);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    return 0;
}
