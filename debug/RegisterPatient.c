#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>

char _userName[] = "admin";
char _passWord[] = "1234567";

// struct para datas
typedef struct  {
    int year;
    int month;
    int day;
} Date;

// struct para informações do paciente
typedef struct {
	char Name[100];
	int CPF;
	int CEP;
    Date _birthDate;
    Date _diagnosisDate;
    int age;
	bool Havediabetes;
	bool HaveObesity;
	bool HaveHypertension;
	bool HaveTuberculosis;
} Patient;

bool CreatePatientFile(Patient patient, char folder [100], int format){
	FILE *file = fopen(folder, "a");
	//formato que o arquivo será salvo
		switch (format){
	   		case 1:
				fprintf(file, "%s,%d,%d,%d,%i/%i/%i,%i/%i/%d,%d,%d,%d,%d;\n", patient.Name, patient.CPF,patient.CEP, patient.age, patient._birthDate.day,patient._birthDate.month,patient._birthDate.year,
						patient._diagnosisDate.day, patient._diagnosisDate.month, patient._diagnosisDate.year, patient.Havediabetes,
						patient.HaveHypertension,patient.HaveTuberculosis,patient.HaveObesity);
						fclose(file);
						return true;
			case 2:
				fprintf(file, "%s,%d;\n", patient.Name, patient.CEP);
					fclose(file);
					return true;
	   		default:
	   				fclose(file);
					return false;
		}
}
void BuildPatient(){
	system("cls");
	int conditional = 1;
	do{
		// instância das structs para armazenar dados do paciente
		Patient _patient;
		Date _birthDate;
		Date _diagnosisDate;

		//entrada de dados pelo usuário
		printf("\nInforme o nome do paciente:\n");
		ValidationString(&_patient.Name, "Informe o nome : ");
		system("cls");

		printf("Informe o CPF do paciente:\n");
		_patient.CPF = ValidationNumber("CPF : ");
		system("cls");

		printf("Informe o CEP do paciente:\n");
		_patient.CEP = ValidationNumber("CEP : ");
		system("cls");

		printf("Informe idade do paciente:\n");
		_patient.age = ValidationNumber("Idade : ");
		system("cls");

		printf("Informe o dia de nascimento do paciente:\n");
		_birthDate.day = ValidationNumber("Dia : ");
		system("cls");

		printf("Informe o mes de nascimento do paciente:\n");
		_birthDate.month = ValidationNumber("Mes : ");
		system("cls");

		printf("Informe o ano de nascimento do paciente:\n");
		_birthDate.year = ValidationNumber("Ano : ");
		system("cls");

		printf("Informe o dia do diagnostico do paciente:\n");
		_diagnosisDate.day = ValidationNumber("Dia : ");
		system("cls");

		printf("Informe o mes do diagnostico do paciente:\n");
		_diagnosisDate.month = ValidationNumber("Mes : ");
		system("cls");

		printf("Informe o ano do diagnostico do paciente:\n");
		_diagnosisDate.year = ValidationNumber("Ano : ");
		system("cls");

		printf("O Paciente tem diabete?:\nDigite <1> SIM - <0> NAO\n");
		_patient.Havediabetes = ValidationNumber("Digite uma das opcoes : ");
		system("cls");

		printf("O Paciente eh obeso?:\nDigite <1> SIM - <0> NAO\n");
		_patient.HaveObesity = ValidationNumber("Digite uma das opcoes : ");
		system("cls");

		printf("O Paciente eh hipertenso?:\nDigite <1> SIM - <0> NAO\n");
		_patient.HaveHypertension = ValidationNumber("Digite uma das opcoes : ");
		system("cls");

		printf("O Paciente ja contraiu tuberculose?:\nDigite <1> SIM - <0> NAO\n");
		_patient.HaveTuberculosis = ValidationNumber("Digite uma das opcoes : ");
		system("cls");

		_patient._birthDate = _birthDate;
		_patient._diagnosisDate = _diagnosisDate;

		printf("Dados do paciente:\n\n");
		// saída com os dados cadastrados do paciente
		printf("Nome %s\n", _patient.Name);
		printf("CPF %i\n", _patient.CPF);
		printf("Idade %d\n", _patient.age);
		printf("Data de Nascimento %i/%i/%i\n", _patient._birthDate.day, _patient._birthDate.month, _patient._birthDate.year);
		printf("Data do diagnostico %i/%i/%i\n", _patient._diagnosisDate.day, _patient._diagnosisDate.month, _patient._diagnosisDate.year);

		if(_patient.Havediabetes == 1)
			printf("Diabete? : SIM\n");
		else
			printf("Diabete? : NAO\n");

		if(_patient.HaveObesity == 1)
			printf("Obeso? : SIM\n");
		else
			printf("Obeso? : NAO\n");

		if(_patient.HaveHypertension == 1)
			printf("Hipertenso? : SIM\n");
		else
			printf("Hipertenso? : NAO\n");

		if(_patient.HaveTuberculosis == 1)
			printf("Turbeculose? : SIM\n");
		else
			printf("Turbeculose? : NAO\n\n");

		printf("\nDESEJA SALVAR ? <DIGITE 0> \nDESEJA REFAZER O CADASTRO ?<1>\n");
		scanf("%i", &conditional);

		if(conditional == 0){
			//cria arquivo com os dados do usuário
			bool result = CreatePatientFile(_patient, "Pacientes.txt", 1); // 1 - true, 2 - false
			if(result)
				printf("Paciente cadastrado com sucesso!\nSegue os dados cadastrados:\n\n");
			else
				printf("Ocorreu um erro, entre em contato com o suporte.\n\n");

			system("PAUSE");
		}
		system("cls");

	}while(conditional == 1);

}
void GetPatients(){
	//checa se existe
	FILE *file = fopen("Pacientes.txt", "r");

	if(file == NULL){
		printf("Nenhum paciente cadastrado.\n");
	}else{
		//ler o arquito txt e exibir na saida do console todos os pacientes
		system("cls");
		char string [10000];
		printf("Pacientes Cadastrados:\n\n");
		int count = 1;
		// exibe pacientes cadastrados
		while(fgets(string, 10000, file) != NULL){
				Patient _patient;

				char *item = strtok(string, ",");
				snprintf(_patient.Name, sizeof(_patient.Name), "%s", item);

				item = strtok(NULL, ",");
				_patient.CPF = atoi(item);

				item = strtok(NULL, ",");
				_patient.CEP = atoi(item);

				item = strtok(NULL, ",");
				_patient.age = atoi(item);

				item = strtok(NULL, ",");
				char* birthDate = item;

				item = strtok(NULL, ",");
				char* diagnosisDate = item;

				item = strtok(NULL, ",");
				_patient.Havediabetes = atoi(item);

				item = strtok(NULL, ",");
				_patient.HaveObesity = atoi(item);

				item = strtok(NULL, ",");
				_patient.HaveHypertension = atoi(item);

				item = strtok(NULL, ",");
				_patient.HaveTuberculosis = atoi(item);

				printf("----------------------\n");
				printf("- Paciente %i\n", count++);

				printf("Nome : %s\n", _patient.Name);
				printf("CPF : %d\n", _patient.CPF);
				printf("CEP : %d\n", _patient.CEP);
				printf("Idade : %d\n", _patient.age);
				printf("Data de Nascimento : %s\n", birthDate);
				printf("Data do diagnostico : %s\n", diagnosisDate);

				if(_patient.Havediabetes == 1)
					printf("Diabete? : SIM\n");
				else
					printf("Diabete? : NAO\n");

				if(_patient.HaveObesity == 1)
					printf("Obeso? : SIM\n");
				else
					printf("Obeso? : NAO\n");

				if(_patient.HaveHypertension == 1)
					printf("Hipertenso? : SIM\n");
				else
					printf("Hipertenso? : NAO\n");

				if(_patient.HaveTuberculosis == 1)
					printf("Turbeculose? : SIM\n");
				else
					printf("Turbeculose? : NAO\n\n");

				}
				printf("----------------------\n");

	}
	fclose(file);
	system("PAUSE");
	system("cls");
}
void Login(){
    char userScan[15];
    char pwScan[15];
    int login_efetuado = 0; //0 - Falso e  1 - Verdadeiro
    printf("-----------------------------LOGIN------------------------------------------\n\n");

    while(!login_efetuado){
        printf("Digite o Usuario: ");
        scanf("%s", userScan);

        printf("Digite a Senha: ");
        scanf("%s", pwScan);

        if (strcmp(_userName, userScan) == 0 && strcmp(_passWord, pwScan) == 0){
            system("cls");
            login_efetuado = 1;
        }
        else
            printf("\n\nUsuario ou senha invalidos!\n\n");
    }
}
int ValidationNumber(char message [100]){

	char digitado[50];//armazena o que foi digitado pelo usuário
    char c;//armazena cada caractere digitado pelo usuário
    int i=0;//variável para controlar o índice do vetor de caracteres
    int numero=0;//variável para armazenar a conversão do que foi digitado pelo usuário

    printf (message);

    do
    {
       c=getch();//captura o caractere digitado pelo usuário
       if (isdigit(c)!=0)//se for um número
       {
          digitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
          digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
          i--;//o índice do vetor de caracteres é decrementado
          printf("\b \b");//o caractere digitado é apagado da tela
       }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

    digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
    numero = atoi(digitado);//a variável numero recebe o valor do vetor de caracteres convertido para inteiro
    return numero;
}
void ValidationString(char *digitado, char message[100]){

    char c;//armazena cada caractere digitado pelo usuário
    int i=0;//variável para controlar o índice do vetor de caracteres

    printf (message);

    do
    {
       c=getch();//captura o caractere digitado pelo usuário
       if (isalpha(c)!=0 || c==32)//se for uma letra
       {
          digitado[i] = c;//armazena no vetor de caracteres
          i++;//incrementa o índice do vetor de caracteres
          printf ("%c", c);//exibe o caractere digitado
       }
       else if(c==8&&i)//se for pressionada a tecla BACKSPACE e houver caracteres já digitados
       {
          digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string
          i--;//o índice do vetor de caracteres é decrementado
          printf("\b \b");//o caractere digitado é apagado da tela
       }
    }while(c!=13);//o loop vai ser executado até que a tecla pressionada seja o ENTER (código 13 na tabela ASCII)

    digitado[i]='\0';//o índice atual do vetor de caracteres recebe a terminação da string

}
void SendPatient(){
	int count = 0;
	//checa se existe
	FILE *file = fopen("Pacientes.txt", "r");

	if(file == NULL){
		printf("Nenhum paciente cadastrado.\n");
	}else{
		//ler o arquito txt e exibir na saida do console todos os pacientes
		system("cls");
		char string [10000];

		while(fgets(string, 10000, file) != NULL){
				Patient _patient;

				char *item = strtok(string, ",");
				snprintf(_patient.Name, sizeof(_patient.Name), "%s", item);

				item = strtok(NULL, ",");
				_patient.CPF = atoi(item);

				item = strtok(NULL, ",");
				_patient.CEP = atoi(item);

				item = strtok(NULL, ",");
				_patient.age = atoi(item);

				item = strtok(NULL, ",");
				char* birthDate = item;

				item = strtok(NULL, ",");
				char* diagnosisDate = item;

				item = strtok(NULL, ",");
				_patient.Havediabetes = atoi(item);

				item = strtok(NULL, ",");
				_patient.HaveObesity = atoi(item);

				item = strtok(NULL, ",");
				_patient.HaveHypertension = atoi(item);

				item = strtok(NULL, ",");
				_patient.HaveTuberculosis = atoi(item);

				if(_patient.age >= 65 && (_patient.Havediabetes > 0 || _patient.HaveHypertension > 0 || _patient.HaveObesity > 0 || _patient.HaveTuberculosis > 0)){

						//cria arquivo com pacientes que atendem os requisitos
						bool result = CreatePatientFile(_patient, "PacientesEnviados.txt", 2); // 1 - true, 2 - false
						if(result){
							printf("Paciente(s) Enviado(s) para a Secretaria da Saude:\n");
							printf("Paciente(s) acima de 65 anos e possui alguma comorbidade.\n\n");
							printf("******************************\n");
							printf("Nome : %s\n", _patient.Name);
							printf("CEP : %i\n", _patient.CEP);
							printf("Status : ENVIADO\n\n");
							printf("******************************\n");
							count++;
						}
						else
							printf("Ocorreu um erro ao enviar o paciente, entre em contato com o suporte.\n");
				}
		}
	}
	if(count == 0){
		printf("Nenhum paciente cadastrado acima de 65 anos e com alguma comorbidade foi localizado.\n\n");
	}
	fclose(file);
	system("PAUSE");
	system("cls");
}
void SystemOptions(){
	// loop para utilizar alguma método da aplicação após o login
	int conditional = 0;
	printf("---------------------Bem vindo %s---------------------\n", _userName);
	do{

		printf("O que deseja fazer?\n\n");
		printf("Digite <1> para cadastrar um novo paciente:\n\n");
		printf("Digite <2> para visualizar pacientes cadastrados:\n\n");
		printf("Digite <3> para enviar pacientes acima de 65 anos com alguma comorbidade para a Secretaria da Saude\n\n");
		printf("Digite <4> para sair:\n");

		scanf("%d", &conditional);

		// switch case para determinar qual funcionalidade da aplicação será chamada
		switch (conditional){
	   		case 1:
	     		BuildPatient();
	     		break;
			case 2:
				GetPatients();
				break;
			case 3:
				SendPatient();
				break;

	   		default:
	   			break;
		}
	}
	while(conditional > 0 && conditional < 4);
}
int main() {
	//método para logar
	Login();
	//método que traz o menu principal da aplicação
	SystemOptions();
	return 0;
}
