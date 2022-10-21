#include <stdio.h>
#include <stdlib.h>
#define MAX 80 //nome do candidato
struct data{

    int dia, mes, ano;

};

struct dadoEmLinhas{ //precisaria criar um vetor de registro;

    int codinscricao; // referente ao participante;
    char nomecandidato[MAX]; 
    data datanasc; // será utilizado para calcular o caso de empate;
    char tipovaga[5]; // no arquivo em questão aparece com letras e números, como no exemplo dado na DescriçãoTrabalho;

};
struct curso{
    int codcurso, qtd;
    dadoEmLinhas *tuplas;
};



void lerDados(int quant){ //quantidade total de cursos
    FILE *dados;
    char nome[20]; // nome do arquivo
    curso *titulo;
    printf("Digite o nome do arquivo: ");
    scanf(" %s", nome);
    
    //abertura do arquivo
    dados = fopen(nome,"r");

    if (dados == NULL){
        printf("\n\nO arquivo não pode ser aberto\n\n");
    }


    //executar leitura do arquivo

    else{//a leitura deste arquivo provavelmente será diferente da forma atual

        printf("\n\nO arquivo foi aberto!\n\n");
        
        int quant = 113;//aqui vai pegar o quant do meu codigo

        titulo = (curso *) malloc(quant * sizeof(curso));

        for (int i=0;i<quant;i++){ //ler até acabar o arquivo

            fscanf(dados, "%d %d", &titulo[i].codcurso, &titulo[i].qtd); // a primeira linha tem duas entradas

            //alocar memória pra cada bloco            
            titulo[i].tuplas = (dadoEmLinhas *) malloc (titulo[i].qtd * sizeof(dadoEmLinhas)); //aloca dinâmicamente as linhas


            //verificar se alocou - caso saiba que vai alocar, pule para o else, para facilitar a leitura
            if (titulo[i].tuplas == NULL){
                printf("Não foi possível alocar na memória");
                break;
            }


            else{
                //executar a leitura dos dados de forma correta para cada bloco;
                int x;
                for (x=0; x < titulo[i].qtd; x++){
                    fscanf(dados, "%d %[^0^1^2^3^4^5^6^7^8^9] %d/%d/%d %[^\n]", &titulo[i].tuplas[x].codinscricao, titulo[i].tuplas[x].nomecandidato, &titulo[i].tuplas[x].datanasc.dia, &titulo[i].tuplas[x].datanasc.mes, &titulo[i].tuplas[x].datanasc.ano, titulo[i].tuplas[x].tipovaga);
                }


                
            }
        }
    }

    for (int i=0; i<20;i++){
        printf("%d %d \n",titulo[i].codcurso, titulo[i].qtd);
        for(int x=0;x<titulo[i].qtd;x++){
            printf("%d %s %d/%d/%d %s \n",titulo[i].tuplas[x].codinscricao, titulo[i].tuplas[x].nomecandidato, titulo[i].tuplas[x].datanasc.dia, titulo[i].tuplas[x].datanasc.mes, titulo[i].tuplas[x].datanasc.ano, titulo[i].tuplas[x].tipovaga);
        }
    }
}
