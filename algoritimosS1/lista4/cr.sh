#!/data/data/com.termux/files/usr/bin/bash

#!/bin/bash

# Solicitar o nome do arquivo fonte ao usuário
read -p "Digite o nome do arquivo fonte: " SOURCE_FILE

# Verificar se o arquivo fonte existe
if [ ! -f "$SOURCE_FILE" ]; then
  echo "Erro: O arquivo fonte $SOURCE_FILE não foi encontrado!"
fi

# Extrair o nome base do arquivo (sem extensão)
BASE_NAME="${SOURCE_FILE%.c}"

# Nome do arquivo binário
OUTPUT_FILE="$BASE_NAME"

# Compilar o código fonte
echo "Compilando $SOURCE_FILE..."
gcc "$SOURCE_FILE" -o "$OUTPUT_FILE"

# Verificar se a compilação foi bem-sucedida
if [ $? -ne 0 ]; then
  echo "Erro: A compilação falhou!"
fi

# Executar o programa compilado
echo "Executando $OUTPUT_FILE..."
./"$OUTPUT_FILE"
