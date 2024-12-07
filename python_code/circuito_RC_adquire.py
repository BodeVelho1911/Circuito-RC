import serial
import csv

# Configurações da porta serial
porta = "COM10"  # Substitua pela sua porta
baud_rate = 9600
ser = serial.Serial(porta, baud_rate)

# Nome do arquivo CSV
arquivo_csv = "dados_capacitor_dois_ciclos.csv"

# Inicializa as listas para contagem de ciclos
ciclos = 0

# Abre o arquivo CSV para salvar os dados
with open(arquivo_csv, mode="w", newline="") as arquivo:
    writer = csv.writer(arquivo)
    writer.writerow(["tempo(ms)", "tensao(V)", "estado"])  # Cabeçalho do arquivo CSV

    print("Capturando dados do Arduino...")

    try:
        while ciclos < 2:  # Captura apenas dois ciclos
            # Lê uma linha da porta serial
            linha = ser.readline().decode().strip()

            if linha.startswith("tempo"):  # Ignora o cabeçalho inicial
                continue

            if "Carregando" in linha or "Descarregando" in linha:
                partes = linha.split(",")
                tempo = int(partes[0])
                tensao = float(partes[1])
                estado = partes[2].strip()

                # Salva os dados no arquivo CSV
                writer.writerow([tempo, tensao, estado])

                # Conta os ciclos de carga e descarga
                if estado == "Descarregando" and tensao <= 0.1:
                    ciclos += 1

    except KeyboardInterrupt:
        print("\nCaptura interrompida pelo usuário.")
    finally:
        ser.close()

print(f"Dados salvos no arquivo: {arquivo_csv}")
