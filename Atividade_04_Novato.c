#include <stdio.h> // inclui as bibliotecas de entrada e saída para interagir com os terminais, printf e scanf.

// Função para inicializar o tabuleiro com zeros (representando a água).
void inicializarTabuleiro(int tabuleiro[10][10])
{
    // Loop externo para percorrer as linhas.
    for (int i = 0; i < 10; i++)
    {
        // Loop interno para percorrer as colunas.
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0; // Define cada posição como água (0).
        }
    }
}

// Função para validar se o navio pode ser posicionado sem ultrapassar limites ou ficar em cima de outro navio.
int validarPosicao(int tabuleiro[10][10], int linha, int coluna, int tamanho, int horizontal)
{
    // Verifica se o navio está na horizontal.
    if (horizontal)
    {
        // Verifica se o navio cabe horizontalmente no tabuleiro (coluna inicial + tamanho <= 10).
        if (coluna + tamanho > 10)
        {
            return 0; // Retorna 0 se ultrapassar o limite.
        }
        // Verifica se há sobreposição com outro navio.
        for (int j = coluna; j < coluna + tamanho; j++)
        {
            if (tabuleiro[linha][j] != 0)
            {
                return 0; // Retorna 0 se encontrar uma posição ocupada.
            }
        }
    }
    // Caso o navio seja vertical.
    else
    {
        // Verifica se o navio cabe verticalmente no tabuleiro (linha inicial + tamanho <= 10).
        if (linha + tamanho > 10)
        {
            return 0; // Retorna 0 se ultrapassar o limite.
        }
        // Verifica se há sobreposição com outro navio.
        for (int i = linha; i < linha + tamanho; i++)
        {
            if (tabuleiro[i][coluna] != 0)
            {
                return 0; // Retorna 0 se encontrar uma posição ocupada.
            }
        }
    }
    return 1; // Retorna 1 se a posição for válida.
}

// Função para posicionar o navio no tabuleiro.
void posicionarNavio(int tabuleiro[10][10], int linha, int coluna, int tamanho, int horizontal)
{
    // Se o navio é horizontal.
    if (horizontal)
    {
        // Preenche as posições horizontais com o valor 3 (representa o navio).
        for (int j = coluna; j < coluna + tamanho; j++)
        {
            tabuleiro[linha][j] = 3;
        }
    }
    // Se o navio é vertical.
    else
    {
        // Preenche as posições verticais com o valor 3.
        for (int i = linha; i < linha + tamanho; i++)
        {
            tabuleiro[i][coluna] = 3;
        }
    }
}

// Função para exibir o tabuleiro no console de forma organizada.
void exibirTabuleiro(int tabuleiro[10][10])
{
    // Imprime o título do tabuleiro.
    printf("\nTabuleiro de Batalha Naval - Nv Iniciante: (10x10):\n");
    printf("\n"); // Adiciona uma linha em branco para separar o código e deixar mais organizado.

    // Imprime os números das colunas (0 a 9) com um espaço inicial para alinhamento.
    printf("  "); // Adiciona um espaço do lado esquerdo do taboleiro para organizar as matreizes.
    for (int j = 0; j < 10; j++)
    {
        printf("%d ", j);
    }
    printf("\n");

    // Loop para percorrer e exibir cada linha do tabuleiro.
    for (int i = 0; i < 10; i++)
    {
        // Imprime o número da linha atual.
        printf("%d ", i);
        // Loop para exibir os valores de cada coluna na linha atual.
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]); // Exibe 0 (água) ou 3 (navio).
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro.
    }
}

int main()
{
    // Declara o tabuleiro como uma matriz 10x10.
    int tabuleiro[10][10];

    // Define o tamanho fixo dos navios (3 posições).
    int tamanhoNavio = 3;

    // Define as coordenadas iniciais do navio horizontal.
    int linhaNavioHorizontal = 4;  // Linha fixa para o navio horizontal.
    int colunaNavioHorizontal = 2; // Coluna inicial para o navio horizontal.

    // Define as coordenadas iniciais do navio vertical.
    int linhaNavioVertical = 1;  // Linha inicial para o navio vertical.
    int colunaNavioVertical = 6; // Coluna fixa para o navio vertical.

    // Inicializa o tabuleiro com zeros (a água).
    inicializarTabuleiro(tabuleiro);

    // Valida e posiciona o navio horizontal.
    if (validarPosicao(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, tamanhoNavio, 1))
    {
        posicionarNavio(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, tamanhoNavio, 1);
    }
    else
    {
        printf("Erro!: Não foi possível posicionar o navio horizontal em (%d, %d).\n",
               linhaNavioHorizontal, colunaNavioHorizontal);
        return 1; // Encerra o programa com erro.
    }

    // Valida e posiciona o navio vertical.
    if (validarPosicao(tabuleiro, linhaNavioVertical, colunaNavioVertical, tamanhoNavio, 0))
    {
        posicionarNavio(tabuleiro, linhaNavioVertical, colunaNavioVertical, tamanhoNavio, 0);
    }
    else
    {
        printf("Erro: Não foi possível posicionar o navio vertical em (%d, %d) ou há sobreposição.\n",
               linhaNavioVertical, colunaNavioVertical);
        return 1; // Encerra o programa com erro.
    }

    // Exibe o tabuleiro com os navios posicionados.
    exibirTabuleiro(tabuleiro);

    return 0; // Finaliza retornando o programa com sucesso.
}
