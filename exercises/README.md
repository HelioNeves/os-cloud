# UFCSPA � Inform�tica Biom�dica

# Sistemas Operacionais � 19/02 � Prof. Jo�o Gluz

## Lista de Exerc�cios 1 � Exerc�cios sobre Processos, Sinais e Pipes

**(1)** Criar um programa que se abre em 2 processos. O processo pai imprime "eu sou o pai" e seu
_pid_. O filho imprime "eu sou o filho" e seu _pid_.

**(2)** Criar um programa que se abre em 2 processos e que possua pelo menos uma vari�vel global,
que deve ser inicializada antes da opera��o **_fork_** (). Depois verifique se o valor da vari�vel global
tamb�m � herdado pelo filho, imprimindo o valor dessa vari�vel em cada processo.

**(3)** Altere o programa do exerc�cio (3) atribuindo valores distintos a vari�vel global no processo pai
e no processo filho. Depois verifique se a altera��o da vari�vel do processo pai � vista pelo processo
filho e vice-versa.

**(4)** Fa�a um programa que cria um processo pai e um processo filho, depois faz o processo filho
imprimir N n�meros pares. A quantidade N de n�meros pares a ser impressa � passada como
par�metro (argumento) de linha de comando do programa. O processo pai espera o processo filho
terminar a execu��o e s� ent�o imprimir uma mensagem indicando que terminou sua execu��o.

**(5)** Fa�a um programa que implemente a primitiva **_system_** () usando **_execl_** () e **_fork_** (), isto �, fa�a o
c�digo do processo filho ser substitu�do pelo c�digo de um outro programa qualquer. O nome do
programa que ira substituir o c�digo do processo filho deve ser passado como par�metro de linha de
comando para o programa.

**(6)** Fa�a um programa que cria um processo filho e tamb�m um duto ( _pipe_ ) nomeado atrav�s da
fun��o **_pipe_** () e faz com que o processo pai leia do teclado e o processo filho imprima na tela. A
comunica��o entre os processos � atrav�s do duto.

**(7)** Fa�a um programa que cria um processo filho e tamb�m um duto nomeado atrav�s da fun��o
**_pipe_** () e faz com que o processo filho leia do teclado e o processo pai imprima na tela. A
comunica��o entre os processos � atrav�s do duto.

**(8)** Fa�a um programa que cria um processo filho e se conecta ao filho atrav�s de um duto (pipe)
que ser� utilizado para comunica��o bidirecional. A linha de comando deste programa deve ter dois
argumentos: o primeiro argumento define que opera��o aritm�tica ser� feita pelo processo filho: �-
a� para adi��o, �-s� para subtra��o, �-m� para multiplica��o e �-d� para divis�o; o segundo
argumento � um valor num�rico ponto flutuante que ser� usado na opera��o aritm�tica. O processo
pai l� valores do teclado e envia esses valores para o processo filho. O processo filho recebe os
valores do processo pai pelo duto de comunica��o pai para filho, executa a opera��o selecionada
pelos argumentos da linha de comando e envia o resultado de volta ao pai pelo duto de
comunica��o filho para pai. Os processos pai e filho se encerram quando for lido o valor 0.

**(9)** Fa�a dois programas distintos para testar a comunica��o por sinais: um programa mestre e um
programa escravo. Cada programa ser� executado como um processo independente em um terminal
distinto. Cada programa inicialmente imprime seu pid no terminal usando a fun��o **_getpid_** (). O
programa mestre envia pode enviar os sinais SIGUSR1, SIGUSR2 e SIGTERM para o programa
escravo atrav�s da fun��o **_kill_** () de acordo com a escolha do usu�rio. O programa escravo deve
capturar os sinais enviados pelo programa mestre com o uso da fun��o **_signal_** (). Cada vez que um
desses sinais for capturado deve ser impresso uma mensagem no terminal informando que essa
captura ocorreu. Tanto o programa mestre quanto o escravo encerram a execu��o quando o usu�rio
selecionar a op��o de envio de SIGTERM. O programa mestre deve esperar o fim do programa
escravo e depois informar na tela que isso ocorreu.


