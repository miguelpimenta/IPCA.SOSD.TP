/*#########################################################################
# Created By: 	Miguel Pimenta
# Date: 		14-12-2016, 21:56
# Project:		SOSD
# Filename:		consultamsg.c
#########################################################################*/

#include "shared.h"

/*
	Lista as mensagens na caixa de um utilizador.
*/
int main(int argc, char *argv[]) {
	
	// Variaveis (Declaração e Inicialização)
	char *msg = NULL;
	char path[100] = {0};
	char line[MSG_SIZE + 11] = {0};
	int i, file;
	i = file = 0;
	
	if (argv[1] == NULL)
	{
		printf (CRED "\n\t%s" CRESET "\n\n", "Comando imcompleto.\n \tFalta nome de utilizador.");
		return (EXIT_FAILURE);
	}
	
	// Path do ficheiro
	strcpy (path, FILESPATH);
	strcat (path, argv[1]);
	strcat (path, ".txt");	
	
	// Verificar se utilizador existe
	if (stat (path, &FileInfo) == -1 ) 
	{
		printf(CRED "\n\t%s" CRESET "\n\n", "O utilizador nao existe!");
		return (EXIT_FAILURE);
	}
	
	// Abrir ficheiro e listar mensagens
	file = open(path, O_RDONLY);	
	if (file > 0)
	{
		//printf ("%d\n", file);	
		printf ("\n");		
		read (file, line, MSG_SIZE + 11);
		msg = strtok (line,"\n");
		i = 1;
		while (msg != NULL)
		{
			printf (CBLUE "\t%s%d" CCYAN "%s%s" CRESET "\n", "Msg ", i, " - ", msg);
			msg = strtok (NULL, "\n");
			i++;
		}
		printf ("\n");
	}
	else
	{
		printf(CRED "\n\t%s" CRESET, "Não foi possivel abrir o ficheiro de Mensagens.");
		printf(CYELLOW "\n\t%s" CRESET "\n\n", "Provavelmente esse utilizador não existe.");
	}
	// Fecha ficheiro
	close(file);
	
	// Termina
	return (EXIT_SUCCESS);
}


