/*
 ============================================================================
 Name        : mi_ram_hq.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conexion.h>
#include <nivel-gui/nivel-gui.h>
#include <nivel-gui/tad_nivel.h>
#include <curses.h>
#include <commons/collections/list.h>

#define ASSERT_CREATE(nivel, id, err)

int main(void) {
	//crear_server("6667","127.0.0.1",5);
	//ejemplo();
	NIVEL* nivel = crear_mapa();
	crear_server()
	crear_personajes(nivel, patota);
	return EXIT_SUCCESS;
}



int rnd() {
	return (rand() % 3) - 1;
}

int crear_mapa(){
		NIVEL* nivel;

		int cols, rows;
		int err;

		nivel_gui_inicializar();

		nivel_gui_get_area_nivel(&cols, &rows);

		nivel = nivel_crear("Test Chamber 04");
		return nivel;
		//Aca hacemos un while de 0 hasta la cantidad de tripulantes y los creamos/dibujamos

		nivel_gui_dibujar(nivel);

		while ( 1 ) {
			nivel_gui_dibujar(nivel);

			int key = getch();

			switch( key ) {

				case KEY_UP:
					err = item_desplazar(nivel, '#', 0, -1);
				break;

				case KEY_DOWN:
					err = item_desplazar(nivel, '#', 0, 1);
				break;

				case KEY_LEFT:
					err = item_desplazar(nivel, '#', -1, 0);
				break;
				case KEY_RIGHT:
					err = item_desplazar(nivel, '#', 1, 0);
				break;

				case 'w':
				case 'W':
					err = item_desplazar(nivel, '@', 0, -1);
				break;

				case 's':
				case 'S':
					err = item_desplazar(nivel, '@', 0, 1);
				break;

				case 'a':
				case 'A':
					err = item_desplazar(nivel, '@', -1, 0);
				break;

				case 'D':
				case 'd':
					err = item_desplazar(nivel, '@', 1, 0);
				break;

				case 'Q':
				case 'q':
					nivel_destruir(nivel);
					nivel_gui_terminar();
					return EXIT_SUCCESS;
				break;
			}

			if(err) {
				printf("WARN: %s\n", nivel_gui_string_error(err));
			}

			item_desplazar(nivel, '1', rnd(), rnd());
			item_desplazar(nivel, '2', rnd(), rnd());

			if (items_chocan(nivel, 'H', '@') || items_chocan(nivel, 'H', '#')) {
				caja_quitar_recurso(nivel, 'H');
			}

			if (items_chocan(nivel, 'F', '@') || items_chocan(nivel, 'F', '#')) {
				caja_quitar_recurso(nivel, 'F');
			}

			if (items_chocan(nivel, 'M', '@') || items_chocan(nivel, 'M', '#')) {
				caja_quitar_recurso(nivel, 'M');
			}

			if(items_chocan(nivel, '#', '@')) {
				item_borrar(nivel, '#');
			}
		}
}
