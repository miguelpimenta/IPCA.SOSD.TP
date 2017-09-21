/*#########################################################################
# Created By: 	Miguel Pimenta
# Date: 		30-12-2016, 22:00
# Project:		Trabalho SOSD
# Filename:		retiramsg.c
#########################################################################*/

#include "shared.h"
#include "shared.c"

int main(int argc, char *argv[]) {

	// Variaveis (Declaração e Inicialização)	
	char path[100] = {0};	
	char fullMsgDB[MSG_DB_SIZE] = {0};
	char newFullMsgDB[MSG_DB_SIZE] = {0};
	int file = 0;
	char *pos;
	
	// Verifica se o cmd está completo
	if (argc < 2) {
		printf (CRED "\n\t%s" CRESET "\n", "Nao introduziu todos os parametros necessários");
		printf (CYELLOW "\t%s" CRESET "\n\n", "apagamsg <utilizador>");
		// Termina
		return (EXIT_FAILURE);
	}

	strcpy (path, FILESPATH);
	strcat (path, argv[1]);	
	strcat (path, USERFILEEXT);
	
	// Verificar se utilizador existe
	if (stat (path, &FileInfo) == -1 ) 
	{
		printf(CRED "\n\t%s" CRESET "\n\n", "O utilizador nao existe!");
		return (EXIT_FAILURE);
	}	

	file = open (path, O_RDONLY);
	
	if (FileInfo.st_size == 0)
	{
		printf (CRED "\n\t%s" CRESET "\n\n", "O ficheiro está vazio!!");	
	}
	else
	{
		read (file, &fullMsgDB, MSG_DB_SIZE);

		close (file);

		// 1ª Ocorrencia \n
		// The strchr() function returns a pointer to the first occurrence of the character c in the string s.
		// http://man7.org/linux/man-pages/man3/strchrnul.3.html
		pos = strchr (fullMsgDB, '\n');

		// The strcpy() function copies the string pointed to by src, including the terminating null byte ('\0'), to the buffer pointed to by dest. The strings may not overlap, and the destination string dest must be large enough to receive the copy. Beware of buffer overruns! (See BUGS.)
		// The strncpy() function is similar, except that at most n bytes of src are copied. Warning: If there is no null byte among the first n bytes of src, the string placed in dest will not be null-terminated.
		// https://linux.die.net/man/3/strncpy
		strncpy (newFullMsgDB, pos + 1, strlen (pos));

		file = open (path, O_WRONLY | O_TRUNC);

		write (file, newFullMsgDB, strlen (newFullMsgDB));

		close (file);
		
		printf (CGREEN "\n\t%s" CRESET "\n\n", "1ª mensagem removida com sucesso!!");	
	}

	return (EXIT_SUCCESS); 
}
