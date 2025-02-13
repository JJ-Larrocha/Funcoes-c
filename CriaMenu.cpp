#include <stdio.h>
#include <stdlib.h>

#define LEN 20

void Criar_Menu_While(char chave[2], char separador[2][LEN], char C, int n, FILE *fp);
void Cria_Menu(char chave[2], char separador[2][LEN], int n, FILE *fp);
void separacao(char separador[2][LEN], char crctr[2]);
int opcao(const char* txt);

int main(){
    int n, w, comeco, opc1, opc2;
    char chave[2], charSeparacao[2], C;
    char separador[2][LEN];
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
        // tipo de separador
        puts("Tipo do primeiro separador:");
        puts("[1]- ===\t[2]- ---");
        puts("[3]- +++\t[4]- ###");
        puts("[5]- ***\t[6]- |||");
        puts("[7]- Outro caractere");
        scanf("%d", &opc2);

        switch(opc2){
            case (1):
                charSeparacao[0] = '=';
            break;

            case (2):
                charSeparacao[0] = '-';
            break;

            case (3):
                charSeparacao[0] = '+';
            break;

            case (4):
                charSeparacao[0] = '#';
            break;

            case (5):
                charSeparacao[0] = '*';
            break;
        
            case (6):
                charSeparacao[0] = '|';
            break;

            case (7):
                printf("Digite o caractere desejado: "); scanf("%c%*c", &charSeparacao[0]);
            break;

            default:
                break;
        }

        puts("Tipo do Segundo separador:");
        puts("[1]- ===\t[2]- ---");
        puts("[3]- +++\t[4]- ###");
        puts("[5]- ***\t[6]- |||");
        puts("[7]- Outro caractere");
        scanf("%d", &opc2);

        switch(opc2){
            case (1):
                charSeparacao[1] = '=';
            break;

            case (2):
                charSeparacao[1] = '-';
            break;

            case (3):
                charSeparacao[1] = '+';
            break;

            case (4):
                charSeparacao[1] = '#';
            break;

            case (5):
                charSeparacao[1] = '*';
            break;
        
            case (6):
                charSeparacao[1] = '|';
            break;

            case (7):
                printf("Digite o caractere desejado: "); scanf("%c", &charSeparacao[1]);
            break;

            default:
                break;
        }
    }

    separacao(separador, charSeparacao);
    
    if(w)
        Criar_Menu_While(chave, separador, C, n, fp);
    else
        Cria_Menu(chave, separador, n, fp);

    puts("Menu criado com sucesso!");
    fclose(fp);
return 0;
}

// criacao do menu
void Criar_Menu_While(char chave[2], char separador[2][LEN], char C, int n, FILE *fp){
    // Criacao do whille e passo.
    if (C == 'c')
        fprintf(fp, "bool pass = true; char opc;\n");
    else
        fprintf(fp, "bool pass = true; char opc;\n");

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
        
    fprintf(fp, "\n\tscanf(\"%%%c\", &opc);\n", C);
    fprintf(fp, "\tputs(\"%s\");\n\n", separador[1]);// separador final

    fprintf(fp, "\tswitch(opc){\n");// if

    // Criacao do else if
    for (int i=1; i<(n+1); i++){
        fprintf(fp, "\tcase (%d):\n\tbreak;\n\n", i);
    }// Fim
        
    //else
    fprintf(fp, "\tcase (0):\n\t\tpass = false;\n\tbreak;\n");
    fprintf(fp, "\tdefault: \n\t\tputs(\"Opcao Inexistente!\");\n");
    fprintf(fp, "\t}\n");
    fprintf(fp, "}");
}

void Cria_Menu(char chave[2], char separador[2][LEN], int n, FILE *fp){
    fprintf(fp, "puts(\"%s\");\n", separador[0]);// separador inicial
        
    // Inicio da criacao das opc. do menu
    for (int i=1; i<(n); i++){
        if (i % 2 != 0)
            fprintf(fp, "puts(\"%c%d%c- ",chave[0], i, chave[1]);

        else{
            fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], i, chave[1]);
            fprintf(fp, "\n");
        }
    }// fim dacriacao

    if (n % 2 != 0) // se n = impar, fecha o print
        fprintf(fp, "\tputs(\"%c%d%c- \\n\");", chave[0], n, chave[1]);
    else
        fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], n, chave[1]);
        
    fprintf(fp, "\nscanf(\"%%c%%*c\", &opc);\n");
    fprintf(fp, "puts(\"%s\\n\");\n\n", separador[1]);// separador final

    fprintf(fp, "switch(opc){\n");// if

    // Criacao do else if
    for (int i=1; i<(n+1); i++){
        fprintf(fp, "\tcase (%d):\n\tbreak;\n\n", i);
    }// Fim
        
    //else
    fprintf(fp, "\tcase (0):\n\t\tpass = false;\n\tbreak;\n");
    fprintf(fp, "\tdefault: \n\t\tputs(\"Opcao Inexistente!\");\n");
    fprintf(fp, "\t}\n");
    fprintf(fp, "}");
}

/* Funcao para preencher o vetor com o separador escolhido */
void separacao(char separador[2][LEN], char crctr[2]){
    for(int i=0; i<2; i++){
        for(int j=0; j<LEN-1; i++){
            separador[i][j] = crctr[i];
        }
    }
}

/*Imprime um texto e faz leitura de um inteiro*/
int opcao(const char* txt){
    int a;
    printf("%s", txt);
    scanf("%d", &a);
    return a;
}