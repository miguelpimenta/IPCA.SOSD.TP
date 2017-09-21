/*#########################################################################
# Created By: 	Miguel Pimenta
# Date: 		17-12-2016, 23:00
# Project:		Trabalho SOSD
# Filename:		msgsys.c
#########################################################################*/

#include "shared.h"
#include "shared.c"

int ShellLoop();

int main() {
		
	// Titulo Shell
	printf("\033]0;SOSD Shell\007\" ");
	// Limpar Shell
	printf("\033[2J\033[1;1H");
	// Startup Shell
	printf(CYELLOW "\t%s" CRESET "\n","+-+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+");
	printf(CCYAN "\t%s" CRESET "\n","|S|.|O|.|S|.|D|.| |M|s|g| |S|y|s|t|e|m|");
	printf(CYELLOW "\t%s" CRESET "\n" ,"+-+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+-+-+-+");
	printf(CCYAN"\t%s" CRESET "\n" ,"\"ajuda\" para ajuda. \"termina\" para sair.");
	
	// Verificar se existe dir de trabalho
	VerificaDir();
	
	// Inicio do loop
	ShellLoop();	

    return 0;
}

int ShellLoop() 
{
	
	// Variaveis (Declaração e Inicialização)
	char cmd[CMD_SIZE + 1] = {0};	
    char* params[NUM_PARAMS + 1] = {0};		
	
	while(1) 
	{  						
        printf(CMAGEN "%s" CRESET, " % ");
        // Ler linha de comando
		fgets(cmd, sizeof(cmd), stdin);

        // Remove "\n" e substitui por NULL "\0"
		cmd[strlen(cmd)-1] = '\0';

        // Separar comando em array de parametros
        SepararCmd(cmd, params);
        
		/* The strcasecmp() function compares the two strings s1 and s2, ignoring the case of the characters. 
		It returns an integer less than, equal to, or greater than zero if s1 is found, respectively, 
		to be less than, to match, or be greater than s2.
		The strncasecmp() function is similar, except it only compares the first n bytes of s1.
		https://linux.die.net/man/3/strcasecmp */
		
		// Exit
		if (strcasecmp (params[0], CMD_EXIT1) == 0  || strcasecmp (params[0], CMD_EXIT2) == 0) {
			printf("\033[2J\033[1;1H");
			break;
		}
		
		// Linha vazia
		else if (strcmp (params[0], "\0") == 0) {
						
		}
		
		// Help	
		else if (strcasecmp (params[0], CMD_HELP1) == 0 || strcasecmp (params[0], CMD_HELP2) == 0)	{
			printf (CGREEN "\t%s" CRESET "\n", "Comandos disponiveis: ");
			printf (CBLUE "\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s" CRESET "\n", 
				   "listautilizador\n", "enviamsg\n", "consultamsg\n", "removemsg\n" , "login\\logout\n");
		}
		
		// Login				
		else if (strcasecmp (params[0], CMD_LOGIN) == 0) {
			if (params[1] == NULL)
			{
				printf (CRED "\n\t%s" CRESET "\n\n", "Comando imcompleto.\n \tFalta nome de utilizador.");				
			}
			else
			{
				// Verificar se utilizador existe
				strcpy (path, FILESPATH);
				strcat (path, params[1]);	
				strcat (path, USERFILEEXT);	
				if (stat (path, &FileInfo) == -1 ) 
				{
					printf(CRED "\n\t%s%s%s" CRESET "\n\n", "O utilizador \"", params[1], "\" nao existe!");
				}
				// TODO: Password
				//else if (strcmp (params[2], passWord)
				else
				{
					strcpy (user, params[1]);
					printf ("\033]0;SOSD Shell - %s%s\007\" ", "Utilizador: ", user);					
					printf ("\033[2J\033[1;1H");
					printf(CGREEN "\t%s%s%s" CRESET "\n\n", "Login utilizador \"", params[1], "\" efectuado com sucesso.");
					userLogged = true;
				}
			}
		}
		
		// Logout		
		else if (strcasecmp (params[0], CMD_LOGOUT) == 0) {
			if (userLogged == false)
			{
				printf (CRED "\n\t%s" CRESET "\n\n", "Não está nenhum utilizador ligado.");	
			}
			else
			{				
				printf ("\033]0;SOSD Shell\007\" ");
				printf ("\033[2J\033[1;1H");
				printf(CGREEN "\t%s%s%s" CRESET "\n\n", "Logout do utilizador \"", user, "\" efectuado com sucesso.");
				userLogged = false;
				strcpy (user, "\0");				
			}
		}
		
		// Executar comandos
		else if (strcasecmp (params[0], CMD_ENTREGAMSG) == 0 || strcasecmp (params[0], CMD_CONSULTAMSG) == 0 ||
				strcasecmp (params[0], CMD_RETIRAMSG) == 0 || strcasecmp (params[0], CMD_LISTAUTILIZADOR) == 0) {	
			if (ExecutarCmd(params, userLogged, user) == 0) 
			{
				break;
			}				
			/*if (ExecutarCmd(params) == 0) 
			{
				break;
			}*/	
		}
		
		// Comando inválido
		else {
			printf(CRED "\t%s" CRESET "\n", "Esse comando não pode ser executado nesta shell.");
		}
	}
	
	return (EXIT_SUCCESS);
}