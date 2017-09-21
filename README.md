# IPCA.SOSD.TP
Trabalho Prático - SOSD (Sistemas Operativos e Sistemas Distribuídos) 2016/2017

Este trabalho prático tem como objetivo a aplicação prática dos conceitos de gestão de processos e de ficheiros, assim como a aplicação da comunicação entre processos.
O trabalho deverá ser realizado em grupos de 2 elementos, excecionalmente de apenas um elemento, devidamente justificado ao docente.

Parte 1) Implementação de comandos para gestão de mensagens

De modo a permitir que múltiplos utilizadores possam deixar mensagens entre si, pretende-se implementar um conjunto de comandos que apoiem na criação, armazenamento e consulta de mensagens. Para tal, deverão ser implementados em C os seguintes comandos, como programas distintos, sendo que todas as mensagens deverão ser armazenadas num ficheiro individual por utilizador. Estas aplicações deverão usar uma mesma diretoria base para conter todas as caixas de correio dos utilizadores.

a) entregamsg <utilizador> <utilizador destino> <mensagem> - recolhe e armazena na caixa de correio do utilizador destino a mensagem (neste caso mensagem é uma frase de texto sem quebras de linhas).
b) consultamsg <utilizador> - mostra todas as mensagens recebidas para um utilizador.
c) retiramsg <utilizador> - remove a primeira mensagem da caixa de correio de um utilizador.
d) criautilizador <utilizador> - cria uma nova caixa de correio para um utilizador.
e) removeutilizador <utilizador> - remove a caixa de correio de um utilizador, desde que esteja vazia.
f) listautilizador – lista todas as caixas de correio criadas.

Parte 2) Implementação de um interpretador de comandos para gestão de mensagens.

Para que os utilizadores não tenham de fazer uso direto do interpretador de comandos (Bash shell) para executar os comandos anteriores, pretende-se criar um interpretador para estes comandos específicos de gestão de mensagens, que recebe uma cadeia de caracteres do utilizador, através da consola, indicando o comando e argumentos, sendo que o comando respetivo será executado como um novo processo. O programa deve mostrar o símbolo “%” como indicação de que está pronto para receber comandos do utilizador.

O programa deve executar o comando através de primitivas de execução genérica de processos tendo como referência a funcionalidade da função system(3), mas sem fazer uso da mesma. Adicionalmente, pode considerar que a execução do interpretador deve ser suspensa até o comando indicado estar concluído, e pode também o interpretador indicar se o comando concluiu com sucesso ou não. O programa deve permitir executar vários comandos sequencialmente, isto é, um a seguir ao outro, até o utilizador indicar o comando especial "termina" que termina o interpretador.

Para facilitar ao utilizador a indicação do seu nome de utilizador de cada vez que os comandos são executados, o interpretador deve começar por receber um comando de sessão que identifica qual o utilizador a ser usado para os comandos seguintes. 
Exemplo:
% utilizador <nome>
% consultamsg
% entregamsg destino “Ola, fica aqui uma mensagem.”
% termina
