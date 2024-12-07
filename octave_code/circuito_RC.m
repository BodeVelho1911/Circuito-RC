% Definindo os parâmetros do circuito
R = 1000;          % Resistência em Ohms (1kΩ)
C = 1000e-6;       % Capacitância em Farads (1000µF)
V0 = 5;            % Amplitude do degrau em Volts

% Definindo o vetor de tempo
t = 0:0.01:5;      % Tempo de 0 a 5 segundos, com intervalos de 0.01s

% Calculando a resposta do capacitor
Ec = V0 * (1 - exp(-t/(R*C)));

% Plotando a resposta
plot(t, Ec, 'b', 'LineWidth', 2);      % Plot em azul com linha mais grossa
xlabel('Tempo [s]');                   % Rótulo do eixo x
ylabel('DDP no Capacitor [V]');       % Rótulo do eixo y
title('Resposta do Circuito RC ao Degrau Unitário de 5V'); % Título do gráfico
grid on;                               % Ativa a grade no gráfico

