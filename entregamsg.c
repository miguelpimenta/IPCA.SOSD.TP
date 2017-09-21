/*#########################################################################
# Created By: 	Miguel Pimenta
# Date: 		14-12-2016, 21:56
# Project:		SOSD
# Filename:		entregamsg.c
#########################################################################*/

#include "shared.h"

/*
	entregamsg <remetente> <destinatário> <mensagem>
	Insere (após verificar se remetente e distinatario existem) 
	no ficheiro do destinatário a mensagem do remetente
*/
int main(int argc, char *argv[]) {
	
	// Variaveis (Declaração e Inicialização)
	time_t timer;
	struct tm* tm_info;
	struct stat FileInfo;
	int file = 0;
	char remetente[30] = {0};
	char pathRemetente[100] = {0};
	char destinatario[30] = {0};
	char pathDestinatario[100] = {0};		
	char mensagem[MSG_SIZE] = {0};
	char dateTime[26] = {0};	
	
	// Current DateTime
    time(&timer);
    tm_info = localtime(&timer);
    strftime(dateTime, 26, "%d-%m-%Y %H:%M:%S", tm_info);
	
	// Info Remetente
	strcat (remetente, argv[1]);
	strcat (remetente, USERFILEEXT);	
	// Path ficheiro Remetente
	strcpy (pathRemetente, FILESPATH);
	strcat (pathRemetente, remetente); 
	
	// Info Destinatário
	strcat (destinatario, argv[2]); 
	strcat (destinatario, USERFILEEXT);	
	// Path ficheiro Destinatário
	strcpy (pathDestinatario, FILESPATH);
	strcat (pathDestinatario, destinatario);		

	// Verificar se o comando de entrada tem mensagem
	if (argc < 4)
	{
		printf (CRED "\n\t%s" CRESET "\n", "Nao introduziu nenhuma mensagem!");
		printf (CYELLOW "\t%s" CRESET "\n\n", "entregamsg <remetente> <destinatário> <mensagem>");
		return (EXIT_FAILURE);
	}	
	// Verificar se remetente existe
	else if (stat (pathRemetente, &FileInfo) == -1) 
	{		
		printf(CRED "\n\t%s" CRESET "\n\n", "O Remetente nao existe!");
		return (EXIT_FAILURE);
	}	
	// Verificar se destinatário existe
	else if (stat (pathDestinatario, &FileInfo) == -1 ) 
	{
		printf(CRED "\n\t%s" CRESET "\n\n", "O Destinatário nao existe!");
		return (EXIT_FAILURE);
	}
	// Construção e gravação em ficheiro da msg
	else
	{
		// Adiciona o Remetente e Data/Hora ao inicio da msg
		strcat (mensagem, dateTime);
		strcat (mensagem, " ");
		strcat (mensagem, argv[1]);		
		strcat (mensagem, " -> ");
		// Construir a mensagem
		for (int i = 3; i < argc; i++)
		{
			strcat (mensagem, argv[i]);
			strcat (mensagem, " ");			
		}
		strcat (mensagem, "\0");	
		strcat (mensagem, "\n");
		// Tamanho da msg
		size_t length = strlen (mensagem); 
		// Abrir ficheiro do Destinatário e adicionar msg
		file = open(pathDestinatario, O_WRONLY | O_APPEND);
		if (file >= 0) 
		{
			write (file, mensagem, length);
			close (file);
			printf (CGREEN "\n\t%s" CYELLOW "%s" CGREEN "%s" CRESET "\n\n", "Mensagem para \"", argv[2], "\" entregue com sucesso!!");			
			return (EXIT_SUCCESS);
		}
		else
		{
			//perror
			printf(CRED "\n\t%s" CRESET "\n\n", "Erro!!! Algo não funcionou como era suposto.");
			return (EXIT_FAILURE);
		}		
	}
}
