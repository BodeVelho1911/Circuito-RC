import pandas as pd
import matplotlib.pyplot as plt

# Nome do arquivo CSV gerado
arquivo_csv = "dados_capacitor_dois_ciclos.csv"

# Carrega os dados do arquivo CSV
dados = pd.read_csv(arquivo_csv)

# Inicializa listas para armazenar os dados contínuos
tempo = []
tensao = []

# Variável para controle do tempo contínuo
tempo_total = 0

# Processa os dados para criar um sinal contínuo
for i, linha in dados.iterrows():
    tensao.append(linha["tensao(V)"])  # Adiciona a tensão à lista
    tempo.append(tempo_total)         # Adiciona o tempo incremental à lista
    tempo_total += 50  # Incremento de 50 ms entre cada leitura

# Plota o gráfico contínuo
plt.figure(figsize=(10, 6))
plt.plot(tempo, tensao, label="Carga e Descarga do Capacitor", color="blue")
plt.title("Gráfico de Carga e Descarga do Capacitor")
plt.xlabel("Tempo (ms)")
plt.ylabel("Tensão (V)")
plt.legend()
plt.grid()
plt.show()
