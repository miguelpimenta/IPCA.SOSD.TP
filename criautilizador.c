/*#########################################################################
# Created By: 	Miguel Pimenta
# Date: 		14-12-2016, 21:56
# Project:		Trabalho SOSD
# Filename:		criautilizador.c
#########################################################################*/

#include "shared.h"
#include "shared.c"

/* TODO:
	- Password
	- Verificar user por Upper/Lower case
*/

/*
	Cria ficheiro de utilizador para registo de mensagens.
*/
int main(int argc, char *argv[]) {

	// Variaveis (Declaração e Inicialização)
	char path[100] = {0};
	int file = 0; 
	
	// Path ficheiros utilizador
	strcpy(path, FILESPATH);	

	// Verifica se comando tem nome de utilizador a criar
	if (argc < 2)
	{
		printf (CRED "\n\t%s" CRESET "\n", "Não introduziu nome de utilizador a criar");
		printf ("\t%s\n", "\"criautilizador <nome do utilizador>\"");
		// Termina
		return (EXIT_FAILURE);
	}
	// Cria ficheiro de utilizador
	else
	{		
		strcat (path, argv[1]);			
		strcat (path, USERFILEEXT);
		file = open(path, O_RDWR | O_CREAT | O_EXCL, 0777);
		if (file != -1)
		{
			printf (CGREEN "\n\t%s" CYELLOW "%s" CGREEN "%s" CRESET "\n\n", "Utilizador \"", argv[1] ,"\" criado com sucesso!!");		
		}
		else 
		{
			printf (CRED "\n\t%s" CYELLOW "%s" CRED "%s" CRESET "\n\n", "Utilizador \"", argv[1] ,"\" já existe.");				
		}
		// Liberta/Fecha ficheiro
		close (file);		
	}
	// Termina
	return (EXIT_SUCCESS);	
}
