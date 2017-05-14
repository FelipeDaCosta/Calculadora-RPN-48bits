 /*******************************************************************************************************
    UnB - Universidade de Brasília
    Software Básico - 2017/1
    Professor: Marcelo Ladeira
    Grupo 5: 
    	Felipe da Costa Malaquias 13/0044440
    	Paulo Victor Gonçalves Farias - 13/0144754
    	Ricardo Hideki Ito - 12/0045818

   	Tarefa: Máquina de Pilha e aritmética via software
 	-------------------------------------------------------------------------------------------------------
 
 	Objetivo: implementar um resolvedor de expressões 
 	aritméticas baseado em uma máquina de pilha, que receba 
 	uma equação por linha de comando ou dentro do programa, 
 	caso não tenham sido passados os parâmetros. 
 	A equação deve ser razoavelmente simples e utilizar apenas 
 	inteiros. Os parâmetros passados serão por notação infixa, 
 	com ou sem parênteses.

	 ------------------------------------------------------------------------------------------------------
	 Funcionamento do programa:
	 --------------------------
	 >> 1ª Etapa: Checa se o usuário passou uma expressão como parâmetro, se sim continua o programa. Caso
	 contrário vai pedir uma expressão que não exceda 64 caracteres.
	    
	 >> 2ª Etapa: Converte a expressão passada de notação infixa para notação polonesa reversa. Utiliza
	 o algoritmo de Shaunting Yard. Isso facilita para que o resolvedor possa fazer suas operações.

	 >> 3ª Etapa: Com a expressão em notação pósfixa é possível resolver a expressão e imprimir o resultado.
	 É importante notar que o overflow é checado.

    Conteúdo do arquivo: maqPilha_Grupo5.zip
      > main.c = programa principal
      > calculadora.c & calculadora.h = biblioteca c/ diversas funções implementadas do resolvedor de expressão
      > pilha.c & pilha.h = biblioteca c/ funções a respeito da pilha
      > relatorioImplementacao.pdf = relatório das atividades desenvolvidas
      > makefile = arquivo para facilitar na compilação

 --------------------------------------------------------------------------------------------------------
    Padrão: O programa, escrito em C, está em conformidade e usa bibliotecas disponíveis pelo C ISO.

    Entrada: Uma expressão pelo terminal ao chamar o programa ou passada posteriormente durante
    a execução do programa.
    
    Abordagem do problema: Foi utilizado o algoritmo de Shaunting Yard para conversão da expressão.
    A aritmética de 48 bits é usada como se fosse a de 64 bits, porém é detectado overflow e underflow se
    exceder 2^48. Também se faz a checagem de números negativos obtidos.

    Saída: 
      Expressão digitada.
      Expressão em notação polonesa reversa.
      Resultada da expressão convertida.

    Limitações: 
      

    Como compilar e executar:
    	No terminal: 
    > > > > >  make main
    > > > > >	./test "(Expressão)" ou ./test

    Foram feitos testes no sistema Linux Mint 17.3 (64 bits), kernel do linux 3.19.0-32, sendo que a versão entregue 
    compilou nos sistema sem warnings e foi executada como esperado.
**********************************************************************************************************************/ 