#include <stdio.h>
#include <stdlib.h>

void Criar_Menu_While(char chave[2], char separador[2][20], char C, int n, FILE *fp);
void Cria_Menu(char chave[2], char separador[2][20],char C, int n, int comeco, FILE *fp);
void separacao(char separador[], char caractere);
int opcao(const char* txt);

int main(){
    system("clear");

    int n, w, comeco, opc1, opc2;
    char chave[2], separador[2][20], C;
    FILE *fp;
    
    fp = fopen("MENU.cpp", "w");

    if(fp == NULL)
        return 0;

    // Se quer while no menu
    w = opcao("Com while?\n[1]- Sim\t[0]- Nao\n");
    if (!w)
        comeco = opcao("Comeca em 1 ou em 0?\n");

    n = opcao("Qantd. de elementos no menu: ");
    
    if(opcao("Leitura de inteiro ou de caractere?\n[1]- Inteiro\t[0]- Caractere\n"))
        C = 'd';
    else
        C = 'c';
    // tipo de selecionador
    puts("Tipo de selecionador:");
	puts("(1)- ( )\t[2]- [ ]");
	puts("{3}- { }\t|4|- | |");
	scanf("%d", &opc1);
    
    switch(opc1){
        case (1):
            chave[0]='('; chave[1]=')';
        break;

        case (2):
            chave[0]='['; chave[1]=']';
        break;

        case (3):
            chave[0]='{'; chave[1]='}';
        break;

        case (4):
            chave[0]='|'; chave[1]='|';
        break;

        default:
            break;
    }

    if (opcao("Quer separador?\n[1]- Sim\t[0]- Nao\n")){    
        char crctr;

        // tipo de separador
        puts("Tipo de separador inicial:");
        puts("[1]- ===\t[2]- ---");
        puts("[3]- +++\t[4]- ###");
        puts("[5]- ***\t[6]- |||");
        puts("[7]- Outro caractere.");
        scanf("%d", &opc2);

        switch(opc2){
            case (1):
                separacao(separador[0], '=');
            break;

            case (2):
                separacao(separador[0], '-');
            break;

            case (3):
                separacao(separador[0], '+');
            break;

            case (4):
                separacao(separador[0], '#');
            break;

            case (5):
                separacao(separador[0], '*');
            break;
        
            case (6):
                separacao(separador[0], '|');
            break;

            case (7):
                printf("Digite o caractere desejado: "); scanf("%c%*c", crctr);
                separacao(separador[0], crctr);
            break;

            default:
                break;
        }

        puts("Tipo de separador final:");
        puts("[1]- ===\t[2]- ---");
        puts("[3]- +++\t[4]- ###");
        puts("[5]- ***\t[6]- |||");
        puts("[7]- Outro caractere.");
        scanf("%d", &opc2);

        switch(opc2){
            case (1):
                separacao(separador[1], '=');
            break;

            case (2):
                separacao(separador[1], '-');
            break;

            case (3):
                separacao(separador[1], '+');
            break;

            case (4):
                separacao(separador[1], '#');
            break;

            case (5):
                separacao(separador[1], '*');
            break;
        
            case (6):
                separacao(separador[1], '|');
            break;

            case (7):
                printf("Digite o caractere desejado: "); scanf("%c%*c", crctr);
                separacao(separador[1], crctr);
            break;

            default:
                break;
        }
    }
    
    if(w)
        Criar_Menu_While(chave, separador, C, n, fp);
    else
        Cria_Menu(chave, separador, C, n, comeco, fp);

    puts("Menu criado com sucesso!");
    fclose(fp);
return 0;
}

