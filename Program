#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

#define MAX 50

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Corrida{
    float duracao_em_minutos;
    float distancia_em_km;
    Data data_do_treino;
    float pace_corrida;
};

// Função para calcular o pace médio
float calcular_pace (float distancia, float duracao){
    float pace = 0.00;
    pace = (duracao/distancia);
    return pace;
};

// Verifica se o ano é bissexto para validar fevereiro
bool verifica_bissexto(Data &d){
    if ((d.ano % 4 == 0 && d.ano % 100 != 0) || 
        (d.ano % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// Leitura dos campos da data
void ler_data(Data &d){
    cout << "Dia: ";
    cin >> d.dia;
    cout << "Mes: ";
    cin >> d.mes;
    cout << "Ano: ";
    cin >> d.ano;
}

//Valida a data com o calendário
void validar_data (Data &d){
    bool bissexto;
    bissexto = verifica_bissexto (d);
    while (((d.dia < 1) || (d.dia > 31)) || 
            ((d.mes < 1) || (d.mes > 12)) || 
            (((d.mes == 2) || (d.mes == 4) || 
            (d.mes == 6) || (d.mes == 9) || 
            (d.mes == 11)) && (d.dia == 31)) || 
            ((bissexto == 0) && (d.mes == 2) && (d.dia > 28)) || 
            ((bissexto == 1) && (d.mes == 2) && (d.dia > 29))){

        if ((d.dia < 1) || (d.dia > 31)){
                cout << "O dia digitado nao existe. Digite a data novamente. " << endl;
                ler_data (d);
            }

        if ((d.mes < 1) || (d.mes > 12)){
                cout << "O mes digitado nao existe. Digite a data novamente. " << endl;
                ler_data (d);
            }

        if (((d.mes == 2) ||
            (d.mes == 4) || 
            (d.mes == 6) || 
            (d.mes == 9) || 
            (d.mes == 11)) && (d.dia == 31)){
                cout << "O mes digitado nao possui dia 31. Digite a data novamente. " << endl;
                ler_data(d); 
        }

        bissexto = verifica_bissexto (d);

        if ((bissexto == 0) && (d.mes == 2) && (d.dia > 28)){
                cout << "O ano que voce colocou nao possui este dia no mes de fevereiro. Digite a data novamente. " << endl;
                ler_data(d); 
        }
    }
}

// Cadastra novos treinos e acumula em um vetor mais global
void ler_treinos (int quantidade_de_treinos, Corrida treino[], int &total_treinos){
    int i;
    cout << endl;
    cout << "Perfeito! Agora, vamos adicionar os treinos." << endl;

    for (int i = total_treinos; i < total_treinos + quantidade_de_treinos; i++) {
        cout << "Digite a data do treino " << i + 1 << "." << endl;
        ler_data(treino[i].data_do_treino);
        validar_data(treino[i].data_do_treino);

        cout << "Digite a duracao da corrida em MINUTOS: ";
        cin >> treino[i].duracao_em_minutos;

        while (treino[i].duracao_em_minutos <= 0) {
            cout << "Duracao invalida! Digite novamente: ";
            cin >> treino[i].duracao_em_minutos;
        }

        cout << "Digite a distancia da corrida em km: ";
        cin >> treino[i].distancia_em_km;
        cout << endl;

        while (treino[i].distancia_em_km <= 0) {
            cout << "Distancia invalida! Digite novamente: ";
            cin >> treino[i].distancia_em_km;
        }

        treino[i].pace_corrida = calcular_pace(
            treino[i].distancia_em_km,
            treino[i].duracao_em_minutos
        );
    }

    total_treinos += quantidade_de_treinos;

}

// Escolher o filtro de visualização
void ler_filtro (int &criterio_ordenacao, int &filtro){
    filtro = 0;

    cout << endl;
    cout << "1 - Ordenar os treinos por data." << endl;
    cout << "2 - Ordenar os treinos por pace." << endl;
    cout << "3 - Ordenar os treinos por duracao." << endl;
    cout << "4 - Ordenar os treinos por distancia." << endl;
    cin >> criterio_ordenacao;

    while ((criterio_ordenacao !=1) && (criterio_ordenacao != 2) && (criterio_ordenacao !=3) && (criterio_ordenacao != 4)){
        cout << "Entrada invalida. Escolha uma opcao valida." << endl;
        cin >> criterio_ordenacao;
        cout << endl;
    }

    while ((filtro != 1) && (filtro != 2)){
        cout << endl;
        cout << "1 - Crescente." << endl;
        cout << "2 - Decrescente." << endl;
        cin >> filtro;
    }

}

// Menu principal
bool menu_inicial (int &opcao){
    cout << endl;
    cout << "1 - Adicionar treino." << endl;
    cout << "2 - Sair." << endl << endl;
    cin >> opcao;

    while ((opcao !=1) && (opcao != 2)){
        cout << "Entrada invalida. Escolha uma das opcoes abaixo: (Digite o numero)" << endl;
        cout << "1 - Adicionar treino." << endl;
        cout << "2 - Sair" << endl;
        cin >> opcao;
        cout << endl;
    }

    if (opcao == 2){
        return 0;
    } else {
        return 1;
    }
    
}

// Função de ordenar por data
void ordenar_por_data (Corrida treino[], int quantidade_de_treinos, int filtro){
    int i, j;
    Corrida aux;

    if (filtro == 1){ //crescente
        for (i=0;i<quantidade_de_treinos-1;i++) {
            for (j=i+1;j<quantidade_de_treinos;j++) {

                if ((treino[i].data_do_treino.ano > treino[j].data_do_treino.ano) ||

                    (treino[i].data_do_treino.ano == treino[j].data_do_treino.ano &&
                    treino[i].data_do_treino.mes > treino[j].data_do_treino.mes) ||

                    (treino[i].data_do_treino.ano == treino[j].data_do_treino.ano &&
                    treino[i].data_do_treino.mes == treino[j].data_do_treino.mes &&
                    treino[i].data_do_treino.dia > treino[j].data_do_treino.dia)) {
                        aux = treino[i];
                        treino[i] = treino[j];
                        treino[j] = aux;
                }
            }
        }
    }

    if (filtro == 2){ //decrescente
        for (i = 0; i < quantidade_de_treinos - 1; i++) {
            for (j = i + 1; j < quantidade_de_treinos; j++) {

                if ((treino[i].data_do_treino.ano < treino[j].data_do_treino.ano) ||

                    (treino[i].data_do_treino.ano == treino[j].data_do_treino.ano &&
                    treino[i].data_do_treino.mes < treino[j].data_do_treino.mes) ||

                    (treino[i].data_do_treino.ano == treino[j].data_do_treino.ano &&
                    treino[i].data_do_treino.mes == treino[j].data_do_treino.mes &&
                    treino[i].data_do_treino.dia < treino[j].data_do_treino.dia)) {
                        aux = treino[i];
                        treino[i] = treino[j];
                        treino[j] = aux;
                }
            }
        }
    }
}

// Função de ordenar por pace
void ordenar_por_pace (Corrida treino[], int quantidade_de_treinos, int filtro){
    int i, j;
    Corrida aux;

    if (filtro == 1){ //crescente
        for (i=0;i<quantidade_de_treinos-1;i++) {
            for (j=i+1;j<quantidade_de_treinos;j++) {
                if ((treino[i].pace_corrida) > (treino[j].pace_corrida)) {
                    aux = treino[i];
                    treino[i] = treino[j];
                    treino[j] = aux;
                }
            }
        }
    }
    if (filtro == 2){ //decrescente
        for (i=0;i<quantidade_de_treinos-1;i++) {
            for (j=i+1;j<quantidade_de_treinos;j++) {
                if ((treino[i].pace_corrida) < (treino[j].pace_corrida)) {
                    aux = treino[i];
                    treino[i] = treino[j];
                    treino[j] = aux;
                }
            }
        }
    }
}

// Função de ordenar por duração
void ordenar_por_duracao (Corrida treino[], int quantidade_de_treinos, int filtro){
    int i, j;
    Corrida aux;

    if (filtro == 1){ //crescente
        for (i=0;i<quantidade_de_treinos-1;i++) {
            for (j=i+1;j<quantidade_de_treinos;j++) {
                if ((treino[i].duracao_em_minutos) > (treino[j].duracao_em_minutos)) {
                    aux = treino[i];
                    treino[i] = treino[j];
                    treino[j] = aux;
                }
            }
        }
    }
    if (filtro == 2){ //decrescente
        for (i=0;i<quantidade_de_treinos-1;i++) {
            for (j=i+1;j<quantidade_de_treinos;j++) {
                if ((treino[i].duracao_em_minutos) < (treino[j].duracao_em_minutos)) {
                    aux = treino[i];
                    treino[i] = treino[j];
                    treino[j] = aux;
                }
            }
        }
    }
}

// Função de ordenar por distância
void ordenar_por_distancia (Corrida treino[], int quantidade_de_treinos, int filtro){
    int i, j;
    Corrida aux;

    if (filtro == 1){ //crescente
        for (i=0;i<quantidade_de_treinos-1;i++) {
            for (j=i+1;j<quantidade_de_treinos;j++) {
                if ((treino[i].distancia_em_km) > (treino[j].distancia_em_km)) {
                    aux = treino[i];
                    treino[i] = treino[j];
                    treino[j] = aux;
                }
            }
        }
    }
    if (filtro == 2){ //decrescente
        for (i=0;i<quantidade_de_treinos-1;i++) {
            for (j=i+1;j<quantidade_de_treinos;j++) {
                if ((treino[i].distancia_em_km) < (treino[j].distancia_em_km)) {
                    aux = treino[i];
                    treino[i] = treino[j];
                    treino[j] = aux;
                }
            }
        }
    }
}

// Exibe os resultados formatados
void imprimir_ordenacao (Corrida treino[], int quantidade_de_treinos, int filtro, int escolha_menu,  char nome[]){
    int i;
    
    cout << endl << endl;
    cout << nome << ", ";

    cout << "os seus treinos ordenados por ";
    
    if (escolha_menu == 1){
        cout << "data ";
    } else if (escolha_menu == 2){
        cout << "pace ";
    } else if (escolha_menu == 3){
        cout << "duracao ";
    } else{
        cout << "distancia ";
    }

    if (filtro == 1){
        cout << "em ordem crescente ";
    } else {
        cout << "em ordem decrescente ";
    }
    cout << "ficaram da seguinte forma: " << endl << endl;

    for (i=0;i<quantidade_de_treinos;i++){
        cout << "Corrida do dia " << treino[i].data_do_treino.dia << "/" << treino[i].data_do_treino.mes << "/" << treino[i].data_do_treino.ano << ":" << endl;
        cout << "Distancia da corrida: " << fixed << setprecision(2) << treino[i].distancia_em_km << "km;" << endl;
        cout << "Duracao da corrida: " << treino[i].duracao_em_minutos << "min.;" << endl;
        cout << "Pace da corrida: " << treino[i].pace_corrida << endl << endl;
    }

}

int main (){

    int quantidade_de_treinos, menu, filtro, escolha,criterio_ordenacao;
    int finaliza_programa = 1;
    int total_treinos = 0;
    char nome_usuario [MAX];

    Corrida treino[MAX];

    cout << "Seja bem-vindo ao Sistema de Treinos de Corrida." << endl;
    cout << "Aqui, voce conseguira: " << endl << "Ordenar seus treinos por data, duracao, distancia ou pace." << endl; 
    cout << "Vamos comecar!" << endl;

    cout << "Voce deseja (Digite o numero): " << endl;

    finaliza_programa = menu_inicial (menu);

    switch (menu){
    case 1:
        cout << "Quantos treinos voce ira cadastrar? (Maximo 50)" << endl;
        cin >> quantidade_de_treinos;
        break;
    case 2:
        cout << "Ate mais!" << endl;
        return 0;
    }

    while ((quantidade_de_treinos < 1) || (quantidade_de_treinos > 50)){
        cout << "Quantidade fora dos limites, digite novamente." << endl;
        cin >> quantidade_de_treinos;
        cout << endl;
    }

    cout << "Qual o seu nome? ";
    cin.ignore();
    cin.getline(nome_usuario, MAX);


    ler_treinos (quantidade_de_treinos, treino, total_treinos);    

    cout << "Qual filtro voce deseja? (Digite o numero) " << endl;
        
    ler_filtro (criterio_ordenacao, filtro);

    switch (criterio_ordenacao){
        case 1:
            ordenar_por_data (treino, total_treinos, filtro);
            break;
        case 2:
            ordenar_por_pace(treino, total_treinos, filtro);
            break;
        case 3:
            ordenar_por_duracao (treino, total_treinos, filtro);
            break;
        case 4:
            ordenar_por_distancia (treino, total_treinos, filtro);
            break;
    }

    imprimir_ordenacao(treino, total_treinos, filtro, criterio_ordenacao, nome_usuario);

    do {
        cout << endl;
        cout << "Agora, voce deseja: " << endl;
        cout << "1 - Adicionar mais treinos" << endl;
        cout << "2 - Filtrar os treinos de forma diferente" << endl;
        cout << "3 - Finalizar o programa" << endl;
        cin >> escolha;

        while (escolha != 1 && escolha != 2 && escolha!=3){
            cout << "Essa opcao nao existe. Digite novamente: " << endl;
            cin >> escolha;
        }

    switch (escolha){
        case 1:
            cout << endl;
            cout << "Quantos treinos voce ira cadastrar? (Maximo 50)" << endl;
            cin >> quantidade_de_treinos;

            while (total_treinos + quantidade_de_treinos > MAX) {
                cout << "Quantidade excede o limite de 50 treinos." << endl;
                cout << "Voce ainda pode adicionar no maximo " << (MAX - total_treinos) << " treinos." << endl;
                cin >> quantidade_de_treinos;
            }

            ler_treinos (quantidade_de_treinos, treino, total_treinos);
            break;
        case 2:
            ler_filtro (criterio_ordenacao, filtro);

                switch (criterio_ordenacao){
                    case 1:
                        ordenar_por_data (treino, total_treinos, filtro);
                        break;
                    case 2:
                        ordenar_por_pace(treino, total_treinos, filtro);
                        break;
                    case 3:
                        ordenar_por_duracao (treino, total_treinos, filtro);
                        break;
                    case 4:
                        ordenar_por_distancia (treino, total_treinos, filtro);
                        break;
                }

                imprimir_ordenacao (treino, total_treinos, filtro, criterio_ordenacao, nome_usuario);

            break;
        case 3:
            cout << "Ate mais!" << endl;
            finaliza_programa = 0;
    }

    } while (finaliza_programa != 0);

    return 0;
}
