#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

int main()
{

    inicia_allegro(800,600);
    inicia_audio(70,70);

    grafica();

    readkey();

return 0;
}
END_OF_MAIN();



void inicia_allegro(int ANCHO_ , int ALTO_)
{
   allegro_init();
   install_keyboard();
   set_color_depth(32);
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, ANCHO_, ALTO_, 0, 0);
}


int inicia_audio(int izquierda, int derecha)
{
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0)
    {
       allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
       return 1;
    }
	set_volume(izquierda, derecha);
    return 0;
}


void grafica()
{
    int i=0,x=50,y=100;
    int arrg[10]={10,2,8,15,30,29,45,1,5,4};

    srand(time(NULL));
    for(i; i<10; i++)
    {
        arrg[i]=rand()%50;
        printf("%d \n", arrg[i]);
    }

    for(i=0; i<10; i++)
    {
        line(screen, x, 550-arrg[i]*10, y, 550-arrg[i+1]*10, palette_color[15]);
        x+=50;
        y+=50;

        if(i==8)
        {
            x=y=0;
        }

   //   w=arrg[i];
   //   textout(screen, font, w, 600-x, 600-y, palette_color[15]);
    }

}



