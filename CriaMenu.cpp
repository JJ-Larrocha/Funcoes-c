#include <stdio.h>
#include <stdlib.h>

                                    /* ESCOPOS */

void Cria_Menu_Padrao(char chave[2], char separador1[], char separador2[], char C, int n, int comeco, int w, FILE *fp);
void Cria_Menu_Coluna(char chave[2], char separador1[], char separador2[], char C, int n, int comeco, int w, FILE *fp);
void Cria_Menu_Horizontal(char chave[2], char separador1[], char separador2[], char C, int n, int comeco, int w, int l, FILE *fp);
void Preambulo(char separador1[], char C, int w, FILE *fp);
void Cria_Switch(char C, int n, int comeco, int w, FILE *fp);
void Seleciona_Separador(char *separador, int m);
void separacao(char separador[], char caractere, int m);
int opcao(const char* txt);

                                    /* MAIN */

int main(){
    system("clear");

    int n, m, w, comeco=1, opc, layout, lateral, ordem;
    char chave[2], C;
    char *separador1, *separador2;
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
	scanf("%d", &opc);
    switch(opc){
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
        // Esscolha dos separadores
        m = opcao("Qntd. de digitos no separador: ");
        separador1 = (char*) malloc(sizeof(char) * m);
        separador2 = (char*) malloc(sizeof(char) * m);

        puts("\nTipo de separador inicial:");
        Seleciona_Separador(separador1, m);
        
        puts("\nTipo de separador final:");
        Seleciona_Separador(separador2, m);
    }

    puts("\nSelecione o layout do Menu:");
    puts("[1]- Padrao. Ex:\n\t[a]-\t[b]-\n\t[c]-\t[d]-");
    puts("\n[2]- Apenas uma coluna. Ex:\n\t[a]-\n\t[b]\n\t[c]-\n\t[d]-");
    puts("\n[3]- Mais de duas opcoes na lateral. Ex:\n\t[a]-\t[b]-\t[c]-\n\t[d]-\t[e]-\t[f]-");
    scanf("%d%*c", &layout);

    switch(layout){
        case (1):
            Cria_Menu_Padrao(chave, separador1, separador2, C, n, comeco, w, fp);
        break;

        case (2):
            Cria_Menu_Coluna(chave, separador1, separador2, C, n, comeco, w, fp);
        break;

        case (3):
        {
            lateral = opcao("\nQntd. de elementos na lateral: ");
            
            puts("\nOrdem dos elementos:");
            puts("[1]- Da esqueda pra direita. Ex:\n\t[a]-\t[b]-\t[c]-\n\t[d]-\t[e]-\t[f]-");
            puts("[2]- De cima pra Baixo. Ex:\n\t[a]-\t[c]-\t[e]-\n\t[b]-\t[d]-\t[f]-");
            scanf("%d%*c", &ordem);

            switch(ordem){
                case (1):
                    Cria_Menu_Horizontal(chave, separador1, separador2, C, n, comeco, w, lateral, fp);
                break;

                case (2):
                break;

                default: 
                    puts("Opcao Inexistente!");
            }
            break;
        }

        default: 
            puts("Opcao Inexistente!");
        break;
    }


    puts("Menu criado com sucesso!");
    
    fclose(fp);
    free(separador1);
    free(separador2);
return 0;
}

                                    /* FUNCOES*/

