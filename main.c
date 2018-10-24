#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
/*void bd_modify (){

    FILE *bd;
    bd = fopen("bd_loc.txt", "a");

}

void bd_read (){

    FILE *bd;
    bd = fopen("bd_loc.txt", "r");

}*/

//edita filme
void edit_film(){
    int edit_aux = 0;
    char edit_cont;
    int edit_help;
    char edit_nom[50];
    int edit_cod;
    int edit_loc;
    int edit_mult;

    while(!edit_aux){
        system("cls");
        printf("\n");
        printf("|-----------------------------------------|\n");
        printf("|     Bem-vindo a edicao de filmes        |\n");
        printf("|-----------------------------------------|\n");
        printf("|                                         |\n");
        printf("|  Digite o codigo do para ser editado:   |\n");
        printf("|                                         |\n");
        printf("|-----------------------------------------|\n");
        scanf("%d", &edit_cod);

        }
        printf("Deseja realizar outro cadastro? s/n\n");
        scanf("%s", &edit_cont);
        if(edit_cont == 's'){
            edit_aux = 0;
        }
        else if(edit_cont == 'n'){
            edit_aux = 1;
            menu();
        }
        else printf("Tecla invalida!");

    return;
}
//procura filme
void src_film(){
    int src_aux = 0;
    char src_cont;
    int src_help;
    char src_nom[50];
    int src_cod;
    int src_loc;
    int src_mult;

    while(!src_aux){
        system("cls");
        printf("\n");
        printf("|-----------------------------------------|\n");
        printf("|     Bem-vindo ao catalogo de filmes     |\n");
        printf("|-----------------------------------------|\n");
        printf("|                                         |\n");
        printf("| 1 - Procurar filme por nome             |\n");
        printf("|                                         |\n");
        printf("| 2 - Procurar filme por codigo           |\n");
        printf("|                                         |\n");
        printf("|-----------------------------------------|\n");
        scanf("%d", src_help);

        switch(src_help){
            case 1:
                    printf("Digite o nome do filme desejado:\n");
                   // scanf("%s", &src_nom[50]);
                break;

            case 2:
                    printf("Digite o codigo do filme desejado:\n");
                   // scanf("%d", &src_cod);
                break;

            case 3:
                    printf("Digite o status de alocacao do filme desejado:\n");
                   // scanf("%d", &src_loc);
                break;

            case 4:
                    printf("Digite a multa aplicada do filme desejado:\n");
                   // scanf("%d", &src_mult);
                break;
        }
        printf("Deseja realizar outra pesquisa? s/n\n");
        scanf("%s", &src_cont);
        if(src_cont == 's'){
            src_aux = 0;
        }
        else if(src_cont == 'n'){
            src_aux = 1;
            menu();
        }
        else printf("Tecla invalida!");
    }
    return;
}
//Menu principal
void menu(){
 int usue;
 int quit = 0;
 //Limpador do terminal
 system("cls");
 printf("\n");
 printf("|-----------------------------------------|\n");
 printf("|         Digite a opcao desejada         |\n");
 printf("|-----------------------------------------|\n");
 printf("|                                         |\n");
 printf("| 1 - Cadastrar novo filme                |\n");
 printf("|                                         |\n");
 printf("| 2 - Editar filme existente              |\n");
 printf("|                                         |\n");
 printf("| 3 - Procurar filme por titulo ou codigo |\n");
 printf("|                                         |\n");
 printf("| 4 - Gerar Relatorio                     |\n");
 printf("|                                         |\n");
 printf("| 5 - Consultar informacoes do filme      |\n");
 printf("|                                         |\n");
 printf("| 6 - Gerar relatorio em PDF              |\n");
 printf("|                                         |\n");
 printf("| 7 - Sair                                |\n");
 printf("|                                         |\n");
 printf("|-----------------------------------------|\n");

    scanf("%d", &usue);
    if(usue > 7 || usue < 1){
        printf("Tecla invalida! Limpando a tela em 10 segundos!");
        menu();
    }
    else {
        while(!quit) {
            switch(usue){
            case 1:
                    cad_filme();
                break;
            case 2:
                    printf("Opcao 2 selecionada!\n");
                    edit_film();
                break;
            case 3:
                    printf("Opcao 3 selecionada!\n");
                    src_film();
                break;
            case 4:
                    printf("Opcao 4 selecionada!\n");
                    scanf("%d", &usue);
                break;
            case 5:
                    printf("Opcao 5 selecionada!\n");
                    scanf("%d", &usue);
                break;
            case 6:
                    printf("Opcao 6 selecionada!\n");
                    scanf("%d", &usue);
                break;
            case 7:
                    printf("Fim de operacao!\n");
                    quit = 1;
                break;
            }
        }
        exit(0);
    }
}

//Cadastro de filme
void cad_filme(){
    char nom_filme[50];
    int cod_filme;
    int loc_filme;
    float cad_val;
    float mult_filme;
    int cad_aux = 0;
    char cad_cont = 's';
    char cad_stat[16];

    while(!cad_aux){
        system("cls");
        printf("\n");
        printf("|-----------------------------------------|\n");
        printf("|     Bem-vindo ao cadastro de filmes     |\n");
        printf("|-----------------------------------------|\n");
        printf("Insira o nome do filme:\n");
        scanf("%s", &nom_filme);
        printf("\n");
        printf("Insira o codigo do filme:\n");
        scanf("%d", &cod_filme);
        printf("\n");
        printf("Insira o status de locacao do filme:\n");
        scanf("%d", &loc_filme);

        if(loc_filme < 0){
            printf("Erro! Numero menor que zero!");
            printf("Insira o status de locacao do filme:\n");
            scanf("%d", &loc_filme);
        }
        else if(loc_filme == 0){
            cad_stat[12] = "Disponivel";
        }
        else if(loc_filme == 1){
            cad_stat[10] = "Alugado";
        }
        else cad_stat[16] = "Mais de um alugado";
        printf("\n");
        printf("Insira o valor de locacao do filme:\n");
        scanf("%f", &cad_val);
        printf("\n");
        printf("Insira a multa pendente do filme:\n");
        scanf("%f", &mult_filme);
        printf("\n");
        printf("Deseja realizar outro cadastro? s/n\n");
        scanf("%s", &cad_cont);

        if(cad_cont == 's'){
            FILE *bd;
            bd = fopen("bd_loc.txt", "a");
            fprintf(bd, "-----------\nNome: %s\nCodigo: %d\nStatus: %s\nValor: R$ %.2f\nMulta: R$ %.2f\n-----------\n", nom_filme, cod_filme, cad_stat, cad_val, mult_filme);
            fclose(bd);
            cad_aux = 0;
        }
        else if(cad_cont == 'n'){
            FILE *bd;
            bd = fopen("bd_loc.txt", "a");
            fprintf(bd, "-----------\nNome: %s\nCodigo: %d\nLocacao: %s\nValor: R$ %.2f\nMulta: R$ %.2f\n-----------\n", nom_filme, cod_filme, cad_stat, cad_val, mult_filme);
            fclose(bd);
            cad_aux = 1;
            menu();
        }
        else printf("Tecla invalida!");
    }
    return;
}

//Funcao principal
int main()
{
    menu();
}
