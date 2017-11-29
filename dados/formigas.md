# Formigas
- Pertencem a uma comunidade
- Sao identificadas por um numero gerado automaticamente
- a primeira formiga tem o numero 1
- um ninho pode ter varias formigas na sua posição
- no mundo so pode existir uma formiga em cada espaço
- uma formiga pode esar na mesma casa de uma migalha
- Cada formiga tem uma lista de caracteristicas e comportamento definidos quando a formiga é criada
- 

## energia
- sao criadas com energia inicial (dependendo as suas caracteristicas)
#Varia de acordo com:
- se nao estiver no ninho perde, pelo menos, 1 energia por iteração
- se estiver no ninho, perde ou ganha energia tendo em conta a sua vida actual
- Obtem energia quando come migalhas
- se o nivel de energia for 0 ou menos a formiga morre e desaparece

## visao

`max( abs(x – x1), abs(y – y1) ) <= raio de visão`
(x,y) posição actual
(x1,y1) celula a pesquisar

- o seu comportamento depende do que vêm a sua volta.

## movimento
- raio de movimento é sempre igual ou INFERIOR ao raio de visao

`max( abs(x – x1), abs(y – y1) ) <= raio de movimento`
(x,y) posição actual
(x1,y1) celula para onde quer ir

- em cada iteração pode se mover o maximo do raio de movimento (horiz + vert), nao se pode mover directamente na diagonal.

## comportamento
- existe apena um tipo de formiga
- cada formiga age de uma forma diferente tendo em conta o seu conjunto de regras
- quando estao no ninho comportam-se todas iguais (dando ou retirando energia)
- cada regra determina uma acção que a formiga executa
existem conjuntos de regras diferente que definem o comportamento de um comjunto de formigas
