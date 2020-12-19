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
	int marche = 0;
	int timeout = 1;

	while(a != 1)
	{

		        /* Affichage */
	   	dclear(C_WHITE);
	        dimage(x,40,marche ? &img_personnagemarche : &img_personnage);
                dupdate();

                /* Réinitialisation des infos du frame précédent */
	        marche = 0;

	       /* Lecture des entrées */
	       key = getkey_opt(GETKEY_DEFAULT, &timeout).key;
	       if(key == KEY_EXE)
                       a = 1;
	       if(key == KEY_RIGHT)
		       marche = 1;

	       /* Simulation du monde */
	       if(marche)
		       x = x+1;

	       /* Délai */
	       sleep_us(25000);
	}
	getkey();
	return 1;
}
