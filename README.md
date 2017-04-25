# Project of PPP
##Objetivo
Implementar uma aplicação para gerir os exames do DEI.
##Competências
```
1. Escrita de programas em C. Domínio do ambiente de desenvolvimento.
2. Escrita de código corretamente formatado e indentado.
3. Acesso a ficheiros.
4. Definição de novos tipos de dados.
5. Domínio de estruturas de dados dinâmicas.
6. Utilização de listas ligadas.
7. Utilização de soluções eficientes de ordenamento.
```
Descrição do Problema
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
1. Criar, alterar e apagar dados dos alunos.
2. Criar, alterar e apagar dados das disciplinas.
3. Criar exames e configurar as salas, assegurando que não existe mais nenhuma
marcação para essas salas nesse horário.
4. Apagar exames que já tenham sido realizados.
5. Listar Exames – disciplina, época, bem como toda a restante informação relevante.
6. Inscrever alunos, i.e., associar alunos ao exame, assegurando que têm acesso à época
do exame em causa. Deverá também permitir a remoção de inscrições.
  7. Listar alunos inscritos num exame.
  8. Listar exames em que um aluno está inscrito.
  9. Verificar se um dado exame tem salas reservadas que cheguem, com base no número
  de alunos inscritos e no número de lugares em cada sala (assuma que cada sala tem 30
  lugares).
  Todos os dados da aplicação (exames, alunos e disciplinas) deverão ser guardados em
  ficheiros de texto, e carregados para as estruturas de dados adequadas no arranque do
  programa.
  A interação com o utilizador deverá ser realizada através de uma consola em modo de texto
  para permitir a entrada de dados e a apresentação de resultados. Os resultados (ex.:
  listagens e pesquisas) deverão, também, poder ser armazenados em ficheiros de texto (a
  pedido do utilizador).
  Implementação
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
  É importante que compreenda que a implementação que vai fazer desta aplicação tem um
  objetivo pedagógico de o introduzir na linguagem C e de lhe permitir o domínio da
  programação com apontadores. Uma aplicação real faria sempre recurso de outras
  tecnologias, como bases de dados e de outras estruturas de dados que terá oportunidade
  de conhecer noutras disciplinas mais avançadas do curso.
  Composição dos grupos
  O trabalho deverá ser realizado por grupos de 2 elementos pertencentes a turmas do
  mesmo Professor.
  Material a entregar
  Cada grupo deve entregar obrigatoriamente:
  1. Upload de zipFile no InforEstudante com:
  • Todo o código fonte (.c e .h).
  • Ficheiros de dados para teste.
  • Relatório (em formato pdf).
  2. O relatório deve incluir os seguintes aspetos:
  • Esquema com as estruturas de dados utilizadas.
  • Estrutura geral do programa.
  • Estrutura dos ficheiros de texto (que dados são armazenados e cada ficheiro e
  como).
  • Breve explicação de como o programa se executa.
  Defesa final do trabalho
  O trabalho deverá ser defendido através de uma prova oral com todos os elementos do
  grupo. Os estudantes que não comparecerem à defesa do trabalho terão a classificação de
  zero valores no projeto.
  A nota do projeto será atribuída em função da avaliação do trabalho entregue e da sua
  defesa.
  Apesar do trabalho ser essencialmente um trabalho de grupo as notas são individuais,
  podendo ser atribuídas notas diferentes a cada elemento do grupo, sempre que tal se
  justifique.
  As defesas decorrerão após a entrega dos trabalhos, em data a anunciar. Será colocado no
  inforestudante um mapa de defesas onde os grupos se devem inscrever. 