// criacao do menu
void Criar_Menu_While(char chave[2], char separador[2][20], char C, int n, FILE *fp){
    // Criacao do whille e passo.
    if (C == 'c')
        fprintf(fp, "bool pass = true; char opc;\n");
    else
        fprintf(fp, "bool pass = true; int opc;\n");

    fprintf(fp, "while (pass == true){\n");
    fprintf(fp, "\tputs(\"%s\\n\");\n", separador[0]);// separador inicial
       
    // Inicio da criacao das opc. do menu
    for (int i=1; i<(n+1); i++){
        if (i % 2 != 0)
        fprintf(fp, "\tputs(\"%c%d%c- ",chave[0], i, chave[1]);

        else{
             fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], i, chave[1]);
            fprintf(fp, "\n");
        }
    }// fim dacriacao

    if (n % 2 != 0) // se n = impar, fecha o print
        fprintf(fp, "\\t%c0%c- sair\");", chave[0], chave[1]);
    else
        fprintf(fp, "\tputs(\"%c0%c- sair\");", chave[0], chave[1]);
        
    fprintf(fp, "\n\tscanf(\"%%%c%%*c\", &opc);\n", C);
    fprintf(fp, "\tputs(\"%s\");\n\n", separador[1]);// separador final

   
    fprintf(fp, "\tswitch(opc){\n");// switch
    
    // Criacao das opcoes do switch
    for (int i=1; i<(n+1); i++){
        if (C == 'c')
            fprintf(fp, "\t\tcase ('%d'):\n\t\tbreak;\n\n", i);
        else
            fprintf(fp, "\t\tcase (%d):\n\t\tbreak;\n\n", i);
    }// Fim
            
    //defalt
    if (C == 'c')
        fprintf(fp, "\t\tcase ('0'):\n\t\t\tpass = false;\n\t\tbreak;\n");
    else
        fprintf(fp, "\t\tcase (0):\n\t\t\tpass = false;\n\t\tbreak;\n");

    fprintf(fp, "\n\t\tdefault: \n\t\t\tputs(\"Opcao Inexistente!\");\n");
    fprintf(fp, "\t}\n");
    fprintf(fp, "}");
}

void Cria_Menu(char chave[2], char separador[2][20],char C, int n, int comeco, FILE *fp){
    if (C == 'c')
        fprintf(fp, "char opc;\n\n");
    else
        fprintf(fp, "int opc;\n\n");

    fprintf(fp, "puts(\"%s\");\n", separador[0]);// separador inicial

    // Inicio da criacao das opc. do menu
    
    if(comeco){ // Se comecar em 1, crie aqui        
        for (int i=1; i<(n); i++){
            if (i % 2 != 0)
                fprintf(fp, "puts(\"%c%d%c- ",chave[0], i, chave[1]);

            else{
                fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], i, chave[1]);
                fprintf(fp, "\n");
            }
        }

        if (n % 2 != 0) // se n = impar, fecha o print
            fprintf(fp, "puts(\"%c%d%c- \\n\");", chave[0], n, chave[1]);
        else
            fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], n, chave[1]);
    }// fim da criacao

    else{
        for (int i=0; i<n-1; i++){
            if (i % 2 == 0)
                fprintf(fp, "puts(\"%c%d%c- ",chave[0], i, chave[1]);

            else{
                fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], i, chave[1]);
                fprintf(fp, "\n");
            }
        }

        if (n % 2 != 0) // se n = impar, fecha o print
            fprintf(fp, "puts(\"%c%d%c- \\n\");", chave[0], n-1, chave[1]);
        else
            fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], n-1, chave[1]);
    }// fim dacriacao
        
    fprintf(fp, "\nscanf(\"%%%c%%*c\", &opc);\n", C);
    fprintf(fp, "puts(\"%s\\n\");\n\n", separador[1]);// separador final

    fprintf(fp, "switch(opc){\n"); //Switch

    if(comeco) { //Se comecar em 1:
        // Criacao das opcoes do switch
        for (int i=1; i<(n+1); i++){
            if (C == 'c')
                fprintf(fp, "\tcase ('%d'):\n\tbreak;\n\n", i);
            else
                fprintf(fp, "\tcase (%d):\n\tbreak;\n\n", i);
        }// Fim
            
        //defalt
        fprintf(fp, "\tdefault: \n\t\tputs(\"Opcao Inexistente!\");\n");
        fprintf(fp, "}\n");
    }
    
    else { //Se comecar em 0
        // Criacao das opcoes do switch
        for (int i=0; i<n; i++){
            if (C == 'c')
                fprintf(fp, "\tcase ('%d'):\n\tbreak;\n\n", i);
            else
                fprintf(fp, "\tcase (%d):\n\tbreak;\n\n", i);
        }// Fim
        
        //defalt
        fprintf(fp, "\tdefault: \n\t\tputs(\"Opcao Inexistente!\");\n");
        fprintf(fp, "}\n");
    }
}

/* Funcao para preencher o vetor com o separador escolhido */
void separacao(char separador[], char caractere){
    for(int i=0; i<22; i++){
        separador[i] = caractere;
    }
}

/*Imprime um texto e faz leitura de um inteiro*/
int opcao(const char* txt){
    int a;
    printf("%s", txt);
    scanf("%d", &a);
    return a;
}