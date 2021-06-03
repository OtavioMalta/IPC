#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> //Para a função getch();
#define MAX_PATRIMONIOS 50
struct patrimonio{
    char nome[50];
    int data;
    int ativo; //0->inativo...1->ativo;
    int id;
    char marca[50];
    char setor[50];
    char status[50];
    char responsavel[50];
    //manutencao
    char tecnico[50];
    char datamanutencao[12];
    char descricao_status[100];
    //movimentacao
    char data_transferencia[12];
    char data_retorno[12];
    char setor_origem [50];
    char setor_destino [50];
    int status_transferencia;       //Se for igual a 1 o patrimonio deve ser mostrado, se for 0 não
};

void cadastrar(struct patrimonio patrimonios[]){
    int op=1;
    system("cls"); //Limpa o terminal

    while(op!=0){

        FILE *pat_arq; //Cria o ponteiro para o arquivo

        pat_arq = fopen("arquivo_patrimonios.txt","a"); //Abre o arquivo no modo de adição de dados "a"
        //Caso o arquivo não exista, criará um novo

        printf("*-------------------------*\n");
        printf("| Cadastrar um Patrimonio |\n");
        printf("*-------------------------*\n");


        for (int i = 0;i< MAX_PATRIMONIOS;i++){
            if (patrimonios[i].ativo==0){                   //0->inativo...1->ativo - usar na baixa de patrimonios
                printf("ID: ");
                scanf("%d",&patrimonios[i].id);
                fflush(stdin);
                printf("\nNome: ");
                fgets(patrimonios[i].nome, 50, stdin);
                printf("\nSetor: ");
                fflush(stdin);
                fgets(patrimonios[i].setor, 50, stdin);
                fflush(stdin);
                printf("\nMarca: ");
                fgets(patrimonios[i].marca, 50, stdin);
                printf("\nResponsavel: ");
                fgets(patrimonios[i].responsavel, 50, stdin);
                printf("\nData de aquisicao: ");
                scanf("%d",&patrimonios[i].data);
                fflush(stdin);
                patrimonios[i].ativo=1;
                strcpy(patrimonios[i].status, "OK!");

                //Registra os dados no arquivo
                fprintf(pat_arq, "\nId:        #%d\n", patrimonios[i].id);
                fprintf(pat_arq, "Nome:      %s\n", patrimonios[i].nome);
                fprintf(pat_arq, "Setor:     %s\n", patrimonios[i].setor);
                fprintf(pat_arq, "Aquisição: %d\n", patrimonios[i].data);
                fprintf(pat_arq, "Marca:     %s\n\n", patrimonios[i].marca);
                fprintf(pat_arq, "Responsavel:     %s\n\n", patrimonios[i].responsavel);
                fprintf(pat_arq,"--------------------------\n");

                fclose(pat_arq);      //Fecha o arquivo

                printf("\nCadastro realizado com sucesso!\n");
                break;}}
        printf("\n1 - Continuar\n0 - Sair\n");
        scanf("%d",&op);}}

void inventario(struct patrimonio patrimonios []){
    int id,d;
    system("cls");
    printf("*----------------------------*\n");
    printf("| Inventario de Patrimonios  |\n");
    printf("*----------------------------*\n");
    for (int i = 0; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].ativo==1){
        printf("\n---------------");
        printf("\nID:   #%d",patrimonios[i].id);
        printf("\nNome: %s\n\n",patrimonios[i].nome);

        }}
        printf("Digite qualquer tecla para continuar\n\n");
        getch();} //pausa na tela até uma tecla ser digitada

void mostra1(struct patrimonio patrimonios []){
    char responsavel[50];
    int op = 1;
    system("cls");
    while(op!=0){
        printf("*-------------------------------------*\n");
        printf("| Exibir um Patrimonio detalhadamente |\n");
        printf("*-------------------------------------*\n");
        printf("\nDigite o Responsavel: #\n");
        fflush(stdin);
        fgets(responsavel, 50, stdin);

        for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if ((strcmp(patrimonios[i].responsavel,responsavel)==0)){
            printf("\n---------------");
            printf("\nID:     #%d",patrimonios[i].id);
            printf("\nNome:   %s",patrimonios[i].nome);
            printf("\nData:   %d",patrimonios[i].data);
            printf("\nSetor:  %s",patrimonios[i].setor);
            printf("\nMarca:  %s",patrimonios[i].marca);
            printf("\nStatus: %s",patrimonios[i].status);
            printf("\nResponsavel: %s",patrimonios[i].responsavel);

            if (strcmp(patrimonios[i].status,"Em Manutencao")==0){
                printf("\n-----------------------------------------------");
                printf("\nTecnico Responsavel: %s",patrimonios[i].tecnico);
                printf("\nData da Manutencao:  %s",patrimonios[i].datamanutencao);
                printf("\nDescricao:  %s\n",patrimonios[i].descricao_status);
            }
        }
        }printf("\n\nDeseja pesquisar outro Patrimonio?\n0 - Nao\n1 - Sim\n");
    scanf("%d",&op);
    }}


