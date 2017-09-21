/*#########################################################################
# Created By: 	Miguel Pimenta
# Date: 		14-12-2016, 21:56
# Project:		Trabalho SOSD
# Filename:		listautilizador.c
#########################################################################*/

#include "shared.h"
#include "shared.c"
	
/*
	Lista utilizadores existentes.
*/
int main() {	
	
	// Variaveis (Declaração e Inicialização)
	DIR *filesDir = NULL;	
	struct dirent *ent = NULL;
	
	// Acede a directoria e lista os ficheiros de utilizador.
	filesDir = opendir(FILESPATH);	
	printf(CGREEN "\n\t%s" CRESET "\n", "Utilizadores: ");	
	while ((ent = readdir(filesDir)) != NULL)
    {			
		if (!strcmp (ent->d_name, ".") || !strcmp (ent->d_name, "..")) 
		{
			continue;
		}		
		// Lista apenas caixas de msg de utilizadores
		if (strstr (ent->d_name, USERFILEEXT))
		{	
			int len = strlen(ent->d_name);	
  			printf(CYELLOW "\t\t\t%.*s" CRESET "\n", len - 4, ent->d_name);			
    	}
	}	
	printf("\n");
	
	// Liberta/Fecha acesso a dir.
	closedir (filesDir);	
	
	// Termina
	return (EXIT_SUCCESS);
}




