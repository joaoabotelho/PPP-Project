# Project of PPP
## Objetivo
Implementar uma aplicação para gerir os exames do DEI.
## Competências
* Escrita de programas em C. Domínio do ambiente de desenvolvimento.
* Escrita de código corretamente formatado e indentado.
* Acesso a ficheiros.
* Definição de novos tipos de dados.
* Domínio de estruturas de dados dinâmicas.
* Utilização de listas ligadas.
* Utilização de soluções eficientes de ordenamento.
## Descrição do Problema
```
Imagine que o DEI está a planear desenvolver uma nova aplicação para a gestão de exames
e que a direção do departamento lhe pede para escrever esta aplicação. O objetivo é
permitir que os funcionários responsáveis pela organização dos exames possam inserir toda
a informação relevante para o exame: disciplina, época do exame, data, hora, duração, sala
em que terá lugar e lista de alunos inscritos.
Para além dos dados dos exames, a sua aplicação terá de armazenar dados de todos os
alunos e disciplinas.
Os alunos têm um número de aluno, curso, ano de matrícula no curso (1.º, 2.º, …), regime
(normal, trabalhador-estudante, atleta, dirigente associativo ou aluno de Erasmus).
Sobre as disciplinas deverá manter o nome da disciplina e o nome do docente responsável.
Não precisa de manter informação sobre as salas. Pode usar a sua designação, associada ao
exame, para verificar se há sobreposições na utilização das salas.
Os exames podem ser de três tipos: época normal, de recurso e época especial. Os exames
de época normal e recurso estão acessíveis a todos os alunos. Os exames de época especial
estão acessíveis apenas a alunos com estatutos de trabalhador-estudante, atletas,
dirigentes associativos ou alunos que frequentem o último ano do curso (corresponde ao 3º
ano de matrícula).

O seu programa deverá gerir todos os dados que compõem a aplicação e dar resposta
especificamente às seguintes operações:
```
* Criar, alterar e apagar dados dos alunos.
* Criar, alterar e apagar dados das disciplinas.
* Criar exames e configurar as salas, assegurando que não existe mais nenhuma
marcação para essas salas nesse horário.
* Apagar exames que já tenham sido realizados.
* Listar Exames – disciplina, época, bem como toda a restante informação relevante.
* Inscrever alunos, i.e., associar alunos ao exame, assegurando que têm acesso à época
do exame em causa. Deverá também permitir a remoção de inscrições.
* Listar alunos inscritos num exame.
* Listar exames em que um aluno está inscrito.
* Verificar se um dado exame tem salas reservadas que cheguem, com base no número
  de alunos inscritos e no número de lugares em cada sala (assuma que cada sala tem 30
  lugares).
```
Todos os dados da aplicação (exames, alunos e disciplinas) deverão ser guardados em
  ficheiros de texto, e carregados para as estruturas de dados adequadas no arranque do
  programa.
A interação com o utilizador deverá ser realizada através de uma consola em modo de texto
  para permitir a entrada de dados e a apresentação de resultados. Os resultados (ex.:
  listagens e pesquisas) deverão, também, poder ser armazenados em ficheiros de texto (a
  pedido do utilizador).
```
##  Implementação
```
  A aplicação deve ser implementada na linguagem C e deverá ser baseada em listas ligadas.
  Mais concretamente, deverá usar listas ligadas em memória para manter os dados dos
  exames e dos alunos. As relações entre estes deverão depois ser mantidas com novas listas
  ligadas de apontadores. Por exemplo, cada aluno deverá ter uma lista ligada de
  apontadores para os seus exames, enquanto que os exames deverão apontar também para
  os alunos. Algumas destas listas deverão ser ordenadas, por exemplo, a dos exames, de
  forma a permitir uma verificação rápida da ocupação das salas. Note que deverá ter o
  cuidado de manter estas listas num estado consistente, mesmo quando apagar dados do
  programa. Isto poderá obrigar o gestor a apagar primeiro as relações e só depois os
  exames ou os alunos, por exemplo.
  Utilize ficheiros para armazenar os dados sempre que sair da aplicação e para os recuperar,
  sempre que reentrar. Deve utilizar ficheiros de texto, para permitir a sua leitura quer por si,
  quer pelo seu professor.
```