void baixa(struct patrimonio patrimonios []){
    system("cls");
    printf("*--------------------------------*\n");
    printf("| Efetuar Baixa de um Patrimonio | \n");
    printf("*--------------------------------*\n");
    int id;
    printf("Digite o ID do patrimonio a ser removido: #");
    scanf("%d",&id);
    for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if(patrimonios[i].id==id){
        strcpy(patrimonios[i].status,"Indisponivel");            //torna o status patrimonio como inativo
        patrimonios[i].ativo=0;                             //tira o patrimonio do inventario (ainda ? possivel acessar pelo mostra1())
        printf("\nBaixa efetuada com sucesso!\n\n");
        getch();
}}}

void edicao(struct patrimonio patrimonios []){
    int id, op = 1,opcao;
    while(op==1){
    system("cls");
    printf("*---------------------------------*\n");
    printf("| Efetuar Edicao de um Patrimonio | \n");
    printf("*---------------------------------*\n");
    printf("Digite o ID do patrimonio a ser editado: #");
    scanf("%d" ,&id);
    for(int i = 0; i < MAX_PATRIMONIOS; i++){
          if(patrimonios[i].id==id && strcmp(patrimonios[i].status,"Indisponivel")==0){
            printf("[ERRO] Nao foi possivel encontrar este patrimonio. Verique o inventario.");}
          else if(patrimonios[i].id==id){
          system("cls");
          printf("\n------------------------");
          printf("\n|     Patrimonio       |");
          printf("\n------------------------\n");

          printf("\n1-ID:     #%d",patrimonios[i].id);
          printf("\n2-Nome:   %s",patrimonios[i].nome);
          printf("\n3-Data:   %d",patrimonios[i].data);
          printf("\n4-Setor:  %s",patrimonios[i].setor);
          printf("\n5-Marca:  %s",patrimonios[i].marca);
          printf("\n------------------------\n");
          printf("Qual informacao deseja editar? ");
          scanf("%d",&opcao);

            if(opcao==1){
              printf("\nDigite o novo ID: ");
              scanf("%d",&patrimonios[i].id);}
              fflush(stdin);

            if(opcao==2){
              printf("\nDigite o novo Nome: ");
                fgets(patrimonios[i].nome, 50, stdin);}
            if(opcao==3){
              printf("\nDigite a nova Data: ");
                scanf("%d",&patrimonios[i].data);}
            if(opcao==4){
              printf("\nDigite o novo Setor: ");
                fgets(patrimonios[i].setor, 50, stdin);}
            if(opcao==5){
              printf("\nDigite a nova Marca: ");
                fgets(patrimonios[i].marca, 50, stdin);}
          printf("\n------------------------\n");
          printf("\n Patrimonio editado com sucesso!");

          }
      }printf("\n1 - Continuar\n0 - Sair\n");
       scanf("%d" ,&op);
    }
}

