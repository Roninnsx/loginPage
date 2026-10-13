#include <iostream>
#include "Mask.h"
#include <unistd.h>//para usar STDIN_FILENO
#include <string.h>
#include <fstream>

using namespace std;
struct User{
	string name;
	string pass;
	unsigned int id; //id cannot be a negative number
	string email;
};

void login();
void Register();
void ListUsers();


std::string username, userpass;

int main(){
	
	char opc;
	std::cout<<"Welcom to Login Page\n";
	std::cout<<"Please entar a option\n[1] Register\n[2]Login\n[3]exit\n";
	
	while(true){
		std::cin>>opc;
		switch(opc){
			case '1':
				
				Register();
				break;
			case '2':
				
				login();
				break;
		}
		if(opc == '3'){
			std::cout<<"GOOD BYE\n";
			break;
		}

		std::cout<<"[1]Register\n[2]Login\n[3]exit\n";
	}
	
}


void Register(){
		
	ofstream file;
	std::string pass;
	file.open("dados.txt");//cria o arquivo json

	cout<<"Enter name:\n";
	cin.ignore();
	getline(cin, username);

	cout<<"Enter passwd:\n";
	userpass = lerSenha();
	cout<<"Confirm passwd\n";
	pass = lerSenha();

		if(userpass != pass){
			cout<<"Pass not are the same please enter a new pass"<<endl;
			Register();
		}
		else{

			file<<username<<"\t"<<userpass<<endl;
			cout<<"User add sucesfully :)"<<endl;
		}

	file.close();		
}

void login(){

	std::string idname, idpass;
		ifstream file;
		file.open("dados.txt");
	cout<<"enter a name:\n";
	cin.ignore();
	getline(cin, idname);
	cout<<"Enter a passd:\n";
		idpass = lerSenha();
	
	std::string name, pass;
	while(getline(file, name, '\t') && file>>pass){
		if(idname == name && idpass == pass){
			cout<<"Welcome"<<endl;
		}else{
			cout<<"Name or pass are diferent :("<<endl;
		}
	}
		std::cout<<"Nome: "<<idname<<" pass: "<<idpass<<std::endl;
	
}
