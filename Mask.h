#ifndef MASK_H_
#define MASK_H_

#pragma once

#include <termios.h> // para mudar as config do terminal
#include <iostream>
#include <unistd.h>
#include <string>

std::string lerSenha(){
	std::string senha;
	char c;

	termios antigo, novo;

	tcgetattr(STDIN_FILENO, &antigo);
	novo = antigo; //copia as config dos terminal para o novo

	novo.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &novo);

	while((c = getchar()) != '\n' && c != EOF){
		senha += c;
		std::cout<<'*';
	}

	std::cout<<std::endl;

	tcsetattr(STDIN_FILENO, TCSANOW, &antigo);

	return senha; 
}

#endif /* MASK_H_ */
	