void movimentacao(struct patrimonio patrimonios []){
    int id, op = 1,opcao;
    while(op==1){
    system("cls");
    printf("*---------------------------------*\n");
    printf("| Efetuar Edicao de um Patrimonio | \n");
    printf("*---------------------------------*\n");
    printf("Digite o ID do patrimonio a ser editado: #");
    scanf(" %d" ,&id);

    for(int i = 0; i < MAX_PATRIMONIOS; i++){
          if(patrimonios[i].id==id && strcmp(patrimonios[i].status,"Indisponivel")==0){
            printf("[ERRO] Nao foi possivel encontrar este patrimonio. Verique o inventario.");}
          else if(patrimonios[i].id==id){
        printf("\nEscolha uma opcao:\n");
        printf("1-Transferencia Definitiva:\n");
        printf("2-Transferencia provisoria:\n");
        printf("3-Declarar retorno:\n");
        int opc;
        FILE *patm_arq;

        patm_arq = fopen("arquivo_movimentacao.txt","a");

        scanf("%d", &opc);
        fflush(stdin);
        if (opc == 1){
            printf("\nData de Transferencia: ");
            fgets(patrimonios[i].data_transferencia, 50, stdin);
            fflush(stdin);
            printf("\nSetor de destino: ");
            strcpy(patrimonios[i].status,"OK!");
            patrimonios[i].status_transferencia = 1;                   //mostra que ja foi transferido
            strcpy(patrimonios[i].setor_origem, patrimonios[i].setor);
            fprintf(patm_arq, "\nId:                 #%d\n", id);
            fprintf(patm_arq, "\n   Tranferencia Definitiva   \n");
            fprintf(patm_arq, "Setor Origem:          %s\n", patrimonios[i].setor);
            fgets(patrimonios[i].setor, 50, stdin);
            fprintf(patm_arq, "Setor Atual:           %s\n", patrimonios[i].setor);
            fprintf(patm_arq, "Data de Transferencia: %s\n",patrimonios[i].data_transferencia );
            fprintf(patm_arq,"-------------------------------------------\n");

            printf("\nTransferencia efetuada com sucesso!\n\n");
            fclose(patm_arq);      //Fecha o arquivo
}

        if (opc == 2){
            printf("\nData de Transferencia: ");
            fgets(patrimonios[i].data_transferencia, 50, stdin);
            printf("\nData de retorno: ");
            fgets(patrimonios[i].data_retorno, 50, stdin);
            printf("\nSetor de destino: ");
            fgets(patrimonios[i].setor_destino, 50, stdin);
            strcpy(patrimonios[i].setor_origem,patrimonios[i].setor);
            patrimonios[i].status_transferencia = 1;
            strcpy(patrimonios[i].status,"Transferido Provisoriamente");


                fprintf(patm_arq, "\nId:                    #%d\n", id);
                fprintf(patm_arq, "\n   Tranferencia Provisoria   \n");
                fprintf(patm_arq, "Data de Transferencia: %s\n",patrimonios[i].data_transferencia );
                fprintf(patm_arq, "Data de Retorno:       %s\n",patrimonios[i].data_retorno );
                fprintf(patm_arq, "Setor de Origem:       %s\n",patrimonios[i].setor_origem );
                fprintf(patm_arq, "Setor Destino:         %s\n",patrimonios[i].setor_destino );
                fprintf(patm_arq,"-------------------------------------------\n");
                printf("\nTransferencia efetuada com sucesso!\n\n");
                fclose(patm_arq);      //Fecha o arquivo
}
               if (opc ==3){
                for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
                if(patrimonios[i].id==id){
                strcpy(patrimonios[i].status,"OK!");
                patrimonios[i].status_transferencia = 0;}}
                printf("\nRetorno efetuado com sucesso!\n\n");
                fclose(patm_arq);}
}}      printf("\n1 - Continuar\n0 - Sair\n");
        scanf("%d",&op);}}



void reg_movimentacao(struct patrimonio patrimonios []){
    system("cls");
    printf("*--------------------------*\n");
    printf("| Registro de Movimentacao |\n");
    printf("*--------------------------*\n");
    for (int i = 0; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].status_transferencia==1){
        printf("\n--------------------------------------------------");
        printf("\nID:   #%d\n",patrimonios[i].id);
        if(strcmp(patrimonios[i].status,"Transferido Provisoriamente")==0){
                printf("Transferencia Provisoria\n");
                printf("\nSetor de Origem: %s\n",patrimonios[i].setor_origem);
                printf("\nSetor Atual: %s\n",patrimonios[i].setor_destino);
                printf("\nData de Transferencia: %s\n",patrimonios[i].data_transferencia);
                printf("\nData de   Retorno: %s\n\n",patrimonios[i].data_retorno);}
            else{
                printf("Transferencia Definitiva\n");
                printf("\nSetor de Origem: %s\n",patrimonios[i].setor_origem);
                printf("\nSetor Atual: %s\n",patrimonios[i].setor);
                printf("\nData de Transferencia: %s\n\n",patrimonios[i].data_transferencia);}
}}        printf("Digite qualquer tecla para continuar\n\n");
          getch();}

