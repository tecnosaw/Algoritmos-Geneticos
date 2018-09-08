
#include <allegro.h>

int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,320,200,30,0);
    readkey();

    return 0;
}
END_OF_MAIN();

