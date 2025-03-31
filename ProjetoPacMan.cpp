#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

    typedef struct {
        int x, y;
    } Posicao;

//declarando as funções ; no final, depois quando chamar a função abre e fecha {}
    void exibirTelaInicial();
    void exibirTelaFinal();
    void exibirTelaBomba();
    void exibirTelaInimigo();
    void exibirGameOver();
    void desenharLabirinto(char labirinto[24][32], Posicao jogador, Posicao inimigo, int tamanho_celula, int moedas);
    void moverInimigo(Posicao *inimigo, Posicao jogador, char labirinto[24][32]);//talvez mudar o inimigo pra um possível player 2?
    void moverBombas(char labirinto[24][32]);
    void gerarBombas(char labirinto[24][32]);
    void gerarMoedas(char labirinto[24][32]);
    void regerarMoedas(char labirinto[24][32]);
    void regerarBombas(char labirinto[24][32]);


int main() {
    int largura_tela = 800;
    int altura_tela = 600;
    initwindow(largura_tela, altura_tela, "Labirinto");

    char labirinto[24][32] = {//24 linhas  32 colunas

        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'},
        {'#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', ' ', ' ', 'S', 'S', 'S', 'S', ' ', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', 'S', 'S', 'S', 'S', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', ' ', 'S', 'S', 'S', 'S', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', '#', '#', ' ', '#', ' ', '#', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };
    Posicao jogador = {1, 1};
    Posicao inimigo = {8, 1};
    int tamanho_celula = largura_tela / 32;
    int moedas = 0; //define o valor inicial das moedas como 0
    int tempo_na_safe = 0; //define o valor inicial da safe zone como 0


    exibirTelaInicial(); //chama a função de mostrar a tela inicial
    gerarBombas(labirinto); //chama a função e gera as bombas
    gerarMoedas(labirinto); //chama a função e gera as moedas


    //-----------------------------------------------------------------
    char entrada;
    do { //loop principal - labirinto
        desenharLabirinto(labirinto, jogador, inimigo, tamanho_celula, moedas); //desenha o labirinto
        entrada = getch(); //ta recebendo a tecla que o jogo precionou

        Posicao nova_posicao = jogador;
        if (entrada == 'w') nova_posicao.x--; //cima
        if (entrada == 's') nova_posicao.x++; //baixo
        if (entrada == 'a') nova_posicao.y--; //esquerda
        if (entrada == 'd') nova_posicao.y++; //direita

        if (labirinto[nova_posicao.x][nova_posicao.y] != '#') jogador = nova_posicao; //verifica aí se o jogador vai pro ' ', se for atualiza a posição

        if (labirinto[jogador.x][jogador.y] == 'M') {  //se o player coletar uma moeda
            moedas++; //adiciona as moedas ao contador
            labirinto[jogador.x][jogador.y] = ' ';  //remove a moeda após coletada
            regerarMoedas(labirinto);//chama a função e da spawn numa nova moeda
        }

        if (labirinto[jogador.x][jogador.y] == 'B') { //se o player for explodido tire moedas
            moedas--;//remove 1 moeda do contador
            labirinto[jogador.x][jogador.y] = ' '; //tira a moeda e "declara" o local como vazio, ou seja troca o 'B' por ' '
            regerarBombas(labirinto);//da spwan numa nova bomba

            if (moedas < 0) { //se o player for explodido e ele não tiver moedas mostre game over
                cleardevice(); //limpa a tela
                exibirTelaBomba();//chama a função
                getch();
                break;//interromper a execução
            }
        }

        int dx = jogador.x - inimigo.x; //dx é pra verificar a diferença x entre o jogador e o inimigo, tipo se o player ta na direita o dx é positivo
        int dy = jogador.y - inimigo.y; //msm coisa só que se for positivo é pro player ta abaixo do npc
        Posicao novo_inimigo = inimigo;
        if (abs(dx) > abs(dy)) novo_inimigo.x += (dx > 0 ? 1 : -1);//movimento do npc inimigo (futuramente fazer uma "cadeia" de if pra melhorar a movimentação)
        else novo_inimigo.y += (dy > 0 ? 1 : -1); //movimento do npc inimigo
        if (labirinto[novo_inimigo.x][novo_inimigo.y] != '#' && labirinto[novo_inimigo.x][novo_inimigo.y] != 'S') inimigo = novo_inimigo;

        if (jogador.x == inimigo.x && jogador.y == inimigo.y) { //se o player for pego mostre a tela de game over
            cleardevice(); //limpa a tela
            exibirTelaInimigo();//chama a função
            getch();
            break;//interromper a execução
        }
        if (labirinto[jogador.x][jogador.y] == 'S') { //era pra calcular o tempo na zona segura, mas mudamos pra calcular o movimento
            tempo_na_safe++; //tempo na safe, virou movimentos na zona segura
                if (tempo_na_safe % 3 == 0) { //a cada 3 movimentos retira moedas do player //tava com erro, arrumamps trocando os 5 segundos e pra 5 movimentos
                moedas--;
                    if (moedas < 0) { //se as moedas ficarem negativas com o player se movimentando dentro da safe zone mostre a tela de game over
                        cleardevice(); //limpa a tela
                        exibirGameOver();//chama a função
                        getch();
                        break; //interromper a execução
                    }
                }
            } else {
                tempo_na_safe = 0; //zera o valor atual da safe zone quando o player sai da zona
            }

//---------------------condição de vitoria---------------------
        if (moedas >= 10 && labirinto[jogador.x][jogador.y] == 'S') { //se o jogador tiver 10 ou mais moedas e for na zona segura ele ganha
            cleardevice();
            readimagefile("gamewin.jpg", 0, 0, 800, 600);
            getch();
            break;//interromper a execução
        }

    } while (entrada != 27); //tecla esc e usando ESC fecha o jogo
    exibirTelaFinal();
    getch();
    closegraph();
    return 0;
    } //fim do main
    //-----------------------------------------------------------------

    //faça as funções depois do main
    void exibirTelaInicial() {//tela inicial
    cleardevice();
    while (!kbhit()) { //cria um efeito de "piscar" o texto
        readimagefile("fundotela1.jpg", 0, 0, 800, 600);
        delay(200);
        readimagefile("fundotela2.jpg", 0, 0, 800, 600);
        delay(200);
        }
    }

    //tela do obrigada por jogar
    void exibirTelaFinal(){
        cleardevice();
        readimagefile("telafinal.jpg", 0, 0, 800, 600);
        }

    void exibirTelaBomba() {//tela de gameover bomba
    cleardevice();
    while (!kbhit()) { //cria um efeito de "piscar" o texto
        readimagefile("bomba.jpg", 0, 0, 800, 600);
        delay(200);
        readimagefile("bomba2.jpg", 0, 0, 800, 600);
        delay(200);
        }
    }

        void exibirTelaInimigo() { //tela de gameover inimigo
        cleardevice();
        while (!kbhit()) { //cria um efeito de "piscar" o texto
        readimagefile("inimigo1.jpg", 0, 0, 800, 600);
        delay(300);
        readimagefile("inimigo2.jpg", 0, 0, 800, 600);
        delay(300);
        }
    }

        void exibirGameOver() { //tela de gameover da zona segura
        cleardevice();
        while (!kbhit()) { //cria um efeito de "piscar" o texto
        readimagefile("gameover.jpg", 0, 0, 800, 600);
        delay(300);
        readimagefile("gameover2.jpg", 0, 0, 800, 600);
        delay(300);
        }

    }

    void desenharLabirinto(char labirinto[24][32], Posicao jogador, Posicao inimigo, int tamanho_celula, int moedas) {
    cleardevice(); //limpa a tela
    setfillstyle(SOLID_FILL, BLACK); //cor do fundo
    bar(0, 0, getmaxx(), getmaxy()); //colore o fundo todo

    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 32; j++) {
            int x = j * tamanho_celula;
            int y = i * tamanho_celula;

            if (labirinto[i][j] == '#') {//parede
                setfillstyle(SOLID_FILL, BLACK); //colore de preto
                bar(x, y, x + tamanho_celula, y + tamanho_celula); //pega as cordenadas e desenha um "quadrado"
            }else if (labirinto[i][j] == 'S') {//safe zone
                setfillstyle(SOLID_FILL, COLOR(0, 70, 0)); ////cor da zona safe é um ver escuro, mas darkgreen não "existe" dentro da graphics.h
                bar(x, y, x + tamanho_celula, y + tamanho_celula);
            } else if (labirinto[i][j] == 'B') {//bombas
                setfillstyle(SOLID_FILL, BLUE);
                bar(x, y, x + tamanho_celula, y + tamanho_celula);
            } else if (labirinto[i][j] == 'M') {//moedas
                setfillstyle(SOLID_FILL, YELLOW);
                bar(x, y, x + tamanho_celula, y + tamanho_celula);
            } else {//caminhos
                setfillstyle(SOLID_FILL, WHITE);
                bar(x, y, x + tamanho_celula, y + tamanho_celula);
            }
        }
    }



    //player
    setfillstyle(SOLID_FILL, GREEN); // desenha o quadrado do vermelho
    bar(jogador.y * tamanho_celula, jogador.x * tamanho_celula, (jogador.y + 1) * tamanho_celula, (jogador.x + 1) * tamanho_celula);
    //era pra desenhar o jogador, mas nao fuciona
    //readimagefile("player.jpg",10,10,173,291); // a imagem é pequena demais pra funcionar


    //inimigo (futuramente talvez fazer um player 2 e não inimigo?)
    setfillstyle(SOLID_FILL, RED);
    bar(inimigo.y * tamanho_celula, inimigo.x * tamanho_celula, (inimigo.y + 1) * tamanho_celula, (inimigo.x + 1) * tamanho_celula);
    //readimagefile("player.png" jogador.y * tamanho_celula, jogador.x * tamanho_celula, (jogador.y + 1) * tamanho_celula, (jogador.x + 1) * tamanho_celula )// testes

    //exibe o número de moedas
    char moedasTexto[20];
    sprintf(moedasTexto, "Moedas:%d", moedas);
    setcolor(WHITE); //cor
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2); //fonte
    outtextxy(10, 9, moedasTexto); //local onde é pra aparecer o texto

