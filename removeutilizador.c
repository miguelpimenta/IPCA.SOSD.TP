/*#########################################################################
# Created By: 	Miguel Pimenta
# Date: 		14-12-2016, 21:56
# Project:		Trabalho SOSD
# Filename:		removeutilizador.c
#########################################################################*/

#include "shared.h"
#include "shared.c"

/*
	Remove ficheiro de utilizador se não tiver dados.
*/
int main(int argc, char *argv[]) {

	// Variaveis (Declaração e Inicialização)
	struct stat FileInfo;
	char path[100] = {0};	
	
	// Path dos ficheiros utilizador
	strcpy (path, FILESPATH);
	
	// Verifica se o comando tem nome de utilizador
	if (argc < 2)
	{
		printf (CRED "\n\t%s" CRESET "\n\n", "Faltam dados. (Nome de Utilizador a remover)");
		// Termina
		return (EXIT_FAILURE);
	}	
	
	// Patch ficheiro utilizador
	strcat (path, argv[1]);
	strcat (path, USERFILEEXT);
	
	// Informação do ficheiro (Existe/Tamanho/...)
	stat (path, &FileInfo);	
	
	// Verifica se utilizador existe
	if (stat (path, &FileInfo) == -1) 
	{		
		//printf(CRED "\n\t%s" CRESET "\n\n", "O utilizador nao existe!");
		printf (CRED "\n\t%s" CYELLOW "%s" CRED "%s" CRESET "\n\n", "O Utilizador \"", argv[1] ,"\" não existe.");	
		return (EXIT_FAILURE);
	}	
	// Remove se estiver ficheiro estiver vazio
	else if (FileInfo.st_size == 0)
	{
		// Elimina ficheiro
		remove (path);		
		printf (CGREEN "\n\t%s" CYELLOW "%s" CGREEN "%s" CRESET "\n\n", "Utilizador \"", argv[1], "\" removido com sucesso!!");	
	}
	// Não remove pq contem dados
	else
	{		
		printf (CRED "\n\t%s" CYELLOW "%s" CRED "%s" CRESET "\n", "A caixa de mensagens do utilizador \"", argv[1] ,"\" não está vazia.");		
		printf (CYELLOW "\t%s" CRESET "\n\n", "Apague as mensagens da caixa primeiro.");	
	}
	// Termina
	return (EXIT_SUCCESS);
}