/*Cria o menu no formato  padrao, com e/ou sem while*/
void Cria_Menu_Padrao(char chave[2], char separador1[], char separador2[], char C, int n, int comeco, int w, FILE *fp){
    Preambulo(separador1, C, w, fp);

    /* Inicio da criacao das opc. do menu */
    
    if(comeco){ // Se comecar em 1, crie aqui        
        for (int i=1; i<=n; i++){
            if (i % 2 != 0 && w)
                fprintf(fp, "\tputs(\"%c%d%c- ",chave[0], i, chave[1]);
            else if (i % 2 != 0 || !w)
                fprintf(fp, "puts(\"%c%d%c- ",chave[0], i, chave[1]);
            
            else{
                fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], i, chave[1]);
                fprintf(fp, "\n");
            }
        }

        if (!w){
            if (n % 2 != 0) // se n = impar, fecha o print
                fprintf(fp, "puts(\"%c%d%c- \\n\");", chave[0], n, chave[1]);
            else
                fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], n, chave[1]);
        }

        else {
            if (n % 2 == !0) // se n = par, fecha o print
                fprintf(fp, "\\t%c0%c- sair\");", chave[0], chave[1]);
            else
                fprintf(fp, "\tputs(\"%c0%c- sair\");", chave[0], chave[1]);
        }
    }// fim da criacao

    else{ //Se comecar em 0, crie aqui
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
        
    /* Leitura da opcao e Separador final */
    if(w){
        fprintf(fp, "\n\tscanf(\"%%%c%%*c\", &opc);\n", C);
        fprintf(fp, "\tputs(\"%s\\n\");\n\n", separador2);// separador final
    }
    else{
        fprintf(fp, "\nscanf(\"%%%c%%*c\", &opc);\n", C);
        fprintf(fp, "puts(\"%s\\n\");\n\n", separador2);// separador final
    }

    Cria_Switch(C, n, comeco, w, fp);
}

void Cria_Menu_Coluna(char chave[2], char separador1[], char separador2[], char C, int n, int comeco, int w, FILE *fp){
    Preambulo(separador1, C, w, fp);

    /* Inicio da criacao das opc. do menu */
    
    if(comeco){ // Se comecar em 1, crie aqui        
        for (int i=1; i<=n; i++){
            if (w)
                fprintf(fp, "\tputs(\"%c%d%c- \");\n",chave[0], i, chave[1]);
            else
                fprintf(fp, "puts(\"%c%d%c- \");\n", chave[0], i, chave[1]);
        }

        if(w)
            fprintf(fp, "\tputs(\"%c0%c- sair\");", chave[0], chave[1]);
        else
            fprintf(fp, "puts(\"%c0%c- sair\");", chave[0], chave[1]);
    }// fim da criacao

    else{ //Se comecar em 0, crie aqui
        for (int i=0; i<n; i++)
            fprintf(fp, "puts(\"%c%d%c- \");\n",chave[0], i, chave[1]);


    }// fim dacriacao
        
    /* Leitura da opcao e Separador final */
    if(w){
        fprintf(fp, "\n\tscanf(\"%%%c%%*c\", &opc);\n", C);
        fprintf(fp, "\tputs(\"%s\\n\");\n\n", separador2);// separador final
    }
    else{
        fprintf(fp, "\nscanf(\"%%%c%%*c\", &opc);\n", C);
        fprintf(fp, "puts(\"%s\\n\");\n\n", separador2);// separador final
    }

    Cria_Switch(C, n, comeco, w, fp);
}

void Cria_Menu_Horizontal(char chave[2], char separador1[], char separador2[], char C, int n, int comeco, int w, int l, FILE *fp){
    Preambulo(separador1, C, w, fp);

    /* Inicio da criacao das opc. do menu */
    
    if(comeco){ // Se comecar em 1, crie aqui        
        for (int i=1; i<=n; i++){
            if ((i-1) % l == 0 && w)
                fprintf(fp, "\tputs(\"%c%d%c- ",chave[0], i, chave[1]);
            else if ((i-1) % l == 0)
                fprintf(fp, "puts(\"%c%d%c- ",chave[0], i, chave[1]);
            
            else{
                fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], i, chave[1]);
                fprintf(fp, "\n");
            }
        }

        if (!w){
            if (n % 2 != 0) // se n = impar, fecha o print
                fprintf(fp, "puts(\"%c%d%c- \\n\");", chave[0], n, chave[1]);
            else
                fprintf(fp, "\\t%c%d%c- \\n\");", chave[0], n, chave[1]);
        }

        else {
            if (n % 2 == !0) // se n = par, fecha o print
                fprintf(fp, "\\t%c0%c- sair\");", chave[0], chave[1]);
            else
                fprintf(fp, "\tputs(\"%c0%c- sair\");", chave[0], chave[1]);
        }
    }// fim da criacao

    else{ //Se comecar em 0, crie aqui
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
        
    /* Leitura da opcao e Separador final */
    if(w){
        fprintf(fp, "\n\tscanf(\"%%%c%%*c\", &opc);\n", C);
        fprintf(fp, "\tputs(\"%s\\n\");\n\n", separador2);// separador final
    }
    else{
        fprintf(fp, "\nscanf(\"%%%c%%*c\", &opc);\n", C);
        fprintf(fp, "puts(\"%s\\n\");\n\n", separador2);// separador final
    }

    Cria_Switch(C, n, comeco, w, fp);
}

