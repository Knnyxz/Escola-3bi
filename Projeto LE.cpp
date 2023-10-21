#include <stdio.h>
#include <locale.h>   
#include <stdlib.h>
#include <string.h>

char times[4][50];
char timestmp;
int classificacao[4];
int pontosturno[4][2];
int totalpontos[4];
int x, y;

int main(){
setlocale(LC_ALL,"portuguese");

// Nome dos times
for(x=0;x <= 3;x++){
    printf("Digite o nome do %d° time: \n", x+1);
    gets(times[x]);
    classificacao[x] = x;
}

// Pontuação
printf("\nEscreva a pontuação do 1° turno:\n");
for(y=0;y <= 1;y++){
    if(y == 1){
        printf("\nEscreva a pontuação do 2° turno:\n");
    }
    for(x = 0; x <= 3; x++){
        printf("\n%s no %d turno: \n", times[x], y + 1);
        scanf("%d", &pontosturno[x][y]);
    }
}

// Total d pnts
for(x=0;x <= 3;x++){
    totalpontos[x] = pontosturno[x][0] + pontosturno[x][1];
}
// Classificação
    for (x = 0; x <= 2; x++) {
        for (y = x + 1; y <= 3; y++) {
            if (totalpontos[classificacao[x]] < totalpontos[classificacao[y]]) {
                timestmp = classificacao[x];
                classificacao[x] = classificacao[y];
                classificacao[y] = timestmp;
            } else{
			 if (totalpontos[classificacao[x]] == totalpontos[classificacao[y]]) {
                if (pontosturno[classificacao[x]][1] < pontosturno[classificacao[y]][1]) {
                	timestmp = classificacao[x];
                    classificacao[x] = classificacao[y];
                    classificacao[y] = timestmp;
                } else{
				if (pontosturno[classificacao[x]][1] == pontosturno[classificacao[y]][1]){
                    if (pontosturno[classificacao[x]][0] < pontosturno[classificacao[y]][0]){
                        timestmp = classificacao[x];
                        classificacao[x] = classificacao[y];
                        classificacao[y] = timestmp;
                    }
                }
             	}
        	}
            }
        }
    }


system("cls");
printf("+-----------------+-----------------+-----------------+-----------------+-----------------+\n");

// Cabeçalho
printf("| %15s | %15s | %15s | %15s | %15s |\n", "Times", "Turno 1", "Turno 2", "Total d pontos", "Classificação");

printf("+-----------------+-----------------+-----------------+-----------------+-----------------+\n");

// Tabela
for(x=0;x <= 3;x++){
    printf("| %15s | %15d | %15d | %15d | %15s |\n", times[x], pontosturno[x][0], pontosturno[x][1], totalpontos[x], times[classificacao[x]]);
}

printf("+-----------------+-----------------+-----------------+-----------------+-----------------+\n");


// Categorias

printf("--------------------------\n");
printf("§ Time campeão: %s\n", times[3]);
printf("§ Vice-campeão: %s\n", times[2]);
printf("§ Pior time do campeonato: %s\n", times[0]);
printf("--------------------------\n");

}