//-------------------- fazer a parte de texto para o objetivo do game----------

    //sprintf(moedasTexto, "*colete 15 moedas 1/%d", moedas);
    //outtextxy(490, 600, moedasTexto);
    //delay(100);

      // for (int i = 0; i < 100; i++) { // se eu deixo esse for não vai dar pra se mover KKKKKKKKK
        setcolor(WHITE);
        outtextxy(210, 9, "Colete 10 moedas e alcance a zona segura");
        delay(300);
      // setcolor(YELLOW); //"troca" a cor do texto
      // outtextxy(210, 9, "Colete 15 moedas e alcance a zona segura");
      // delay(300);
      // }
    }


    void gerarBombas(char labirinto[24][32]){ //bombas
    int numero_bombas = 5; //número de bombas geradas
    srand(time(NULL));//gerador de números aleatórios

    for (int i = 0; i < numero_bombas; i++) {
        int x, y;
        do {
            x = rand() % 24;
            y = rand() % 32;
        } while (labirinto[x][y] != ' ');

        labirinto[x][y] = 'B';

    }
    }

    void regerarBombas(char labirinto[24][32]){ //bombas
    int numero_bombas = 2; //número de bombas geradas
    srand(time(NULL));//gerador de números aleatórios

    for (int i = 0; i < numero_bombas; i++) {
        int x, y;
        do {
            x = rand() % 24;
            y = rand() % 32;
        } while (labirinto[x][y] != ' ');

        labirinto[x][y] = 'B';

    }
    }


    void gerarMoedas(char labirinto[24][32]) { //moedas
    int numero_moedas = 5; //número de moedas que dá spwan
    srand(time(NULL));//gerador de números aleatórios

    for (int i = 0; i < numero_moedas; i++) {
        int x, y;
        do {
            x = rand() % 24;
            y = rand() % 32;
        } while (labirinto[x][y] != ' ' || labirinto[x][y] == 'B' || labirinto[x][y] == '#' || labirinto[x][y] == 'S');

        labirinto[x][y] = 'M';
        }
    }

    void regerarMoedas(char labirinto[24][32]) { //cada vez que pegar uma moeda é pra dar spwan numa nova moeda
    int numero_moedas = 1; //número de moedas que dá spwan
    srand(time(NULL));//gerador de números aleatórios

    for (int i = 0; i < numero_moedas; i++) {
        int x, y;
        do {//local que a moeda pode ser colocada aleatoriamente no labirinto
            x = rand() % 24;
            y = rand() % 32;
        } while (labirinto[x][y] != ' ' || labirinto[x][y] == 'B' || labirinto[x][y] == '#' || labirinto[x][y] == 'S'); //falando onde as moedas nao podem dar spwan

        labirinto[x][y] = 'M';
        }
    }




//coisas pra fazer futuramente(se não der tempo, fazer nas férias):
//adicionar uma opção de player 1 e player 2
//arrumar o inimigo ou tirar o inimigo
//tentar achar uma forma de deixar de "piscar" a tela toda vez que o labirinto é redesenhado, talvez fazer um labirinto no photoshop e jogar no fundo como imagem???
//arrumar que ta dando interferência nas teclas, tipo quando qualquer tecla é precionada o labirinto conta como 1 movimento e ai o inimigo se move
//arrumar q a tela de "obrigado por jogar" só deveria aparecer 1x e não toda vez que da game over, tipo quero que se de game over ainda de pra voltar e tentar de novo, até que o player preciona esc
//fazer uma forma de quanto mais moeda se tem mais bombas aparecem
//e procurar outras formar de deixar mais divertido