void Preambulo(char separador1[], char C, int w, FILE *fp){
        /* Criacao das variaveis de leitura e while */
    
        if (C == 'c'){// Se for leituura de um caractere
            if(w){// Se tiver while
                fprintf(fp, "bool pass = true; char opc;\n\n");
                fprintf(fp, "while (pass == true){\n");
            }
            else // Se nao tiver
                fprintf(fp, "char opc;\n\n");
        }
        else{ // Se for leitura de um inteiro
            if(w){// Se tiver while
                fprintf(fp, "bool pass = true; int opc;\n\n");
                fprintf(fp, "while (pass){\n");
            }
            else // Se nao tiver
                fprintf(fp, "int opc;\n\n");
        }
        /* Separador inicial */
        if (w)
            fprintf(fp, "\tputs(\"%s\");\n", separador1);
        else
            fprintf(fp, "puts(\"%s\");\n", separador1);
}

/*Cria o switch*/
void Cria_Switch(char C, int n, int comeco, int w, FILE *fp){
    /* Switch */
    if(w)
        fprintf(fp, "\tswitch(opc){\n");
    else
        fprintf(fp, "switch(opc){\n");
    
    if (comeco){ //Se comecar em 1:
        if(w){
            // Criacao das opcoes do switch com while
            for (int i=1; i<(n+1); i++){
                if (C == 'c')
                    fprintf(fp, "\t\tcase ('%d'):\n\t\tbreak;\n\n", i);
                else
                    fprintf(fp, "\t\tcase (%d):\n\t\tbreak;\n\n", i);
            }// Fim

            fprintf(fp, "\t\tcase(0):\n\t\t\tpass = false;\n\t\tbreak;");
            //defalt
            fprintf(fp, "\t\tdefault: \n\t\t\tputs(\"Opcao Inexistente!\");\n");
            fprintf(fp, "\t}\n}");
        }

        else{
            // Criacao das opcoes do switch com while
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

void Seleciona_Separador(char *separador, int m){
    char crctr;
    int opc;
        
    // tipo de separador
    puts("[1]- ===\t[2]- ---");
    puts("[3]- +++\t[4]- ###");
    puts("[5]- ***\t[6]- |||");
    puts("[7]- Outro caractere.");
    scanf("%d%*c", &opc);

    switch(opc){
        case (1):
            separacao(separador, '=', m);
        break;

        case (2):
            separacao(separador, '-', m);
        break;

        case (3):
            separacao(separador, '+', m);
        break;

        case (4):
            separacao(separador, '#', m);
        break;

        case (5):
            separacao(separador, '*', m);
        break;
        
        case (6):
            separacao(separador, '|', m);
        break;

        case (7):
            printf("Digite o caractere desejado: "); scanf("%c%*c", &crctr);
            separacao(separador, crctr, m);
        break;

        default:
            break;
    }
}

/* Funcao para preencher o vetor com o separador escolhido */
void separacao(char separador[], char caractere, int m){
    for(int i=0; i<m; i++){
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
