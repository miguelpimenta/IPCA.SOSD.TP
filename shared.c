/*#########################################################################
# Created By: 	Miguel Pimenta
# Date: 		14-12-2016, 21:56
# Project:		Trabalho SOSD
# Filename:		shared.c
#########################################################################*/

#include "shared.h"

// Separar linha de comando em array de parametros
void SepararCmd(char* cmd, char** params) {       
    for (int i = 0; i < NUM_PARAMS; i++) 
	{
        params[i] = strsep(&cmd, " ");
        if(params[i] == NULL) 
		{
			break;
		}
    }
}

void RemoverExtensao(const char *user, int tamExt)
{
    int len = strlen(user);
    printf(CYELLOW "\t\t\t%.*s" CRESET "\n", len - tamExt, user + 0);
}

// Verifica se Diretoria existe
int VerificaDir() {
    struct stat sb;

    if (stat(FILESPATH, &sb) == 0 && S_ISDIR(sb.st_mode))
    {
        //printf("\t%s existe\n",FILESPATH);
		return 1;
    }
    else
    {
		mkdir(FILESPATH, 0700);
        printf(CYELLOW "\n\tA directoria \"%s\" não existe. Mas foi criada.\n" CRESET "\n", FILESPATH);
		return 0;
    }
}

int ExecutarCmd(char** params, bool userLogged, char* user) {	
	
	int childStatus = 0;
	char* error;
		
    // Fork
    pid_t pid = fork();	

    // Erro
    if (pid == -1) 
	{
        error = strerror(errno);        
		printf(CRED "\t%s" CRESET "\n", error);
        return 1;
    }
   
    else if (pid == 0) 
	{		
		char cmdPrefix[CMD_SIZE] = "./";
  		strcat (cmdPrefix, params[0]);		
		params[0] = cmdPrefix;
		
        // Executar comando	com login	
		if (userLogged)
		{	
			if (strcasecmp (params[0], CMD_CONSULTAMSG) == 0 || strcasecmp (params[0], CMD_RETIRAMSG) == 0)
			{
				params[1] = user;
			}
			/*
			if (strcasecmp (params[0], CMD_ENTREGAMSG) == 0)
			{				
							
			}*/	
			execvp (params[0], params); 			
		}
		// Executar comando	sem login
		else
		{			
        	execvp (params[0], params);  
		}

        // Erro
        error = strerror(errno);
		printf(CRED "\t%s: %s" CRESET "\n", params[0], error);
        return 0;
    }

    // Processo Pai
    else 
	{   
        waitpid(pid, &childStatus, 0);
        return 1;
    }
}

