# Переменные для компилятора и флагов
CC = gcc
CFLAGS = -Wall -g

# Имена исходных файлов
SRC = main.c functions.c functions.h

# Имя исполнимого файла
TARGET = program

# Правило по умолчанию для сборки
all: $(TARGET)

# Правило для сборки исполнимого файла
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Правило для очистки сгенерированных файлов
clean:
	rm -f $(TARGET)
