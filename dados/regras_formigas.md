# Regras das formigas

## Regras a implementar

**Foge**
- Caso exista uma formiga de outra comunidade no seu raio de visao
- Desloca-se no sentido contrario

**Persegue**
- Caso existam formigas de outras comunidades no seu raio de visao
- movimenta-se na direcção daquela que tiver mais energia

**Assalta**
- Caso existam formigas de outras comunidades em posições abrangidas pelo raio de movimento
- assalta/attaca a que tiver mais energia
- *um asalto coresponde a tranferir metade da energia da formiga assaltada para si*

**Protege**
- Caso exista uma formiga de outra comunidade e uma formiga da mesma no seu raio de visao
- move-se para uma posição intermedia entre estas duas formigas
- *para dificultar o comingo à inimiga*

**Procura Migalha**
- caso existam migalhas no seu raio de visao
- movimenta-se na direcção da que tiver mais energia

**Come Migalha**
- Caso existam migalhas na mesma posição ou adjacente
- escolhe a que tiver mais energia e retira-lhe uma parte *(a percentagem de energia retirada varia conforme o tipo de formiga)*

**Vai Para Ninho**
- Caso a formiga tenha um valor de energia superior à sua energia inicial ou inferior a metade da sua energia inicial, tenha o ninho no seu raio de visão e esteja fora do ninho há mais de 10 iterações
- desloca-se na sua direcção. Se o ninho já estiver no seu raio de movimento, entra no ninho.

**Passeia**
- Movimenta-se numa direcção aleatória dentro do seu raio de movimento, de forma incondicional.

## Formigas Especializadas

### Formiga cuidadora

- Visão: 5 uni
- Mov: 3 uni
- Energ: 100

#### Variação de energia
- obtem de migalhas
- se estiver fora do ninho perde 1+mov_efec por itera
- se voltar ao ninho, deposita ou recarrega a cada iteração

#### comportamento
- Perante o perigo de ser assaltada, foge.
- Se estiver ao pé de uma migalha, retira-lhe metade da energia.
- Procura activamente migalhas para ingerir e obter energia.
- Quando a formiga cuidadora tiver um valor de energia maior do que a energia inicial ou menor do que metade da energia inicial, tiver o ninho no seu raio de visão e estiver fora do ninho há mais de 10 iterações, dirige-se para o ninho.

#### Regras

- RegraFoge
- RegraComeMigalha
- RegraProcuraMigalha
- RegraVaiParaNinho
- RegraPasseia

### Formiga Vigilante

- visao: 7
- mov: 5
- ener: 150

#### Variação de energia
- obtem por migalhas
- perde 1+mov_efec por iteração

#### comportamento

- Perante o perigo de uma formiga da sua colónia ser assaltada, tenta dificultar a deslocação do inimigo. Se, no seu raio de visão, detectar uma formiga inimiga e uma formiga da sua população, move-se em direcção a uma posição entre a formiga da sua família e a inimiga.
- Se estiver ao pé de uma migalha, retira-lhe 75% da sua energia.
- Procura activamente migalhas para ingerir e obter energia. 

#### Regras

- RegraProtege
- RegraComeMigalha
- RegraProcuraMigalha
- RegraPasseia

### Formiga Assaltante

- visao: 8
- mov: 4
- ener: 80

#### Variação de energia

- obtem de migalhas e **outras formigas**
- perde 1+2xmov_efec por iteração

#### Comportamento

- Havendo uma formiga de outra comunidade numa posição adjacente, assalta-a.
- Se existirem formigas de outra comunidades no seu raio de visão, dirige-se à que tiver mais energia.
- Se estiver ao pé de uma migalha, retira-lhe 25% da sua energia.
- Procura activamente migalhas para ingerir e obter energia. 

#### Regras

- RegraAssalta
- RegraPersegue
- RegraComeMigalha
- RegraProcuraMigalha
- RegraPasseia.


### Formiga Exploradora

- visao: 10
- mov: 8
- ener: 200

#### Variação de energia

- obtem por migalhas
- perde 1+mov_efec por iteração

#### Comportamento

- Esta formiga passeia alegremente pelo mundo. Só quer explorar. Não se preocupa com inimigos, nem ninhos nem nada. Além de passear só tem a actividade de comer e isso apenas por que a natureza a isso a obriga: não procura comer, mas come migalhas (retirando-lhes toda a sua energia) se por acaso tropeçar nelas

#### Regras
- RegraComeMigalha
- RegraPasseia.

### Formiga Venenosa (surpresa)

- visao: 6
- mov: 3
- ener: 100

#### Variação de energia

- obtem por migalhas
- perde 1+mov_efect por itera
- perde 10 sempre que report veneno (repõe ate ter menos de 50% ener inicial)

#### Comportamento

- ao ser atacado o inimigo perde 25% da sua energia
- sempre que tiver mais de metade da sua energia inicial gasta 10 ener para repor o veneno
- veneno causa que quem está envenenado perca 2x mais energia ao movimentar-se

#### Regras

- RegraComeMigalha
- RegraVeneno (temos de fazer)
- RegraVaiParaNinho
- RegraPasseia
