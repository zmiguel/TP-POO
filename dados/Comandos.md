# Comandos do utilizador

## Fase configuração
*Usados para definir o mundo*

- `defmundo <limite>` - Define a dimensão do mundo como uma grelha bidimensional de limite x limite posições, sendo obrigatoriamente limite >=10.
- `defen <energia>` - Define o valor inicial da energia dos ninhos.
- `defpc <valor>` - Define o valor (percentagem) da energia inicial a partir do qual o ninho faz uma formiga. Exemplo: 50 -> o ninho faz uma formiga nova a se tiver 50% de energia a mais do que o inicial.
- `defvt <valor>` - Define o número de unidades de energia transferidas entre ninho e formiga por iteração. O valor inicialmente estabelecido é 1 e pode ser modificado com este comando.
- `defmi <valor de 0 a 100>` - Define a percentagem inicial posições vazias que têm
(inicialmente) migalhas
- `defme <energia>` - Define a energia inicial das novas migalhas.
- `defnm <max>` - Define o número máximo de migalhas a serem criadas a cada instante. O número de migalhas novas é sorteado entre 0 e max.
- `executa <nomeFicheiro>` - Lê comandos do ficheiro de texto designado por nomeFicheiro, um por linha, e executa-os. Este comando pode ser utilizado para configurar o estado inicial da simulação, mas também para executar um conjunto gravado de comandos quando a simulação já está a decorrer. Cada linha do ficheiro tem um comando com a mesma estrutura dos comandos que se digitam através do teclado, e portanto sujeita à mesma interpretação e processamento.
- `inicio` – Se todos os parâmetros que é necessário configurar estiverem definidos, dá por encerrada a configuração e passa à simulação. Em caso contrário, mostra uma mensagem indicando que há parâmetros em falta, e mantém-se a fase de configuração.


## Fase de simulação

- `ninho <linha> < coluna>` - Coloca o ninho na posição (linha, coluna). Este comando cria implicitamente uma nova comunidade. Os ninhos são identificados por um número. O número é atribuído automaticamente pelo programa, sendo o primeiro o ninho 1, e os restantes 2,3, etc.
- `criaf <F> <T> <N>` - Cria e acrescenta F formigas do tipo T em posições aleatórias vazias. As formigas pertencem implicitamente ao ninho N (identificado por um valor inteiro). T indica o tipo das formigas: C – Cuidadora, V – Vigilante, A – Assaltante, E – Exploradora e S – Surpresa.
- `cria1 <T><N><linha>< coluna>` - Cria e acrescenta uma formiga do tipo T, do ninho N, na posição (linha, coluna). T indica o tipo das formigas: C – Cuidadora, V – Vigilante, A – Assaltante, E – Exploradora e S – Surpresa.
- `migalha <linha> < coluna>` - Cria uma migalha na posição (linha, coluna).
- `foca <linha, coluna>` - Nos casos em que não é possível a visualização total da grelha do mundo, pode representar-se apenas uma parte. Este comando define o centro da zona rectangular a ver no ecrã. A dimensão da zona é aquilo que fizer sentido relativamente ao ecrã em questão e à qualidade de visualização.
- `tempo` – Executa a passagem de uma iteração (unidade de tempo).
- `tempo <n>`  – Executa a passagem de n iterações (unidades de tempo).
- `energninho <N><E>` - Acrescenta um valor de energia E ao ninho N.
- `energformiga <linha> <coluna> <E>` - Acrescenta um valor de energia E à formiga que estiver na posição (linha, coluna).
- `mata <linha> <coluna>` - Mata a formiga que estiver na posição (linha, coluna).
- `inseticida <N>` - Elimina o ninho N e a sua comunidade.
- `listamundo` – Apresenta uma lista de todos os ninhos e de todas as migalhas com os seus atributos. Apenas é considerado o número de formigas da comunidade de cada ninho e não a sua listagem.
- `listaninho <N>` - Apresenta uma lista de toda a informação sobre o ninho, incluindo a lista das formigas da comunidade que lhe corresponde. Relativamente a cada formiga, deve ser apresentado o tipo, identificação, posição e energia. 
- `listaposicao <linha> <coluna>` - Apresenta os elementos que estão localizados na posição (linha, coluna) e seus atributos.
- `guarda <nome>` - Salvaguarda o mundo fazendo uma cópia integral dele em memória. O nome é aquilo que o utilizador quiser e serve para identificar posteriormente esta cópia. O nome “default” não pode ser usado neste comando.
- `muda <nome>` - Muda para uma cópia do mundo previamente guardada. Pode ser usado para voltar para a “versão original” que tem sempre automaticamente o nome “default”.
- `apaga <nome>` - Apaga uma cópia previamente guardada. Se se apagar o mundo “default”, a simulação é terminada. O programa não termina, fica de novo na fase de configuração.
- `sair` - Termina a execução do programa.




