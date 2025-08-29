# ProjetoIHS
Projeto final da disciplina Interface Hardware/Software

Aluno: Gabryel Barreto Araujo
Matricula: 202200025500
Professor: Bruno Otavio Piedade Prado

O que é o projeto: O projeto consiste em um módulo que ao ser carregado no kernel do linux ele captura os eventos do teclado do computador e envia para um arduino uno. O arduino controla um buzzer que para cada letra ou número digitado ele emite o código morse.

Objetivo: Criar um meio alternativo para possibilitar que pessoas cegas ou com deficiência visual possam digitar em um computador(Obs: a pessoa precisa conhecer código morse para interpretar o som)

Instruções: Para compilar o módulo, execute no terminal: make, em seguida carregue o módulo no kernel usando: sudo insmod driver.ko. Em seguida compile o código que está na pasta arduíno e faça o upload para ele(Obs: Observar qual o nome do device file do arduíno e ajustar no drive.c, para que o módulo possa enviar os dados corretamente para o arduíno). No arduino que foi desenvolvido o projeto, foi conectado um buzzer ativo, com o lado positivo na porta 8 e o negativo no GND.

Demonstração de funcionamento: https://youtu.be/XcG66oCnag4
