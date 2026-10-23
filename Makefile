CC = mpicc
CFLAGS = -Wall -Iinclude
SRC = src/main.c src/stats.c
TARGET = media_mpi

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	mpirun -np 4 ./$(TARGET) 1000

clean:
	rm -f $(TARGET)

.PHONY: run clean
