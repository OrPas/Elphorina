#include <gint/display.h>
#include <gint/keyboard.h>
#include <gint/clock.h>

int main(void)
{
	extern bopti_image_t img_personnage;
	extern bopti_image_t img_personnagemarche;
        int a = 0;
	int x = 0;
	int key;
	int inAnimation = 0;
	int marche = 0;
	int timeout = 1;

	while(a != 1)
	{


		        /* Affichage */
	   	dclear(C_WHITE);
	        dimage(x,40,marche ? &img_personnagemarche : &img_personnage);
                dupdate();

                /* Réinitialisation des infos du frame précédent */
	        if(marche > 0)
		{
			marche--;
		}
	       /* Lecture des entrées */
	       clearevents();
	       
	       key = getkey_opt(GETKEY_DEFAULT, &timeout).key;
	       if(keydown(KEY_EXE))
                       a = 1;
	       if(keydown(KEY_RIGHT) && marche == 0)
	       {
		       marche = 5;
	               inAnimation = 1;
               }
	       /* Simulation du monde */
	       if(marche==0 && inAnimation == 1)
	       {
		       x = x+3;
	               inAnimation = 0;
               }
	       /* Délai */
	       sleep_us(25000);
	       if(x >= 140)
		       x = 0;
	       
	}
	getkey();
	return 1;
}