void manutencao(struct patrimonio patrimonios []){ //cadastra manutencoes para um patrimonio
    int id;
    int op = 1;
    int opcao;

    system("cls");

    FILE *patma_arq;

    while(op!=0){
        printf("*-------------------------------------*\n");
        printf("| Manutencao do Patrimonio |\n");
        printf("*-------------------------------------*\n");
        printf("\nDigite o id do patrimonio: #\n");
        scanf("%d",&id);
        for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].id == id){
            printf("\nEscolha uma opcao:\n");
            printf("\n1-Efetuar Manutencao");
            printf("\n2-Concluir Manutencao\n");
            scanf("%d",&opcao);
            fflush(stdin);
            if(opcao==1){
                printf("\n-----------------------------------\n");
                printf("| Informacoes do Patrimonio |\n"); //mostra as informacoes do patrimonio para checar se é o correto
                printf("\nID:     #%d",patrimonios[i].id);
                printf("\nNome:   %s",patrimonios[i].nome);
                printf("\nSetor:  %s",patrimonios[i].setor);
                printf("\nMarca:  %s",patrimonios[i].marca);
                printf("\nStatus: %s\n",patrimonios[i].status);
                printf("\n-----------------------------------");
                patma_arq = fopen("arquivo_manutencao.txt","a"); //Abre o arquivo
                printf("\n| Digite a Data, a Descricao e o Tecnico Responsavel |\n"); //Avisa ao usuario o que deve ser informado para cadastrar a manutencao
                printf("\nData: ");
                fgets(patrimonios[i].datamanutencao, 50, stdin);
                fflush(stdin);
                printf("\nDescricao: ");
                fgets(patrimonios[i].descricao_status, 50, stdin);
                printf("\nTecnico: ");
                fgets(patrimonios[i].tecnico, 50, stdin);}
                strcpy(patrimonios[i].status,"Em Manutencao");
                fprintf(patma_arq, "\n-------------------------------------------------\n");
                fprintf(patma_arq, "ID: #%d\n",patrimonios[i].id);
                fprintf(patma_arq, "Data da Manutencao: %s\n",patrimonios[i].datamanutencao);
                fprintf(patma_arq, "Tecnico Responsavel: %s\n",patrimonios[i].tecnico);
                fprintf(patma_arq, "Descricao: #%d\n",patrimonios[i].descricao_status);
                fprintf(patma_arq, "\n-------------------------------------------------\n");

                fclose(patma_arq);      //Fecha o arquivo

                printf("\n*-------------------------------------*\n"); //Mostra o que foi cadastrado para o Cliente verificar
                printf("\nManuencao cadastrada com sucesso!\n");
                printf("\nData da Manutencao:  %s",patrimonios[i].datamanutencao);
                printf("\nDescricao:  %s",patrimonios[i].descricao_status);
                printf("Tecnico Responsavel: %s\n",patrimonios[i].tecnico);
                printf("*-------------------------------------*\n");
            }else if(opcao==2){
                printf("Manutencao Concluida com Sucesso!");
                strcpy(patrimonios[i].status,"OK!");
            }
           } printf("\n\nDeseja cadastrar manutencao em outro patrimonio?\n0 - Nao\n1 - Sim\n");
            scanf("%d",&op);}}

void menu(){
	int opcao;
    struct patrimonio patrimonios[MAX_PATRIMONIOS];
    memset(&patrimonios, 0, sizeof(patrimonios));

	while(1){
        system("cls");
        printf("\n*---------------------------------------------------------------------------*");
		printf("\n| Bem vindo ao Sistema de controle do patrimonios dos equipamentos da UFU! |");
        printf("\n*---------------------------------------------------------------------------*");
		printf("\n1- Cadastrar Patrimonio");
		printf("\n2- Inventario de patrimonios");
		printf("\n3- Mostrar um Patrimonio detalhadamente");
        printf("\n4- Efetuar Baixa de um Patrimonio");
        printf("\n5- Editar Informacoes de um Patrimonio");
        printf("\n6- Efetuar Transferencia");
        printf("\n7- Registro de Transferencia");
        printf("\n8- Manutencao");
		printf("\n0- Sair ");
		printf("\n\nDigite uma  opcao: ");
		scanf("%d", &opcao);
		if(opcao == 1) cadastrar(patrimonios);
		if(opcao == 2) inventario(patrimonios);
		if(opcao == 3) mostra1(patrimonios);
		if(opcao == 4) baixa(patrimonios);
		if(opcao == 5) edicao(patrimonios);
        if(opcao == 6) movimentacao(patrimonios);
	   	if(opcao == 7) reg_movimentacao(patrimonios);
		if(opcao == 8) manutencao(patrimonios);
		if(opcao == 0) return;}}

int main(){
	menu();
}