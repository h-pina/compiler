## Informações do projeto
 - **Nome:** Hugo Antunes Pina
 - **Data:** 25 de setembro de 2023


## Fazendo o Building do Lexer

O lexer já encontra-se compilado no arquivo ./Lexer. Entretanto, caso queira refazer a compilação, existem dois métodos diretos:
 1.  Utilizando o programa _make_, execute o comando **make**  na raiz do projeto, o executavel ./Lexer será criado.
 2. Execute a compilação diretamente
 ```shell
g++ -o Lexer main.cpp Token.cpp Lexer.cpp SymbolTable.cpp -I.
 ```

## Testando a aplicação

Para testar a aplicação, basta executar o código de testes por meio do comando
 ```shell
./Lexer
 ```
Por padrão, o arquivo lido é o **testfile.txt**. Sinta-se livre para modificar seu conteudo e fazer novos testes!
Caso deseje modificar o nome do arquivo testado, basta mudar a string _filename_ no arquivo **main.cpp**.

## Observações sobre a implementação
 
 Cada um dos arquivos criados durante a implementação do Lexer possui um header (.h) e um arquivo .cpp. De modo geral, comentários relacionados ao propósito lógico de cada função ou váriavel estão localizados nos headers, enquanto detalhes de implementação estão localizados nos arquivos cpp
