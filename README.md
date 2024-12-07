# Circuito-RC
Projeto de aquisição de dados de parâmetros da dinâmica de um circuito RC para apresentar da matéria Controle de Sistemas Dinâmicos no curso de Engenharia Mecânica da UFTM
Foi analisada a resposta da tensão no capacitor quando submetida a uma tensão de entrada de 5V.

# Scripts
Foram escritos 5 códigos no total:Um código no Octave para simular a respostar do capacitor, um em C++ para controle do arduino e dois em python. O 'circuito_RC_adquire.py' para ler os dados medidos pelo arduino e salvá-los em .csv.
O 'circuito_RC_plot.py' para plotar o gráfico de resposta'.
O 'circuito_RC_carga_e_descarga.ino' para controle do Arduino Mega 2650
O 'circuito_RC.m' foi em Octave para simular a resposta do sistema e plotar um diagrama
