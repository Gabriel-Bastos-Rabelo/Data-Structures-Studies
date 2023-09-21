#define FALSE 0
#define TRUE 1
typedef struct cofo Cofo;
typedef struct time Time;

/* Cria um novo TAD Cofo
Pre-condicao: maxItems > 0
Pos-condicao: retorna o endereço de um novo TAD Cofo
(Inteiros) vazio ou NULL se não conseguir criar*/
Cofo *cofCreate(int maxItems);

/* Adiciona um item no Cofo
Pre-condicao : (c é um TAD Cofo criado por uma chamada a
cofCreate) e (o TAD Cofo nao esta cheio)
Pos-condicao: item foi adicionado ao TAD cofo/*/
int cofInsert(Cofo *c, Time *t);

/* Retira um item da colecao
Pre-condicao: (c é um TAD Cofo criado por uma chamada a
cofCreate) e && (existe pelo menos um item no TAD Cofo)
Pos-condicao: item foi eliminado do TAD cofo */
int cofRemove(Cofo *c, int item);

/* Encontra um item em um TAD Cofo
Pre-condicao: (c é um TAD Cofo criado por uma chamada a cofCreate)
Pos-condicao: retorna TRUE se o item identificado por key ele existir no TAD cofo, ou FALSE caso contrátrio
*/
int cofQuery(Cofo *c, int key);

/* Destroi um TAD Cofo
Pre-condicao: (c é um TAD Cofo criado por uma chamada a cofCreate e que está vazia)
Pos-condicao: a memoria usada pelo TAD foi liberada
*/
int cofDestroy(Cofo *c);

Time *createTime(const char *nome, int partidas, int vitorias, int derrotas);