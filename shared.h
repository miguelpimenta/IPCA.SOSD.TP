/*#########################################################################
# Created By: 	Miguel Pimenta
# Date: 		14-12-2016, 21:56
# Project:		Trabalho SOSD
# Filename:		shared.h
#########################################################################*/

#ifndef SHARED_H
#define SHARED_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h> 
//C99
#include <stdbool.h>

// Cores para texto
#define CMAGEN   "\x1b[35m"
#define CRED     "\x1b[31m"
#define CGREEN   "\x1b[32m"
#define CYELLOW  "\x1b[33m"
#define CBLUE    "\x1b[34m"
#define CCYAN    "\x1b[36m"
#define CRESET   "\x1b[0m"
// Contantes
#define CMD_SIZE 100
#define MSG_SIZE 1000
#define MSG_DB_SIZE 10000
#define NUM_PARAMS 10
#define FILESPATH "MsgSysDB/"
#define USERFILEEXT ".txt"

const char *PROGRAMFOLDER = "MsgSysDB/";

const char *CMD_HELP1 = "ajuda";
const char *CMD_HELP2 = "help";
const char *CMD_LOGIN = "login";
const char *CMD_LOGOUT = "logout";
const char *CMD_EXIT1 = "exit";
const char *CMD_EXIT2 = "termina";
const char *CMD_ENTREGAMSG = "entregamsg";
const char *CMD_CONSULTAMSG = "consultamsg";
const char *CMD_RETIRAMSG = "retiramsg";
const char *CMD_CRIAUTILIZADOR = "criautilizador";
const char *CMD_LISTAUTILIZADOR = "listautilizador";
const char *CMD_REMOVEUTILIZADOR = "removeutilizador";

struct stat FileInfo;
char path[100] = {0};
char user[CMD_SIZE + 1] = {0};
bool userLogged = false;

void SepararCmd(char* cmd, char** params);

void RemoverExtensao(const char *user, int ext);

int VerificaDir();

int ExecutarCmd(char** params, bool userLogged, char* user);

#endif